# -*- mode: python -*-
# All those hidden imports O.o I'm surprised pyinstaller can't find them

a = Analysis(['../cuwo/server.py'],
             pathex=['/home/mid-kid/Stuff/programming/workspace/cuwo'],
             hiddenimports=["twisted.python.logfile", "twisted.protocols.basic", "twisted.internet.stdio", "twisted.internet._posixstdio", "json", "json.decoder", "json.scanner", "json.encoder"],
             excludes=["config"])
pyz = PYZ(a.pure)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name=os.path.join('dist', 'server'))
