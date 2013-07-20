# Copyright (c) Julien Kross 2013.
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
import sqlite3 as sqldb

from twisted.internet import reactor
from cuwo import constants


def getDatabaseConnection():
    try:
        dbcon = sqldb.connect('cuwo.db')
        self.createDatabaseStructure()
        return dbcon
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
    return None

def createDatabaseStructure():
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.executescript("""
            CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY AUTO_INCREMENT, ingame_name VARCHAR(100) NOT NULL, login_pass VARCHAR(100) DEFAULT NULL, last_ip VARCHAR(100) DEFAULT NULL, last_online UNSIGNED BIG INT DEFAULT NULL, online_seconds UNSIGNED BIG INT DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS player_bans(player_id INTEGER PRIMARY KEY, ip_address VARCHAR(100) NOT NULL UNIQUE, banned_by INTEGER DEFAULT NULL, banned_since UNSIGNED BIG INT NOT NULL, banned_until UNSIGNED BIG INT DEFAULT NULL, reason TEXT DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS server_kv_data(data_key VARCHAR(64) PRIMARY KEY, data_value BLOB DEFAULT NULL);
            CREATE TABLE IF NOT EXISTS server_log(id INTEGER PRIMARY KEY AUTO_INCREMENT, entry_time UNSIGNED BIG INT NOT NULL, entry_text TEXT NOT NULL, player_id INTEGER DEFAULT NULL);
            """)
        dbcon.commit()
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
        sys.exit(1)
    finally:
        if dbcon:
            dbcon.close()

def save_data(dataKey, dataValue):
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.execute("INSERT INSERT OR REPLACE INTO server_kv_data (data_key, data_value) VALUES ('?', '?')", dataKey, dataValue)
        dbcon.commit()
        return True
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
    finally:
        if dbcon:
            dbcon.close()
    return False

def load_data(dataKey, defaultData = None):
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.execute("SELECT data_value FROM server_kv_data WHERE data_key='?'", dataKey)
        dbcon.commit()
        datarow = dbcur.fetchone()
        return datarow[0]
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
    finally:
        if dbcon:
            dbcon.close()
    return defaultData

def banIP(ipAddress, bannedBy = None, bannedUntil = None, banReason = None):
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.execute("INSERT INTO player_bans (player_id, ip_address, banned_by, banned_until, reason) VALUES ((SELECT id FROM players WHERE last_ip='?'), '?', '?', ?, '?')", ipAddress, ipAddress, bannedBy, bannedUntil, banReason)
        dbcon.commit()
        return True
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
    finally:
        if dbcon:
            dbcon.close()
    return False

def unbanIP(ipAddress):
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.execute("DELETE FROM player_bans WHERE ip_address='?'", ipAddress)
        dbcon.commit()
        return True
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
    finally:
        if dbcon:
            dbcon.close()
    return False

def isBannedIP(ipAddress):
    try:
        dbcon = getDatabaseConnection()
        dbcur = dbcon.cursor()
        dbcur.execute("SELECT banned_until FROM player_bans WHERE player_bans.ip_address='?' LIMIT 1", ipAddress)
        dbcon.commit()
        if dbcur.rowcount <= 0:
            return False
        banrow = dbcur.fetchone()
        if banrow[1] <= reactor.seconds:
            unbanIP(ipAddress)
            return False
    except sqldb.Error, e:
        print '[DATABASE ERROR] %s' % e.args[0]
        sys.exit(1)
    finally:
        if dbcon:
            dbcon.close()
    return True
