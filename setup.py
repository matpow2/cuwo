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
import os
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from distutils.command import build_ext as _build_ext
from distutils.sysconfig import get_python_inc
from distutils.sysconfig import customize_compiler
import multiprocessing.pool
from distutils import log

ext_modules = []

names = [
    'cuwo.bytes',
    'cuwo.entity'
]

includes = ['./cuwo', './terraingen/include']
lib_dir = './lib'

macros = [('_CRT_SECURE_NO_WARNINGS', None)]

incdir = os.path.join(get_python_inc(plat_specific=1))
ext_modules.append(Extension('terraingen.pydasm', include_dirs=[incdir],
                             define_macros=macros,
                             sources=['./terraingen/pydasm/libdasm.c',
                                      './terraingen/pydasm/pydasm.c']))

tgen_module = Extension('cuwo.tgen', ['./cuwo/tgen.pyx'],
                        language='c++', include_dirs=includes,
                        library_dirs=[lib_dir], libraries=['tgen'])
ext_modules.append(tgen_module)

for name in names:
    ext_modules.append(Extension(name, ['./%s.pyx' % name.replace('.', '/')],
                                 language='c++', include_dirs=includes))

class build_ext(_build_ext.build_ext):
    def build_extensions(self):
        self.check_extensions_list(self.extensions)

        for ext in self.extensions:
            if ext.name == 'cuwo.tgen':
                self.generate_tgen_sources(ext)
            self.build_extension(ext)

    def generate_tgen_sources(self, ext):
        if not self.force and os.path.isdir('./terraingen/gensrc'):
            return
        from terraingen.converter import convert
        print 'Generating sources for tgen...'
        converter = convert('./data/Server.exe')
        sources = [os.path.relpath(src) for src in converter.get_sources()]
        print 'Generated %s source files.' % len(sources)

        print 'Building static tgen library (this may take a while)'
        is_msvc = self.compiler.compiler_type == 'msvc'
        includes = converter.get_includes(is_msvc)
        extra_args = []
        if is_msvc:
            extra_args += ['/wd4102', '/EHsc', '/MP']

        # make a parallel build
        def compile_single(source):
            return self.compiler.compile([source], output_dir=self.build_temp,
                                         macros=macros, include_dirs=includes,
                                         debug=self.debug,
                                         extra_postargs=extra_args)[0]

        old = log.set_threshold(log.WARN)
        # convert to list, imap is evaluated on-demand
        pool = multiprocessing.pool.ThreadPool(multiprocessing.cpu_count())
        objects = list(pool.imap(compile_single, sources))
        log.set_threshold(old)

        if os.name == 'nt':
            rsp_path = os.path.join(self.build_temp, 'link.rsp')
            fp = open(rsp_path, 'wb')
            fp.write(' '.join(objects))
            fp.close()
            objects = ['@' + rsp_path]

        if is_msvc:
            objects += ['/NOLOGO']

        language = ext.language or self.compiler.detect_language(sources)
        old_force = self.compiler.force
        self.compiler.force = True
        self.compiler.create_static_lib(objects, 'tgen',
                                        output_dir=os.path.relpath(lib_dir),
                                        debug=self.debug)
        self.compiler.force = old_force

setup(
    name='cuwo extensions',
    ext_modules=cythonize(ext_modules),
    cmdclass={"build_ext": build_ext}
)
