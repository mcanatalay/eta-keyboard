# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/can/projects/etaKeyboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/can/projects/etaKeyboard/build

# Include any dependencies generated for this target.
include CMakeFiles/etakeyboard.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/etakeyboard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/etakeyboard.dir/flags.make

reader.moc: ../reader.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/can/projects/etaKeyboard/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating reader.moc"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc -I/usr/include -I/usr/include/KDE -I/usr/include/KDE -I/usr/include -I/usr/include/qt4/phonon -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtWebKit -I/usr/include/qt4/QtUiTools -I/usr/include/qt4/QtTest -I/usr/include/qt4/QtSvg -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtScriptTools -I/usr/include/qt4/QtScript -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtHelp -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDeclarative -I/usr/include/qt4/QtDBus -I/usr/include/qt4/Qt3Support -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/Qt -I/usr/share/qt4/mkspecs/default -I/usr/include/qt4 -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include/qt4/phonon -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtWebKit -I/usr/include/qt4/QtUiTools -I/usr/include/qt4/QtTest -I/usr/include/qt4/QtSvg -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtScriptTools -I/usr/include/qt4/QtScript -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtHelp -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDeclarative -I/usr/include/qt4/QtDBus -I/usr/include/qt4/Qt3Support -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/Qt -I/usr/share/qt4/mkspecs/default -I/usr/include/qt4 -I/home/can/projects/etaKeyboard/build -D_BSD_SOURCE -o /home/can/projects/etaKeyboard/build/reader.moc /home/can/projects/etaKeyboard/reader.h

etaKeyboard.moc: ../etaKeyboard.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/can/projects/etaKeyboard/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating etaKeyboard.moc"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc -I/usr/include -I/usr/include/KDE -I/usr/include/KDE -I/usr/include -I/usr/include/qt4/phonon -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtWebKit -I/usr/include/qt4/QtUiTools -I/usr/include/qt4/QtTest -I/usr/include/qt4/QtSvg -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtScriptTools -I/usr/include/qt4/QtScript -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtHelp -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDeclarative -I/usr/include/qt4/QtDBus -I/usr/include/qt4/Qt3Support -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/Qt -I/usr/share/qt4/mkspecs/default -I/usr/include/qt4 -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include -I/usr/include/qt4/phonon -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtWebKit -I/usr/include/qt4/QtUiTools -I/usr/include/qt4/QtTest -I/usr/include/qt4/QtSvg -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtScriptTools -I/usr/include/qt4/QtScript -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtHelp -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDesigner -I/usr/include/qt4/QtDeclarative -I/usr/include/qt4/QtDBus -I/usr/include/qt4/Qt3Support -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/Qt -I/usr/share/qt4/mkspecs/default -I/usr/include/qt4 -I/home/can/projects/etaKeyboard/build -D_BSD_SOURCE -o /home/can/projects/etaKeyboard/build/etaKeyboard.moc /home/can/projects/etaKeyboard/etaKeyboard.h

CMakeFiles/etakeyboard.dir/reader.o: CMakeFiles/etakeyboard.dir/flags.make
CMakeFiles/etakeyboard.dir/reader.o: ../reader.cpp
CMakeFiles/etakeyboard.dir/reader.o: reader.moc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/can/projects/etaKeyboard/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/etakeyboard.dir/reader.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/etakeyboard.dir/reader.o -c /home/can/projects/etaKeyboard/reader.cpp

CMakeFiles/etakeyboard.dir/reader.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/etakeyboard.dir/reader.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/can/projects/etaKeyboard/reader.cpp > CMakeFiles/etakeyboard.dir/reader.i

CMakeFiles/etakeyboard.dir/reader.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/etakeyboard.dir/reader.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/can/projects/etaKeyboard/reader.cpp -o CMakeFiles/etakeyboard.dir/reader.s

CMakeFiles/etakeyboard.dir/reader.o.requires:
.PHONY : CMakeFiles/etakeyboard.dir/reader.o.requires

CMakeFiles/etakeyboard.dir/reader.o.provides: CMakeFiles/etakeyboard.dir/reader.o.requires
	$(MAKE) -f CMakeFiles/etakeyboard.dir/build.make CMakeFiles/etakeyboard.dir/reader.o.provides.build
.PHONY : CMakeFiles/etakeyboard.dir/reader.o.provides

CMakeFiles/etakeyboard.dir/reader.o.provides.build: CMakeFiles/etakeyboard.dir/reader.o

CMakeFiles/etakeyboard.dir/etaKeyboard.o: CMakeFiles/etakeyboard.dir/flags.make
CMakeFiles/etakeyboard.dir/etaKeyboard.o: ../etaKeyboard.cpp
CMakeFiles/etakeyboard.dir/etaKeyboard.o: etaKeyboard.moc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/can/projects/etaKeyboard/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/etakeyboard.dir/etaKeyboard.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/etakeyboard.dir/etaKeyboard.o -c /home/can/projects/etaKeyboard/etaKeyboard.cpp

