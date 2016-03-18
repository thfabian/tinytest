#      _   _             _            _
#     | | (_)           | |          | |
#     | |_ _ _ __  _   _| |_ ___  ___| |_
#     | __| | '_ \| | | | __/ _ \/ __| __|
#     | |_| | | | | |_| | ||  __/\__ \ |_
#      \__|_|_| |_|\__, |\__\___||___/\__|  - tinytest 0.0.1
#                   __/ |
#                  |___/
# 
#   This file is part of tinytest, a simple C testing framework.
# 
#   Copyright (c) 2016 Fabian Thuring
# 
#   tinytest is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License Version 3
#   as published by the Free Software Foundation.
# 
#   tinytest is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
# 
#   You should have received a copy of the GNU General Public License
#   along with this program. If not, see <http://www.gnu.org/licenses/>.
#
cmake_minimum_required(VERSION 2.8)
project(tinytest)

if(NOT(CMAKE_MAJOR_VERSION LESS 3) AND NOT(CMAKE_MINOR_VERSION LESS 2))
    cmake_policy(SET CMP0054 OLD)
endif()

option(TINYTEST_TEST "Build unit tests" OFF)

################################################################################
# Compiler Flags
################################################################################
if(NOT(${CMAKE_C_COMPILER_ID} STREQUAL "MSVC"))
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -std=c99")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W3")
endif()

################################################################################
# CMake options
################################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "Choose the type of build, options are: Debug Release" FORCE)
    message(STATUS "Setting build type to 'Release' as none was specified.")
endif(NOT CMAKE_BUILD_TYPE)
                     
################################################################################
# Compilation (only needed for tests)
################################################################################
     
include_directories(${PROJECT_SOURCE_DIR})
set(TINYTEST_HEADER "${PROJECT_SOURCE_DIR}/tinytest.h")

if(TINYTEST_TEST)
    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/travis.sh
         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif(TINYTEST_TEST)

################################################################################
# Installation
################################################################################
install(FILES ${TINYTEST_HEADER} DESTINATION include)

