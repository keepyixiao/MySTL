# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\code\Clion\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\code\Clion\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\C++coding\MySTL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\C++coding\MySTL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\MySTL.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\MySTL.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\MySTL.dir\flags.make

CMakeFiles\MySTL.dir\main.cpp.obj: CMakeFiles\MySTL.dir\flags.make
CMakeFiles\MySTL.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\C++coding\MySTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySTL.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\MySTL.dir\main.cpp.obj /FdCMakeFiles\MySTL.dir\ /FS -c E:\C++coding\MySTL\main.cpp
<<

CMakeFiles\MySTL.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySTL.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\MySTL.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\C++coding\MySTL\main.cpp
<<

CMakeFiles\MySTL.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySTL.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MySTL.dir\main.cpp.s /c E:\C++coding\MySTL\main.cpp
<<

# Object files for target MySTL
MySTL_OBJECTS = \
"CMakeFiles\MySTL.dir\main.cpp.obj"

# External object files for target MySTL
MySTL_EXTERNAL_OBJECTS =

MySTL.exe: CMakeFiles\MySTL.dir\main.cpp.obj
MySTL.exe: CMakeFiles\MySTL.dir\build.make
MySTL.exe: CMakeFiles\MySTL.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\C++coding\MySTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MySTL.exe"
	"D:\code\Clion\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\MySTL.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\MySTL.dir\objects1.rsp @<<
 /out:MySTL.exe /implib:MySTL.lib /pdb:E:\C++coding\MySTL\cmake-build-debug\MySTL.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\MySTL.dir\build: MySTL.exe

.PHONY : CMakeFiles\MySTL.dir\build

CMakeFiles\MySTL.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MySTL.dir\cmake_clean.cmake
.PHONY : CMakeFiles\MySTL.dir\clean

CMakeFiles\MySTL.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\C++coding\MySTL E:\C++coding\MySTL E:\C++coding\MySTL\cmake-build-debug E:\C++coding\MySTL\cmake-build-debug E:\C++coding\MySTL\cmake-build-debug\CMakeFiles\MySTL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\MySTL.dir\depend
