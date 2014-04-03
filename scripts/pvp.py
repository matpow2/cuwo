# Copyright (c) Bjoern Lange 2014.
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

from cuwo.entity import FLAGS_1_HOSTILE
from cuwo.packet import EntityUpdate
from cuwo.packet import KillAction
from cuwo.packet import ServerUpdate
from cuwo.script import ConnectionScript
from cuwo.script import ServerScript
from cuwo.script import command
from cuwo.script import admin

import os.path

"""
Player versus player!
"""

ENTITY_HOSTILITY_FRIENDLY_PLAYER = 0
ENTITY_HOSTILITY_HOSTILE = 1
ENTITY_HOSTILITY_FRIENDLY = 2

SAVE_FILE = os.path.join('config', 'pvp')

KEY_PVP_ENABLED = 'pvp_enabled'
KEY_NOTIFY_ON_KILL = 'notify_on_kill'
KEY_GAIN_XP = 'gain_xp'
KEY_PVP_DISPLAY = 'pvp_display'

MASK_HOSTILITY = 1 << 7
MASK_FLAGS = 1 << 14
MASK_MULTIPLIERS = 1 << 30
MASK_TRANSFER = MASK_HOSTILITY | MASK_FLAGS | MASK_MULTIPLIERS

class PVPConnectionScript(ConnectionScript):
    max_hp = 100 # hp multiplier
    joined = False
    
    # events
    def on_join(self, event):
        self.parent.entity_id_mapping[self.connection.entity_data] = self.connection.entity_id
        self.max_hp = self.connection.entity_data.max_hp_multiplier
        if self.parent.pvp_enabled():
            self.make_hostile()
    
    def on_joined(self, event):
        self.force_entity_update()
        self.parent.on_joined(self)
    
    def on_unload(self):
        del self.parent.entity_id_mapping[self.connection.entity_data]
            
    def on_kill(self, event):
        # event is not called if an entity with a friendly display is killed
        if self.parent.gain_xp():
            kill_action = KillAction()
            kill_action.entity_id = self.connection.entity_id
            kill_action.target_id = self.parent.entity_id_mapping[event.target]
            kill_action.xp_gained = self.calculate_xp(self.connection.entity_data.level, event.target.level)
        
            self.parent.server_update_packet.kill_actions = [kill_action]
            self.server.broadcast_packet(self.parent.server_update_packet)
        
        if self.parent.notify_on_kill():
            self.server.send_chat('%s killed %s!' % (self.connection.name, event.target.name))
            
    def on_entity_update(self, event):
        if not self.joined:
            self.joined = True
            self.on_joined(event)
        
        if (event.mask & MASK_MULTIPLIERS) != 0 and self.connection.entity_data.max_hp_multiplier != self.max_hp:
            self.max_hp = self.connection.entity_data.max_hp_multiplier
            if self.parent.pvp_enabled():
                make_hostile()
            else:
                make_friendly()
           
    def on_flags_update(self, event):
        if self.parent.pvp_enabled():
            self.connection.entity_data.flags_1 |= FLAGS_1_HOSTILE
        
    # helper methods
    def make_hostile(self):
        entity_data = self.connection.entity_data
        entity_data.flags_1 |= FLAGS_1_HOSTILE
        entity_data.hostile_type = self.parent.get_pvp_display_mode()
        self.force_entity_update()
            
    def make_friendly(self):
        entity_data = self.connection.entity_data
        entity_data.flags_1 &= ~FLAGS_1_HOSTILE
        entity_data.hostile_type = ENTITY_HOSTILITY_FRIENDLY_PLAYER
        self.force_entity_update()
        
    def force_entity_update(self):
        # seems to be a client bug, the maximum health is not displayed correctly, so adapt it
        entity_update = self.parent.entity_update_packet
        entity_data = self.connection.entity_data
        
        if self.parent.pvp_enabled() and self.parent.get_pvp_display_mode() != ENTITY_HOSTILITY_FRIENDLY_PLAYER:
            entity_data.max_hp_multiplier = self.max_hp * 2.0
            entity_update.set_entity(entity_data, self.connection.entity_id, MASK_TRANSFER)
            self.broadcast_except_self(entity_update)
            entity_data.max_hp_multiplier = self.max_hp
            entity_update.set_entity(entity_data, self.connection.entity_id, MASK_TRANSFER)
            self.connection.send_packet(entity_update)
        else:
            entity_data.max_hp_multiplier = self.max_hp
            entity_update.set_entity(self.connection.entity_data, self.connection.entity_id, MASK_TRANSFER)
            self.server.broadcast_packet(entity_update)
        
    def send_entity_update(self, player):
        entity_update = self.parent.entity_update_packet
        entity_data = self.connection.entity_data
        
        if self.parent.pvp_enabled() and self.parent.get_pvp_display_mode() != ENTITY_HOSTILITY_FRIENDLY_PLAYER:
            entity_data.max_hp_multiplier = self.max_hp * 2.0
            entity_update.set_entity(entity_data, self.connection.entity_id, MASK_TRANSFER)
            player.send_packet(entity_update)
            entity_data.max_hp_multiplier = self.max_hp
        else:
            entity_data.max_hp_multiplier = self.max_hp
            entity_update.set_entity(entity_data, self.connection.entity_id, MASK_TRANSFER)
            player.send_packet(entity_update)
        
    def broadcast_except_self(self, packet):
        for player in self.server.players.values():
            if player != self.connection:
                player.send_packet(packet)
            
    def calculate_xp(self, killer_level, killed_level):
        return max(1, int(10.0 * float(killed_level) / float(killer_level)))        

