/**
 *     _   _             _            _
 *    | | (_)           | |          | |
 *    | |_ _ _ __  _   _| |_ ___  ___| |_
 *    | __| | '_ \| | | | __/ _ \/ __| __|
 *    | |_| | | | | |_| | ||  __/\__ \ |_
 *     \__|_|_| |_|\__, |\__\___||___/\__|  - tinytest 0.0.1
 *                  __/ |
 *                 |___/
 *
 *  This file is part of tinytest, a simple C testing framework.
 *
 *  Copyright (c) 2016 Fabian Thuring
 *
 *  tinytest is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License Version 3
 *  as published by the Free Software Foundation.
 *
 *  tinytest is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define TINYTEST_MAIN
#include "tinytest.h"

#include <stdio.h>
#include <stdlib.h>

TEST_CASE(SameFileTest)
{
    int one = 1;
    int two = 2;
    CHECK(one <= two);
    CHECK(one != two);
}
    
int main(int argc, char* argv[])
{
    tinytest_init(argc, argv);
    tinytest_initSignal();
    
    srand(42);
    
    /* main.c */
    REGISTER_TEST_CASE(SameFileTest);
    
    /* test-allclose-double.c */
    REGISTER_TEST_CASE(AllcloseDouble_Small);
    REGISTER_TEST_CASE(AllcloseDouble_Large);
    REGISTER_TEST_CASE(AllcloseDouble_Array);
    REGISTER_TEST_CASE(AllcloseDouble_Infinity);
    REGISTER_TEST_CASE(AllcloseDouble_Fails);
    
    /* test-allclose-float.c */
    REGISTER_TEST_CASE(AllcloseFloat_Small);
    REGISTER_TEST_CASE(AllcloseFloat_Large);
    REGISTER_TEST_CASE(AllcloseFloat_Array);
    REGISTER_TEST_CASE(AllcloseFloat_Infinity);
    REGISTER_TEST_CASE(AllcloseFloat_Fails);
    
    /* test-allequal-integer.c */
    REGISTER_TEST_CASE(AllequalInteger_Small);
    REGISTER_TEST_CASE(AllequalInteger_Large);
    REGISTER_TEST_CASE(AllequalInteger_Array);
    REGISTER_TEST_CASE(AllequalInteger_Fails);    
    
    /* test-allequal-unsigned.c */
    REGISTER_TEST_CASE(AllequalUnsigned_Small);
    REGISTER_TEST_CASE(AllequalUnsigned_Large);
    REGISTER_TEST_CASE(AllequalUnsigned_Array);
    REGISTER_TEST_CASE(AllequalUnsigned_Fails);
    
    /* test-main-arg.c */
    REGISTER_TEST_CASE(MainArg_Check);
    REGISTER_TEST_CASE(MainArg_Fails);
    
    /* test-segfault.c */
    REGISTER_TEST_CASE(Segfault_Check);
    REGISTER_TEST_CASE(Segfault_Allclose);
    REGISTER_TEST_CASE(Segfault_Allequal);
  
    tinytest_run();
    tinytest_free();
    return 0;
}
