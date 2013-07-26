import sys
sys.path.append('..')

import os
import shutil
import subprocess
import tarfile
import stat


def copy(src, dst):
    if os.path.isfile(src):
        shutil.copyfile(src, dst)
    else:
        shutil.copytree(src, dst)


def get_git_rev():
    pipe = subprocess.Popen(
        ["git rev-parse --short HEAD"],
        stdout=subprocess.PIPE, shell=True)
    return pipe.stdout.read().replace('\n', '')

# copy files
SERVER_FILES = ['scripts', 'config']
COPY_FILES = {}
REMOVE_EXTENSIONS = ['pyc', 'pyo']
REMOVE_FILES = ['w9xpopen.exe', 'dummy']

open('./dist/run.sh', 'wb').write('#!/bin/sh\n./server')
st = os.stat('./dist/run.sh')
os.chmod('./dist/run.sh', st.st_mode | stat.S_IEXEC)

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

# rewrite config
git_rev = get_git_rev()
config = open('./dist/config/base.py', 'rU').read()
open('./dist/config/base.py', 'wb').write(
    config + '\n# Current revision\ngit_rev = %r\n' % git_rev)


filename = 'cuwo-%s.tar.gz' % git_rev

try:
    os.remove(filename)
except OSError:
    pass

try:
    with tarfile.open(filename, "w:gz") as tar:
        tar.add("dist", arcname=os.path.basename("dist"))
except tarfile.TarError as e:
    print e
    print 'tarfile failed, you sure your python is compiled with tar support?'