class PVPScript(ServerScript):
    connection_class = PVPConnectionScript
    
    entity_update_packet = EntityUpdate()
    server_update_packet = ServerUpdate()
    
    entity_id_mapping = {}
    
    # events
    def on_load(self):
        self.server_update_packet.reset()
        self.settings = self.server.load_data(SAVE_FILE, {})
        if KEY_PVP_ENABLED not in self.settings:
            self.settings[KEY_PVP_ENABLED] = True
        if KEY_NOTIFY_ON_KILL not in self.settings:
            self.settings[KEY_NOTIFY_ON_KILL] = False
        if KEY_GAIN_XP not in self.settings:
            self.settings[KEY_GAIN_XP] = True
        if KEY_PVP_DISPLAY not in self.settings:
            self.settings[KEY_PVP_DISPLAY] = ENTITY_HOSTILITY_HOSTILE
            
    def on_joined(self, child):
        for c in self.children:
            if child != c:
                c.send_entity_update(child.connection)
            
    def update(self, event):
        if self.pvp_enabled() and self.get_pvp_display_mode() != ENTITY_HOSTILITY_HOSTILE:
            # the client doesn't allow friendly display and hostile behaviour, so have a little workaround...
            for player in self.server.players.values():
                player.entity_data.flags_1 |= FLAGS_1_HOSTILE
    
    def get_mode(self, event):
        if self.pvp_enabled():
            return 'pvp'
        else:
            return 'default'
            
    # helper methods
    def save_settings(self):
        self.server.save_data(SAVE_FILE, self.settings)
        
    def make_players_friendly(self):
        for child in self.children:
            child.make_friendly()
            
    def make_players_hostile(self):
        for child in self.children:
            child.make_hostile()
    
    # setters for settings
    def set_pvp_enabled(self, enabled):
        self.settings[KEY_PVP_ENABLED] = enabled
        self.save_settings()
        if enabled:
            self.make_players_hostile()
        else:
            self.make_players_friendly()
    
    def set_notify_on_kill(self, enabled):
        self.settings[KEY_NOTIFY_ON_KILL] = enabled
        self.save_settings()
        
    def set_gain_xp(self, gain):
        self.settings[KEY_GAIN_XP] = gain
        self.save_settings()
        
    def set_pvp_display_mode(self, display):
        self.settings[KEY_PVP_DISPLAY] = display
        self.save_settings()
        if self.pvp_enabled():
            self.make_players_hostile()
    
    # getters for settings
    def pvp_enabled(self):
        return self.settings[KEY_PVP_ENABLED]
        
    def notify_on_kill(self):
        return self.settings[KEY_NOTIFY_ON_KILL]
        
    def gain_xp(self):
        return self.settings[KEY_GAIN_XP]
        
    def get_pvp_display_mode(self):
        return self.settings[KEY_PVP_DISPLAY]

