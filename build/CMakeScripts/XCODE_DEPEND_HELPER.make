# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.CGL.Debug:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Debug/libCGL.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Debug/libCGL.a


PostBuild.glew.Debug:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Debug/libglew.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Debug/libglew.a


PostBuild.glfw.Debug:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Debug/libglfw3.a


PostBuild.meshedit.Debug:
PostBuild.CGL.Debug: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Debug/meshedit
PostBuild.glew.Debug: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Debug/meshedit
PostBuild.glfw.Debug: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Debug/meshedit
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Debug/meshedit:\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Debug/libCGL.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Debug/libglew.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Debug/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/src/dirent/glut32.lib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Debug/meshedit


PostBuild.CGL.Release:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Release/libCGL.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Release/libCGL.a


PostBuild.glew.Release:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Release/libglew.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Release/libglew.a


PostBuild.glfw.Release:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Release/libglfw3.a


PostBuild.meshedit.Release:
PostBuild.CGL.Release: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Release/meshedit
PostBuild.glew.Release: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Release/meshedit
PostBuild.glfw.Release: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Release/meshedit
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Release/meshedit:\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Release/libCGL.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Release/libglew.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Release/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/src/dirent/glut32.lib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/Release/meshedit


PostBuild.CGL.MinSizeRel:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/MinSizeRel/libCGL.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/MinSizeRel/libCGL.a


PostBuild.glew.MinSizeRel:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/MinSizeRel/libglew.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/MinSizeRel/libglew.a


PostBuild.glfw.MinSizeRel:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.meshedit.MinSizeRel:
PostBuild.CGL.MinSizeRel: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/MinSizeRel/meshedit
PostBuild.glew.MinSizeRel: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/MinSizeRel/meshedit
PostBuild.glfw.MinSizeRel: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/MinSizeRel/meshedit
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/MinSizeRel/meshedit:\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/MinSizeRel/libCGL.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/MinSizeRel/libglew.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/src/dirent/glut32.lib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/MinSizeRel/meshedit


PostBuild.CGL.RelWithDebInfo:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/RelWithDebInfo/libCGL.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/RelWithDebInfo/libCGL.a


PostBuild.glew.RelWithDebInfo:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/RelWithDebInfo/libglew.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/RelWithDebInfo/libglew.a


PostBuild.glfw.RelWithDebInfo:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a


PostBuild.meshedit.RelWithDebInfo:
PostBuild.CGL.RelWithDebInfo: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/RelWithDebInfo/meshedit
PostBuild.glew.RelWithDebInfo: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/RelWithDebInfo/meshedit
PostBuild.glfw.RelWithDebInfo: /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/RelWithDebInfo/meshedit
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/RelWithDebInfo/meshedit:\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/RelWithDebInfo/libCGL.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/RelWithDebInfo/libglew.a\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/Users/jessicalee/Documents/p2-meshedit-jeshlee121/src/dirent/glut32.lib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/RelWithDebInfo/meshedit




# For each target create a dummy ruleso the target does not have to exist
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Debug/libglew.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/MinSizeRel/libglew.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/RelWithDebInfo/libglew.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glew/Release/libglew.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Debug/libglfw3.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/deps/glfw/src/Release/libglfw3.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Debug/libCGL.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/MinSizeRel/libCGL.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/RelWithDebInfo/libCGL.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/build/CGL/src/Release/libCGL.a:
/Users/jessicalee/Documents/p2-meshedit-jeshlee121/src/dirent/glut32.lib:
/usr/local/lib/libfreetype.dylib:
