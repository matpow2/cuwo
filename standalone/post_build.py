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


def git_ls(path):
    pipe = subprocess.Popen(
        ['git', 'ls-tree', '--name-only', '--full-tree', '-r', 'HEAD', path],
        stdout=subprocess.PIPE, shell=True)
    data = pipe.stdout.read().decode('utf-8')
    return data.splitlines()


def copy_git(src, prefix):
    prefix = os.path.relpath(os.path.join(os.getcwd(), prefix), '..')
    prefix = prefix.replace('\\', '/') + '/'
    for src_file in git_ls(src):
        args = ['git', 'checkout-index', '-f', '--prefix=%s' % prefix,
                src_file]
        subprocess.Popen(args, shell=True, cwd='..').wait()


# copy files
GIT_FILES = ['scripts', 'config']
REMOVE_FILES = ['dummy']


# include files
CRT_DIR = (r'C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC'
           r'\redist\{ARCH}\Microsoft.VC140.CRT')
CRT_FILES = ['msvcp140.dll', 'vcruntime140.dll']
UCRT_DIR = r'C:\Program Files (x86)\Windows Kits\10\Redist\ucrt\DLLs\x64'
INCLUDE_FILES = [os.path.join(CRT_DIR, name) for name in CRT_FILES]
INCLUDE_FILES += [os.path.join(UCRT_DIR, name)
                  for name in os.listdir(UCRT_DIR)]


def main():
    src_dir = os.path.join('build', os.listdir('./build')[0])
    copy(src_dir, './dist/bin')

    open('./dist/run.bat', 'wb').write(b'bin\server.exe\r\npause\r\n')

    is_64bits = sys.maxsize > 2**32
    if is_64bits:
        arch = 'x64'
    else:
        arch = 'x86'
    for name in INCLUDE_FILES:
        name = name.format(ARCH=arch)
        copy(name, os.path.join('./dist/bin', os.path.basename(name)))

    for name in GIT_FILES:
        copy_git(name, './dist')

    for root, sub, files in os.walk('./dist'):
        for name in files:
            path = os.path.join(root, name)
            if name in REMOVE_FILES:
                os.remove(path)

    os.makedirs('./dist/data')

    # rewrite config
    git_rev = get_git_rev()
    config = open('./dist/config/base.py', 'rb').read().decode('utf-8')
    config += '\n# Current revision\ngit_rev = %r\n' % git_rev
    open('./dist/config/base.py', 'wb').write(config.encode('utf-8'))

    filename = 'cuwo.zip'

    try:
        os.remove(filename)
    except OSError:
        pass

    args = ['7z', 'a']
    if len(sys.argv) == 2:
        filename = os.path.join(sys.argv[1], filename)
    args += [filename, 'dist']

    try:
        subprocess.check_call(args)
    except WindowsError:
        print('7zip failed - do you have the 7zip directory in PATH?')

if __name__ == '__main__':
    main()