CMakeFiles/etakeyboard.dir/etaKeyboard.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/etakeyboard.dir/etaKeyboard.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/can/projects/etaKeyboard/etaKeyboard.cpp > CMakeFiles/etakeyboard.dir/etaKeyboard.i

CMakeFiles/etakeyboard.dir/etaKeyboard.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/etakeyboard.dir/etaKeyboard.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/can/projects/etaKeyboard/etaKeyboard.cpp -o CMakeFiles/etakeyboard.dir/etaKeyboard.s

CMakeFiles/etakeyboard.dir/etaKeyboard.o.requires:
.PHONY : CMakeFiles/etakeyboard.dir/etaKeyboard.o.requires

CMakeFiles/etakeyboard.dir/etaKeyboard.o.provides: CMakeFiles/etakeyboard.dir/etaKeyboard.o.requires
	$(MAKE) -f CMakeFiles/etakeyboard.dir/build.make CMakeFiles/etakeyboard.dir/etaKeyboard.o.provides.build
.PHONY : CMakeFiles/etakeyboard.dir/etaKeyboard.o.provides

CMakeFiles/etakeyboard.dir/etaKeyboard.o.provides.build: CMakeFiles/etakeyboard.dir/etaKeyboard.o

CMakeFiles/etakeyboard.dir/main.o: CMakeFiles/etakeyboard.dir/flags.make
CMakeFiles/etakeyboard.dir/main.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/can/projects/etaKeyboard/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/etakeyboard.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/etakeyboard.dir/main.o -c /home/can/projects/etaKeyboard/main.cpp

CMakeFiles/etakeyboard.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/etakeyboard.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/can/projects/etaKeyboard/main.cpp > CMakeFiles/etakeyboard.dir/main.i

CMakeFiles/etakeyboard.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/etakeyboard.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/can/projects/etaKeyboard/main.cpp -o CMakeFiles/etakeyboard.dir/main.s

CMakeFiles/etakeyboard.dir/main.o.requires:
.PHONY : CMakeFiles/etakeyboard.dir/main.o.requires

CMakeFiles/etakeyboard.dir/main.o.provides: CMakeFiles/etakeyboard.dir/main.o.requires
	$(MAKE) -f CMakeFiles/etakeyboard.dir/build.make CMakeFiles/etakeyboard.dir/main.o.provides.build
.PHONY : CMakeFiles/etakeyboard.dir/main.o.provides

CMakeFiles/etakeyboard.dir/main.o.provides.build: CMakeFiles/etakeyboard.dir/main.o

# Object files for target etakeyboard
etakeyboard_OBJECTS = \
"CMakeFiles/etakeyboard.dir/reader.o" \
"CMakeFiles/etakeyboard.dir/etaKeyboard.o" \
"CMakeFiles/etakeyboard.dir/main.o"

# External object files for target etakeyboard
etakeyboard_EXTERNAL_OBJECTS =

etakeyboard: CMakeFiles/etakeyboard.dir/reader.o
etakeyboard: CMakeFiles/etakeyboard.dir/etaKeyboard.o
etakeyboard: CMakeFiles/etakeyboard.dir/main.o
etakeyboard: CMakeFiles/etakeyboard.dir/build.make
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtCore.so
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtGui.so
etakeyboard: /usr/lib/libkdeui.so.5.14.2
etakeyboard: /usr/lib/x86_64-linux-gnu/libXtst.so
etakeyboard: /usr/lib/x86_64-linux-gnu/libX11.so
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtGui.so
etakeyboard: /usr/lib/libkdecore.so.5.14.2
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtCore.so
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtDBus.so
etakeyboard: /usr/lib/x86_64-linux-gnu/libQtSvg.so
etakeyboard: CMakeFiles/etakeyboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable etakeyboard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/etakeyboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/etakeyboard.dir/build: etakeyboard
.PHONY : CMakeFiles/etakeyboard.dir/build

CMakeFiles/etakeyboard.dir/requires: CMakeFiles/etakeyboard.dir/reader.o.requires
CMakeFiles/etakeyboard.dir/requires: CMakeFiles/etakeyboard.dir/etaKeyboard.o.requires
CMakeFiles/etakeyboard.dir/requires: CMakeFiles/etakeyboard.dir/main.o.requires
.PHONY : CMakeFiles/etakeyboard.dir/requires

CMakeFiles/etakeyboard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/etakeyboard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/etakeyboard.dir/clean

CMakeFiles/etakeyboard.dir/depend: reader.moc
CMakeFiles/etakeyboard.dir/depend: etaKeyboard.moc
	cd /home/can/projects/etaKeyboard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/can/projects/etaKeyboard /home/can/projects/etaKeyboard /home/can/projects/etaKeyboard/build /home/can/projects/etaKeyboard/build /home/can/projects/etaKeyboard/build/CMakeFiles/etakeyboard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/etakeyboard.dir/depend

