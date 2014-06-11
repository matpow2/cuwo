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

import sys
sys.path.append('..')

import os
import shutil
import subprocess


def copy(src, dst):
    if os.path.isfile(src):
        shutil.copyfile(src, dst)
    else:
        shutil.copytree(src, dst)


def get_git_rev():
    pipe = subprocess.Popen(
        ["git", "rev-parse", "--short", "HEAD"],
        stdout=subprocess.PIPE, shell=True)
    return pipe.stdout.read().decode('utf-8').replace('\n', '')

# copy files
SERVER_FILES = ['scripts', 'config']
COPY_FILES = {}
REMOVE_EXTENSIONS = ['pyc', 'pyo']
REMOVE_FILES = ['w9xpopen.exe', 'dummy']

open('./dist/run.bat', 'wb').write(b'bin\server.exe\r\npause\r\n')

for name in SERVER_FILES:
    copy('../%s' % name, './dist/%s' % name)

for src, dst in COPY_FILES.items():
    copy('../%s' % src, './dist/%s' % dst)

for root, sub, files in os.walk('./dist'):
    for name in files:
        path = os.path.join(root, name)
        if name in REMOVE_FILES:
            os.remove(path)
        else:
            for ext in REMOVE_EXTENSIONS:
                if name.endswith(ext):
                    os.remove(path)
                    break

os.makedirs('./dist/data')

# rewrite config
git_rev = get_git_rev()
config = open('./dist/config/base.py', 'rb').read().decode('utf-8')
config += '\n# Current revision\ngit_rev = %r\n' % git_rev
open('./dist/config/base.py', 'wb').write(config.encode('utf-8'))


filename = 'cuwo-%s.zip' % git_rev

try:
    os.remove(filename)
except OSError:
    pass

try:
    subprocess.check_call(['7z', 'a', filename, 'dist'])
except WindowsError:
    print('7zip failed - do you have the 7zip directory in PATH?')
