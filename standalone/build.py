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

from distutils.core import setup
import py2exe

import sys
sys.path.append('..')

setup(
    console=['../cuwo/server.py'],
    zipfile=None,
    options={
        'py2exe': {
            'dist_dir': 'dist/bin',
            'compressed': 1,
            'optimize': 2,
            'bundle_files': 3,
            'includes': ['json', 'platform'],
            'packages': ['encodings', 'irc3', 'cuwo'],
            'excludes': ['config'],
            'dll_excludes': ["mswsock.dll", "powrprof.dll"]
        }}
)
