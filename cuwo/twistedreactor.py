from cuwo.pypy import has_pypy
import sys

def install_reactor():
    pass

try:
    if sys.platform == 'linux2':
        from twisted.internet import epollreactor
        install_reactor = epollreactor.install
    elif sys.platform == 'win32' and not has_pypy:
        from twisted.internet import iocpreactor
        install_reactor = iocpreactor.install
except ImportError:
    pass