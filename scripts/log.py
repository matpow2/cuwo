# Copyright (c) Mathias Kaerlev 2013-2017.
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
from cuwo.common import create_file_path

import logging
from logging.handlers import TimedRotatingFileHandler

import time
import sys


class LoggerWriter:
    data = ''
    errors = 'strict'

    def __init__(self, fp, logger, level):
        self.fp = fp
        self.errors = fp.errors
        self.encoding = fp.encoding
        self.logger = logger
        self.level = level

    def write(self, message):
        self.data += message
        splitted = self.data.split('\n')
        for message in splitted[:-1]:
            self.logger.log(self.level, message)
        self.data = splitted[-1]

    def flush(self):
        self.fp.flush()


class LogServer(ServerScript):
    connection_class = None

    def on_load(self):
        logger = logging.getLogger()
        logger.setLevel(logging.INFO)

        # also write stdout/stderr to log file
        sys.stdout = LoggerWriter(sys.__stdout__, logger, logging.INFO)
        sys.sterr = LoggerWriter(sys.__stderr__, logger, logging.ERROR)

        config = self.server.config.base
        logfile = config.log_name
        if config.rotate_daily:
            create_file_path(logfile)
            handler = TimedRotatingFileHandler(logfile, when='d')
        else:
            handler = logging.FileHandler(logfile)
        handler.setFormatter(logging.Formatter(config.file_log_format))
        logger.addHandler(handler)
        self.file_handler = handler

        # log normal logging messages to stdout
        handler = logging.StreamHandler(sys.__stdout__)
        handler.setFormatter(logging.Formatter(config.console_log_format))
        logger.addHandler(handler)
        self.console_handler = handler

        print('cuwo server started on %s' % time.strftime('%c'))

    def on_unload(self):
        sys.stdout = sys.__stdout__
        sys.stderr = sys.__stderr__
        self.file_handler.close()
        self.console_handler.close()


def get_class():
    return LogServer
