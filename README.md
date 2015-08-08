# EAWebKit

### Origin
Based on v13.3.2.0, patched to v13.4.2.0\
See: http://gpl.ea.com

### Changelog of this Fork
- Applied Modifications made in 13.4.2.0 
- Disabled Default Filesystem Provider (you'll have to register your own via appsystems @ EAWebKitLib::Init() ..,\
  see FileSystemDefault @ EAWebKitFileSystem.cpp for example-code)
- Updated Bundled 3rd Party libraries:
  - Updated Bundled libpng (v1.6.18)
  - Updated Bundled zlib (v1.2.8)
  - Updated Bundled SQLite (v3.8.11.1)
  - Updated Bundled libjpeg (v9a)
  - Updated Bundled FreeType (v2.6)
  - Updated Bundled Pixman (v0.32.6)
  - Updated Bundled cairo (v1.14.2)\
  **Note**: All libs are patched to use EAWebKit's memory allocation routines (the old-bundled-libs were also patched)

 - Changed file-naming of the result libraries:
   | Platform | Binary Name |
   |---|---|
   | Windows 32 Bit | EAWebKit.dll |
   | Windows 32 Bit (Debug) | EAWebKitd.dll |
   | Windows 64 Bit | EAWebKit64.dll |
   | Windows 64 Bit (Debug) | EAWebKit64d.dll |
  
**Note (PS4, Xbox One)** \
The Projects & Solutions for Xbox-One and PS4 haven't changed, this may cause PS4 && XBONE are'nt supported at the moment.

### Usage
This fork is intended for being used in Blockz (project-codename, final product-name pending) an Industrial-Voxel-Game.\
It's mainly used for our UI System.

### Maintainer
Florian Wilkemeyer - <fw@f-ws.de> 
