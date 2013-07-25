# Copyright (c) Mathias Kaerlev, Somer Hayter, sarcengm and Jakky89 2013.
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

"""
Performs logging
"""

from cuwo.script import ServerScript

import time
import sys


ANNOUNCE_IRC = False
ANNOUNCE_SERVER_ACTION = "[INFO] The server is {action} in {time} seconds."
ANNOUNCE_MESSAGES = [
    "You can change this announcement."
]

class Announcer(ServerScript):
    first_tick = True
    server = None
    exit_code = 0
    time_left = 0
    action = 'shutting down'
    action_func = None
    action_func_args = None

    # Announce frequency, the closer to 0 more frequent it announces
    tick_step_sizes = (60*60, 30*60, 10*60, 5*60, 60, 30, 10, 5)

    def announce_tick(self):
        if self.time_left > 0:

            tick_size = 1
            for i in self.tick_step_sizes:
                if self.time_left > i:
                    tick_size = min(i, self.time_left - i)
                    break

            self.time_left = self.time_left - tick_size
            reactor.callLater(tick_size, self.announce_tick)

            announcement = ""

            if ((self.first_tick or self.time_left >= 10)
                    and not self.reason is None):

                announcement = (self.message_long
                                .format(action=self.action,
                                        time=self.time_left+tick_size,
                                        reason=self.reason))
            else:
                announcement = (self.message
                                .format(action=self.action,
                                        time=self.time_left+tick_size))

            self.server.send_chat(announcement)

            if self.irc_announcement:
                try:
                    self.server.scripts.irc.send(announcement)
                except AttributeError:
                    self.irc_announcement = False
                except KeyError:
                    self.irc_announcement = False

            print announcement
        else:
            if not self.action_func is None:
                print self.action_func_args
                self.action_func(*self.action_func_args)

        self.first_tick = False

    def announce(self):
        self.first_tick = True
        self.announce_tick()

 def get_class():
    return Announcer
