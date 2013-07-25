# Copyright (c) Jakky89 2013.
#
# This file is part of cuwo.
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

import sys
import os.path
import sqlite3 as sql_db

from twisted.internet import reactor
from cuwo import common
from cuwo import constants


def get_connection():
    try:
        db_con = sql_db.connect(constants.DATABASE_NAME)
        if db_con:
            print '[DATABASE] Connected to database using SQLite %s' % sql_db.sqlite_version
            try:
                db_cur = db_con.cursor()
                db_cur.executescript("""
                    PRAGMA encoding = "UTF-8";
                    PRAGMA locking_mode = EXCLUSIVE;
                    PRAGMA synchronous = OFF;
                    PRAGMA temp_store = MEMORY;
                """)
                db_con.commit()
            except sql_db.Error, e:
                print '[DATABASE ERROR] Could not set database PRAGMA: %s' % e.args[0]
            except:
                print '[DATABASE ERROR] Could not set database PRAGMA!'
            return db_con
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not connect to database: %s' % e.args[0]
    except Exception, e:
        print '[DATABASE ERROR] Could not connect to database: %s' % e
    sys.exit(1)
    return None


def close_connection(db_con):
    if not db_con:
        return
    try:
        db_con.close()
    except:
        pass


def create_structure(db_con=None):
    try:
        if os.path.isfile(constants.DATABASE_NAME):
            return
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.executescript("""
            CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY AUTOINCREMENT, ingame_name VARCHAR(100) NOT NULL, password_hash TINYBLOB, last_ip VARCHAR(100) DEFAULT NULL, last_online UNSIGNED BIG INT DEFAULT NULL, online_seconds UNSIGNED BIG INT DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS player_permissions(player_id INTEGER, permission_type TINYINT(2), permission_node VARCHAR(100) NOT NULL);
            CREATE TABLE IF NOT EXISTS player_bans(player_id INTEGER, ip_address VARCHAR(100) NOT NULL UNIQUE, banned_by INTEGER DEFAULT NULL, banned_since UNSIGNED BIG INT NOT NULL, banned_until UNSIGNED BIG INT DEFAULT NULL, reason TEXT DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS player_inventories(player_id INTEGER, slot_index INTEGER, item_type INTEGER, item_subtype INTEGER DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS kv_data(data_key VARCHAR(64) PRIMARY KEY, data_value BLOB DEFAULT NULL);
            CREATE VIRTUAL TABLE regions_3d USING rtree(id, min_x, max_x, min_y, max_y, min_z, max_z);
            CREATE TABLE IF NOT EXISTS regions_3d(id INTEGER PRIMARY KEY, min_x BIG INT, max_x BIG INT, min_y BIG INT, max_y BIG INT, min_z BIG INT, max_z BIG INT);
            CREATE VIRTUAL TABLE regions_2d USING rtree(id, min_x, max_x, min_y, max_y);
            CREATE TABLE IF NOT EXISTS regions_2d(id INTEGER PRIMARY KEY, min_x BIG INT, max_x BIG INT, min_y BIG INT, max_y BIG INT);
            CREATE TABLE IF NOT EXISTS region_triggers(region_id INTEGER PRIMARY KEY, trigger_enter VARCHAR(100) NOT NULL, trigger_leave VARCHAR(100));
            CREATE TABLE IF NOT EXISTS region_groups(region_id INTEGER, region_group INTEGER, UNIQUE(region_group, region_id));
            CREATE INDEX regions_group ON region_groups(region_id);
            CREATE TABLE IF NOT EXISTS region_group_triggers(region_group INTEGER PRIMARY KEY, trigger_enter VARCHAR(100) NOT NULL, trigger_leave VARCHAR(100));
            CREATE TABLE IF NOT EXISTS log(id INTEGER PRIMARY KEY AUTOINCREMENT, entry_time UNSIGNED BIG INT NOT NULL, entry_source VARCHAR(100) DEFAULT NULL, entry_text TEXT NOT NULL);
            """)
        db_con.commit()
        return True
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not create database structure: %s' % e.args[0]
    except:
        print '[DATABASE ERROR] Exception occurred while creating database structure!'
    sys.exit(1)
    return False


def log_to_database(db_con, entry_source, entry_text):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("INSERT LOW PRIORITY INTO log (entry_time, entry_source, entry_text VALUES (?, '?', '?')", reactor.seconds(), entry_source, entry_text)
        db_con.commit()
        if db_cur.rowcount==1:
            return True
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not store log data: %s' % (data_key, e.args[0])
    except:
        print '[DATABASE ERROR] Could not store log data!'
    return False


