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

import os
import sys
sys.path.append('..')

# cx_Freeze issue 155
PYTHON_INSTALL_DIR = os.path.dirname(os.path.dirname(os.__file__))
os.environ['TCL_LIBRARY'] = os.path.join(PYTHON_INSTALL_DIR, 'tcl', 'tcl8.6')
os.environ['TK_LIBRARY'] = os.path.join(PYTHON_INSTALL_DIR, 'tcl', 'tk8.6')

from cx_Freeze import setup, Executable

build_options = {
    'packages': ['encodings', 'irc3', 'cuwo', 'asyncio', 'numpy',
                 'pyrr', 'discord'],
    'excludes': ['config'],
    'includes': ['json', 'platform'],

    # cx_Freeze issue 155
    'include_files': [
        os.path.join(PYTHON_INSTALL_DIR, 'DLLs', 'tk86t.dll'),
        os.path.join(PYTHON_INSTALL_DIR, 'DLLs', 'tcl86t.dll')
    ]
}

executables = [
    Executable('../cuwo/server.py', base='Console', targetName='server.exe')
]

setup(options={'build_exe': build_options}, executables=executables)
