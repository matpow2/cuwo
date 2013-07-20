from distutils.core import setup
import py2exe

import sys
sys.path.append('..')

setup(
    console=['../cuwo/server.py'],
    zipfile=None,
    options={
        'py2exe': {
            'compressed': 1,
            'optimize': 2,
            'bundle_files': 1,
            'includes': ['zope.interface', 'twisted.web.resource'],
            'packages': ['cuwo', 'twisted.words', 'encodings'],
            'excludes': ['config'],
            'dll_excludes': ["mswsock.dll", "powrprof.dll"]
        }}
)
