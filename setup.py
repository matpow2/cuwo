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
from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

ext_modules = []

names = [
    'cuwo.bytes',
    'cuwo.entity'
]

includes = ['./cuwo', './terraingen/include']
lib_dirs = ['./lib']

for name in names:
    ext_modules.append(Extension(name, ['./%s.pyx' % name.replace('.', '/')],
                                 language='c++', include_dirs=includes))

ext_modules.append(Extension('cuwo.tgen', ['./cuwo/tgen.pyx'],
                             language='c++', include_dirs=includes,
                             library_dirs=lib_dirs, libraries=['tgen']))

setup(
    name='cuwo extensions',
    ext_modules=cythonize(ext_modules)
)
