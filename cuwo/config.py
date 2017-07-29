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

import os


class ConfigDict(dict):
    def __getattr__(self, name):
        try:
            return self[name]
        except KeyError:
            raise KeyError('Missing entry %r in configuration file %s.' %
                           (name, self.filename)) from None


class ConfigObject:
    def __init__(self, directory):
        self.directory = directory
        self.reload()

    def load(self, name):
        path = os.path.join(self.directory, name + '.py')
        path = os.path.abspath(path)

        try:
            with open(path) as fp:
                data = fp.read()
        except FileNotFoundError:
            raise FileNotFoundError('Could not find configuration file %s.'
                                    % path) from None

        new_dict = ConfigDict()
        new_dict.filename = path
        exec(compile(data, path, 'exec'), {}, new_dict)
        self.config_dict[name] = new_dict

    def reload(self):
        self.config_dict = {}

    def __getattr__(self, name):
        if name not in self.config_dict:
            self.load(name)
        return self.config_dict[name]
