cmake_minimum_required(VERSION 2.8)
project(AuraServer CXX)

# -[ VSCode building and completion
include(CMakeToolsHelpers OPTIONAL)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/deps/Shinzui/cmake-utils)

# -[ Macros
include(Macros)
include(Configure)
include(External)
ResetAllTargets()


# -[ Configuring
option(AuraServer_BUILD_TESTS     "Build server tests"        ON)
option(AuraServer_DEBUG           "Build with debug mode"     OFF)

# -[ Build type
set(BUILD_TYPE_STR "Choose the type of
    build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug
    Release RelWithDebInfo MinSizeRel.")

if (AuraServer_DEBUG)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING ${BUILD_TYPE_STR} FORCE)
elseif (CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING ${BUILD_TYPE_STR} FORCE)
else ()
    # Should we force Release?
    set(CMAKE_BUILD_TYPE Release CACHE STRING ${BUILD_TYPE_STR} FORCE)
endif()

message("Building with: ${CMAKE_BUILD_TYPE}")

# -[ C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# -[ Subdirectories
add_subdirectory(deps)
add_subdirectory(src)
