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
Utilities for downloading Cube World package files from Picroma

Useful for downloading the terraingen dependencies
"""

import urllib.request
from urllib.error import HTTPError
import xml.dom.minidom
import zlib
import getpass
import os
import sys


VALIDATE_URL = 'https://picroma.com/cwvalidate/'
BASE_URL = 'https://s3.amazonaws.com/picroma/cwdownload/'
PACKAGE_FILE = BASE_URL + 'package.xml'


class ValidateError(Exception):
    pass


def download(s):
    return urllib.request.urlopen(s).read()


def validate(email, password, challenge=0):
    url = VALIDATE_URL + '?e={}&p={}&id={:032x}'.format(email, password,
                                                        challenge)
    try:
        download(url)
    except HTTPError:
        return False
    return True


def get_node_value(node, name):
    return node.getElementsByTagName(name)[0].firstChild.nodeValue


def download_package(*files):
    package = download(PACKAGE_FILE)
    doc = xml.dom.minidom.parseString(package.decode())
    result = []

    for node in doc.getElementsByTagName('file'):
        destination = get_node_value(node, 'destination')
        if destination not in files:
            continue
        source = get_node_value(node, 'source')
        print('Downloading {}'.format(destination))
        data = zlib.decompress(download(BASE_URL + source))
        result.append(data)

    return result


def get_input(prompt):
    if sys.stdin.isatty():
        return input(prompt)

    old_stdin = sys.stdin
    sys.stdin = open('/dev/tty', 'r')
    ret = input(prompt)
    sys.stdin.close()
    sys.stdin = old_stdin
    return ret


def download_prompt(*files, email=None, password=None):
    if 'TRAVIS' in os.environ:
        # Do not prompt if on Travis.
        return download_package(*files)

    if email and password:
        if not validate(email, password):
            print('Invalid login details, skipping package')
            raise ValidateError('Invalid login')
        return download_package(*files)

    print('Picroma login (leave empty to skip package)')

    while True:
        use_email = email or get_input('Email: ')
        if use_email:
            use_password = password or getpass.getpass()

        if not use_email or not use_password:
            raise ValidateError('Empty login provided')

        if validate(use_email, use_password):
            break

        print('Invalid login details, please try again')

    return download_package(*files)


def get_data_path(name):
    return os.path.join(os.getcwd(), 'data', name)


def download_dependencies(email=None, password=None):
    names = ('data1.db', 'data4.db')

    for name in names:
        if not os.path.isfile(get_data_path(name)):
            break
    else:
        return

    try:
        files = download_prompt(*names, email=email, password=password)
    except ValidateError:
        return

    for index, name in enumerate(names):
        filename = get_data_path(name)
        with open(filename, 'wb') as fp:
            fp.write(files[index])


def main():
    import argparse
    parser = argparse.ArgumentParser(
        description='Download Cube World assets using a Picroma account'
    )
    parser.add_argument('email')
    parser.add_argument('password')
    args = parser.parse_args()
    download_dependencies(parser.email, parser.password)


if __name__ == '__main__':
    main()
