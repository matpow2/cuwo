rmdir /S /Q dist
rmdir /S /Q build
py -3 build_cxfreeze.py build
py -3 post_build.py %*