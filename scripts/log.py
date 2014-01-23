# Copyright (c) Mathias Kaerlev 2013-2014.
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
from cuwo.common import create_file_path, open_create

from twisted.python import log
from twisted.python.logfile import DailyLogFile

import time
import sys


class LogServer(ServerScript):
    # should probably perform logging directly later, rather than letting
    # cuwo.server do it.
    connection_class = None

    def on_load(self):
        config = self.server.config.base
        logfile = config.log_name
        if config.rotate_daily:
            create_file_path(logfile)
            logging_file = DailyLogFile(logfile, '.')
        else:
            logging_file = open_create(logfile, 'a')
        self.file_observer = log.FileLogObserver(logging_file)
        log.addObserver(self.file_observer.emit)
        log.msg('cuwo server started on %s' % time.strftime('%c'))
        self.observer = log.startLogging(sys.stdout)  # force twisted logging

    def on_unload(self):
        self.file_observer.stop()
        self.observer.stop()


def get_class():
    return LogServer
