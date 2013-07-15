from cuwo.pypy import has_pypy
import sys

def install_reactor():
    pass

if sys.platform == 'linux2':
    try:
        from twisted.internet import epollreactor
        install_reactor = epollreactor.install
    except ImportError:
        print '(dependencies missing for epoll, using normal reactor)'
elif sys.platform == 'win32' and not has_pypy:
    from twisted.internet import iocpreactor
    install_reactor = iocpreactor.install