def get_class():
    return PVPScript
 
# pvp commands
@command
def pvp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.pvp_enabled():
        return 'PVP mode is active.'
    else:
        return 'PVP mode is not active'

@command
@admin
def enablepvp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.pvp_enabled():
        return 'PVP is already enabled.'
    else:
        pvp_script.set_pvp_enabled(True)
        return 'PVP has been enabled.'

@command
@admin
def disablepvp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if not pvp_script.pvp_enabled():
        return 'PVP is already disabled.'
    else:
        pvp_script.set_pvp_enabled(False)
        return 'PVP has been disabled'

@command
@admin
def togglepvp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.pvp_enabled():
        return disablepvp(script)
    else:
        return enablepvp(script)
        
# notify on kill commands
@command
def notifyonkill(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.notify_on_kill():
        return 'Kills are notified.'
    else:
        return 'Kills are not notified.'
        
@command
@admin
def enablenotifyonkill(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.notify_on_kill():
        return 'Kills are already notified.'
    else:
        pvp_script.set_notify_on_kill(True)
        return 'Kills are now notified.'
        
@command
@admin
def disablenotifyonkill(script):
    pvp_script = script.server.scripts.advanced_pvp
    if not pvp_script.notify_on_kill():
        return 'Kills are already not notified.'
    else:
        pvp_script.set_notify_on_kill(False)
        return 'Kills are no longer notified.'
        
@command
@admin
def togglenotifyonkill(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.notify_on_kill():
        return disablenotifyonkill(script)
    else:
        return enablenotifyonkill(script)

# gain xp commands        
@command
def gainxp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.gain_xp():
        return 'Players gain xp on player kills.'
    else:
        return "Players don't gain xp on player kills."
        
@command
@admin
def enablegainxp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.gain_xp():
        return 'Players already gain xp on player kills.'
    else:
        pvp_script.set_gain_xp(True)
        return 'Players will now gain xp on player kills.'
        
@command
@admin
def disablegainxp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if not pvp_script.gain_xp():
        return "Players already don't gain xp on player kills."
    else:
        pvp_script.set_gain_xp(False)
        return 'Players will no longer gain xp on player kills.'
        
@command
@admin
def togglegainxp(script):
    pvp_script = script.server.scripts.advanced_pvp
    if pvp_script.gain_xp():
        return disablegainxp(script)
    else:
        return enablegainxp(script)

# pvp displaymode command        
@command
def pvpdisplaymode(script):
    pvp_script = script.server.scripts.advanced_pvp
    dm = pvp_script.get_pvp_display_mode()
    if dm == ENTITY_HOSTILITY_FRIENDLY_PLAYER:
        return 'In pvp mode, players are displayed as friendly entities and are shown on the map (setting: friendlyplayer).'
    elif dm == ENTITY_HOSTILITY_FRIENDLY:
        return 'In pvp mode, players are displayed as friendly entities (setting: friendly).'
    elif dm == ENTITY_HOSTILITY_HOSTILE:
        return 'In pvp mode, players are displayed as hostile entities (setting: hostile).'
    else:
        return 'Unknown setting, value=%i' % dm

@command
@admin
def setpvpdisplaymode(script, display):
    pvp_script = script.server.scripts.advanced_pvp
    if display == 'friendlyplayer':
        pvp_script.set_pvp_display_mode(ENTITY_HOSTILITY_FRIENDLY_PLAYER)
        return 'In pvp mode, players are now displayed as friendly entities and are shown on the map.'
    elif display == 'friendly':
        pvp_script.set_pvp_display_mode(ENTITY_HOSTILITY_FRIENDLY)
        return 'In pvp mode, players are now displayed as friendly entities.'
    elif display == 'hostile':
        pvp_script.set_pvp_display_mode(ENTITY_HOSTILITY_HOSTILE)
        return 'In pvp mode, players are now displayed as hostile entities.'
    else:
        return 'Unknown mode: %s' % display
