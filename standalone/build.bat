rmdir /S /Q dist
mkdir dist
py -3 build.py py2exe
py -3 post_build.py %*