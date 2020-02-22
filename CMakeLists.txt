cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(HelloLunch)

include(CheckCXXCompilerFlag)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)

if(NOT CS_PATH STREQUAL "")
    #include_directories("${CS_PATH}/include")
    #link_directories("${CS_PATH}/lib")
    set(CopperSpice_DIR "${CS_PATH}/lib/cmake/CopperSpice")
endif()

find_package(CopperSpice REQUIRED)

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

#SET(CMAKE_BUILD_RPATH "${CS_PATH}/lib")

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

# don't add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

set(CMAKE_MACOSX_RPATH 1)
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    include(GNUInstallDirs)
    set(CMAKE_INSTALL_RPATH "@executable_path")
elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
    include(GNUInstallDirs)
    set(CMAKE_INSTALL_RPATH "\$ORIGIN")
elseif(MSVC)
    # use defaults
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
    include(${CopperSpice_DIR}/InstallMinGW.cmake)
endif()


set(PACKAGE "HelloCopperSpice")
set(PACKAGE_NAME "HelloCopperSpice")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# location for building binary files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)