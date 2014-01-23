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
import glob


class ConfigDict(dict):
    def __getattr__(self, name):
        return self[name]


class ConfigObject(object):
    def __init__(self, directory):
        self.directory = directory
        self.reload()

    def reload(self):
        self.config_dict = {}
        spec = os.path.join(self.directory, '*.py')
        for path in glob.glob(spec):
            name = os.path.splitext(os.path.basename(path))[0]
            new_dict = ConfigDict()
            execfile(path, {}, new_dict)
            self.config_dict[name] = new_dict

    def __getattr__(self, name):
        return self.config_dict[name]
