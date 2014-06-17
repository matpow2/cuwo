rmdir /S /Q dist
rmdir /S /Q build
py -3 build.py build
py -3 post_build.py %*