def save_data(db_con, data_key, data_value, important=False):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("INSERT OR REPLACE INTO kv_data (data_key, data_value) VALUES ('?', ?)", data_key, sql_db.Binary(data_value))
        db_con.commit()
        if db_cur.rowcount==1:
            return True
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not store/update data for key "%s": %s' % (data_key, e.args[0])
    except:
        print '[DATABASE ERROR] Could not store/update data for key "%s"!' % data_key
    if important:
        sys.exit(1)
    return False


def load_data(db_con, data_key, default_value=None, important=False):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("SELECT data_value FROM kv_data WHERE data_key='?'", data_key)
        data_row = db_cur.fetchone()
        if data_row is not None:
            return data_row[0]
    except sql_db.Error, e:
        print '[DATABASE ERROR] Error while fetching value for key "%s": %s' % (data_key, e.args[0])
    except:
        print '[DATABASE ERROR] Could not fetch value for key "%s"!' % data_key
    if important:
        sys.exit(1)
    return default_value


def register_player(db_con, player, password):
    if not player:
        return None
    if not password:
        return None
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        pw_hash_bin = common.sha224_bin(password, config.password_salt)
        db_cur.execute("INSERT INTO players (ingame_name, password_hash, last_ip, last_online, online_seconds) VALUES ('?', ?, '?', ?, 0)", player.name, sql_db.Binary(pw_hash_bin), player.addr.host, reactor.seconds())
        db_con.commit()
        if db_cur.rowcount==1:
            return db_cur.lastrowid
    except:
        pass
    return None


def login_player(db_con, player, id, password):
    if not id:
        return False
    if not password:
        return False
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        pw_hash_bin = common.sha224_bin(password, config.password_salt)
        db_cur.execute("SELECT ingame_name, last_ip, last_online, online_seconds FROM players WHERE id=? AND password=?", id, sql_db.Binary(pw_hash_bin))
        if db_cur.rowcount==1:
            data_row = db_cur.fetchone()
            if data_row is not None:
                return data_row
        elif  db_cur.rowcount>1:
            print '[ERROR] Got more than one player from the database using the same ID: %s!' % id
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not log in player with id %s: %s' % (ip_address, e.args[0])
    except:
        pass
    return False


def ban_id(db_con, player_id, banned_by=None, banned_until=None, ban_reason=None):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("INSERT OR REPLACE INTO player_bans (player_id, ip_address, banned_by, banned_since, banned_until, reason) VALUES (?, (SELECT ip_address FROM players WHERE id=?), '?', ?, ?, '?')", player_id, player_id, banned_by, reactor.seconds(), banned_until, ban_reason)
        db_cur.commit()
        return True
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not ban player with IP %s: %s' % (ip_address, e.args[0])
    except:
        print '[DATABASE ERROR] Could not ban player with IP %s!' % ip_address
    print '[INFO] Shutting down to be on the secure side ...'
    sys.exit(1)
    return False


def ban_ip(db_con, ip_address, banned_by=None, banned_until=None, ban_reason=None):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("INSERT OR REPLACE INTO player_bans (player_id, ip_address, banned_by, banned_since, banned_until, reason) VALUES ((SELECT id FROM players WHERE last_ip='?'), '?', ?, ?, '?')", ip_address, ip_address, banned_by, reactor.seconds(), banned_until, ban_reason)
        db_cur.commit()
        return True
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not ban player with IP %s: %s' % (ip_address, e.args[0])
    except:
        print '[DATABASE ERROR] Could not ban player with IP %s!' % ip_address
    print '[INFO] Shutting down to be on the secure side ...'
    sys.exit(1)
    return False


def unban_id(db_con, player_id):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("DELETE FROM player_bans WHERE player_id=?", player_id)
        db_con.commit()
        if db_cur.rowcount >= 1:
            return True
        print '[INFO] No player with ID %s found for unbanning.' % player_id
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not unban player with ID %s:' % (player_id, e.args[0])
    return False


def unban_ip(db_con, ip_address):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("DELETE FROM player_bans WHERE player_id IN (SELECT player_id FROM player_bans WHERE ip_address='?')", ip_address)
        db_con.commit()
        if db_cur.rowcount >= 1:
            return True
        print '[INFO] No player with IP %s found for unbanning.' % ip_address
    except sql_db.Error, e:
        print '[DATABASE ERROR] Could not unban player with IP %s:' % (ip_address, e.args[0])
    return False


def is_banned_id(db_con, player_id):
    try:
        if not db_con:
            db_con = get_connection()
        db_cur = db_con.cursor()
        db_cur.execute("SELECT banned_until FROM player_bans WHERE player_id=? LIMIT 1", player_id)
        if db_cur.rowcount <= 0:
            return False
        ban_row = db_cur.fetchone()
        if ban_row is not None:
            if ban_row[0] <= reactor.seconds:
                unban_id(db_con, player_id)
                return False
    except sql_db.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
        sys.exit(1)
    finally:
        if db_con:
            db_con.close()
    return True
