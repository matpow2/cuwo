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
    return pipe.stdout.read().replace('\n', '')

# write config
git_rev = get_git_rev()
config = open('../config.py', 'rU').read()
open('./dist/config.py', 'wb').write(
    config + '\n\n# Current revision\ngit_rev = %r\n' % git_rev)

# copy files
SERVER_FILES = ['scripts']
COPY_FILES = {}
REMOVE_EXTENSIONS = ['pyc', 'pyo']
REMOVE_FILES = ['w9xpopen.exe', 'dummy']

open('./dist/run.bat', 'wb').write('server.exe\npause\n')

for name in SERVER_FILES:
    copy('../%s' % name, './dist/%s' % name)

for src, dst in COPY_FILES.iteritems():
    copy('../%s' % src, './dist/%s' % dst)

for root, sub, files in os.walk('./dist'):
    for file in files:
        path = os.path.join(root, file)
        if file in REMOVE_FILES:
            os.remove(path)
        else:
            for ext in REMOVE_EXTENSIONS:
                if file.endswith(ext):
                    os.remove(path)
                    break

filename = 'cuwo-%s.zip' % git_rev

try:
    os.remove(filename)
except OSError:
    pass

try:
    subprocess.check_call(['7z', 'a', filename, 'dist'])
except WindowsError:
    print '7zip failed - do you have the 7zip directory in PATH?'
