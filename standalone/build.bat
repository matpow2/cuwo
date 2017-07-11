rmdir /S /Q dist
rmdir /S /Q build
python build.py build
python post_build.py %*