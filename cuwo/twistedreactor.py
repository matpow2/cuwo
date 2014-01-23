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

from cuwo.pypy import has_pypy
import sys


def install_reactor():
    pass

try:
    if sys.platform == 'linux2':
        from twisted.internet import epollreactor
        install_reactor = epollreactor.install
    elif sys.platform == 'win32' and not has_pypy:
        from twisted.internet import iocpreactor
        install_reactor = iocpreactor.install
except ImportError:
    pass
