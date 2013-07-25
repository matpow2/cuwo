try:
    import __pypy__
    has_pypy = True
except ImportError:
    has_pypy = False

if has_pypy:
    class dummymodule(object):
        pass

    import sys
    for name in ('win32api', 'win32pipe', 'win32file', 'pywintypes'):
        sys.modules[name] = dummymodule
