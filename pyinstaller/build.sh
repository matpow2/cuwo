#!/bin/sh

clean(){
    rm -rf build dist *.log *.tar.gz
}

if [ -z "$1" ]; then
    echo "Usage: ./build.sh <path to pyinstaller>/<clean>"
elif [ $1 == "clean" ]; then
    clean
else
    clean
    for file in "$1/pyinstaller.py ./server.spec" "./post_build.py"; do
        /usr/bin/env python2.7 $file
    done
fi
