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

set(TINYTEST_SOURCE
    main.c
    test-allclose-double.c
    test-allclose-float.c
    test-allequal-integer.c
    test-allequal-unsigned.c
    test-main-arg.c
    test-segfault.c
)

add_executable(tinytest_pass ${TINYTEST_SOURCE})
add_executable(tinytest_fails ${TINYTEST_SOURCE})
add_executable(tinytest_signal ${TINYTEST_SOURCE})

set_target_properties(tinytest_fails  PROPERTIES COMPILE_FLAGS "-DTEST_FAILS")
set_target_properties(tinytest_signal PROPERTIES COMPILE_FLAGS "-DTEST_SIGNAL")
