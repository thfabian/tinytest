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
    
    srand(42);
    
    /* main.c */
    REGISTER_TEST_CASE(SameFileTest);
    
    /* test-close.c */
    REGISTER_TEST_CASE(CloseDouble);
    REGISTER_TEST_CASE(CloseFloat);
    REGISTER_TEST_CASE(CloseDouble_Fails);
    REGISTER_TEST_CASE(CloseFloat_Fails);

    /* test-check-eq.c */
    REGISTER_TEST_CASE(CheckEqualDouble);
    REGISTER_TEST_CASE(CheckEqualDoubleFails);
    REGISTER_TEST_CASE(CheckEqualFloat);
    REGISTER_TEST_CASE(CheckEqualFloatFails);
    REGISTER_TEST_CASE(CheckEqualInteger);
    REGISTER_TEST_CASE(CheckEqualIntegerFails);
    REGISTER_TEST_CASE(CheckEqualUnsigned);
    REGISTER_TEST_CASE(CheckEqualUnsignedFails);

    /* test-check-ne.c */
    REGISTER_TEST_CASE(CheckNotEqualDouble);
    REGISTER_TEST_CASE(CheckNotEqualDoubleFails);
    REGISTER_TEST_CASE(CheckNotEqualFloat);
    REGISTER_TEST_CASE(CheckNotEqualFloatFails);
    REGISTER_TEST_CASE(CheckNotEqualInteger);
    REGISTER_TEST_CASE(CheckNotEqualIntegerFails);
    REGISTER_TEST_CASE(CheckNotEqualUnsigned);
    REGISTER_TEST_CASE(CheckNotEqualUnsignedFails);

    /* test-check-gt.c */
    REGISTER_TEST_CASE(CheckGreaterThanDouble);
    REGISTER_TEST_CASE(CheckGreaterThanDoubleFails);
    REGISTER_TEST_CASE(CheckGreaterThanFloat);
    REGISTER_TEST_CASE(CheckGreaterThanFloatFails);
    REGISTER_TEST_CASE(CheckGreaterThanInteger);
    REGISTER_TEST_CASE(CheckGreaterThanIntegerFails);
    REGISTER_TEST_CASE(CheckGreaterThanUnsigned);
    REGISTER_TEST_CASE(CheckGreaterThanUnsignedFails);

    /* test-check-ge.c */
    REGISTER_TEST_CASE(CheckGreaterEqualDouble);
    REGISTER_TEST_CASE(CheckGreaterEqualDoubleFails);
    REGISTER_TEST_CASE(CheckGreaterEqualFloat);
    REGISTER_TEST_CASE(CheckGreaterEqualFloatFails);
    REGISTER_TEST_CASE(CheckGreaterEqualInteger);
    REGISTER_TEST_CASE(CheckGreaterEqualIntegerFails);
    REGISTER_TEST_CASE(CheckGreaterEqualUnsigned);
    REGISTER_TEST_CASE(CheckGreaterEqualUnsignedFails);

    /* test-check-lt.c */
    REGISTER_TEST_CASE(CheckLesserThanDouble);
    REGISTER_TEST_CASE(CheckLesserThanDoubleFails);
    REGISTER_TEST_CASE(CheckLesserThanFloat);
    REGISTER_TEST_CASE(CheckLesserThanFloatFails);
    REGISTER_TEST_CASE(CheckLesserThanInteger);
    REGISTER_TEST_CASE(CheckLesserThanIntegerFails);
    REGISTER_TEST_CASE(CheckLesserThanUnsigned);
    REGISTER_TEST_CASE(CheckLesserThanUnsignedFails);
    
    /* test-check-le.c */
    REGISTER_TEST_CASE(CheckLesserEqualDouble);
    REGISTER_TEST_CASE(CheckLesserEqualDoubleFails);
    REGISTER_TEST_CASE(CheckLesserEqualFloat);
    REGISTER_TEST_CASE(CheckLesserEqualFloatFails);
    REGISTER_TEST_CASE(CheckLesserEqualInteger);
    REGISTER_TEST_CASE(CheckLesserEqualIntegerFails);
    REGISTER_TEST_CASE(CheckLesserEqualUnsigned);
    REGISTER_TEST_CASE(CheckLesserEqualUnsignedFails);

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

    int ret = tinytest_run();
    tinytest_free();
    
    return ret;
}
