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

    /* test-allcheck-eq.c */
    REGISTER_TEST_CASE(AllCheckEqualInteger_Small);
    REGISTER_TEST_CASE(AllCheckEqualInteger_Large);
    REGISTER_TEST_CASE(AllCheckEqualInteger_Array);
    REGISTER_TEST_CASE(AllCheckEqualInteger_Fails);
    REGISTER_TEST_CASE(AllCheckEqualUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckEqualUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckEqualUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckEqualUnsigned_Fails);

    /* test-allcheck-ne.c */
    REGISTER_TEST_CASE(AllCheckNotEqualInteger_Small);
    REGISTER_TEST_CASE(AllCheckNotEqualInteger_Large);
    REGISTER_TEST_CASE(AllCheckNotEqualInteger_Array);
    REGISTER_TEST_CASE(AllCheckNotEqualInteger_Fails);
    REGISTER_TEST_CASE(AllCheckNotEqualUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckNotEqualUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckNotEqualUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckNotEqualUnsigned_Fails);
    REGISTER_TEST_CASE(AllCheckNotEqualDouble_Small);
    REGISTER_TEST_CASE(AllCheckNotEqualDouble_Large);
    REGISTER_TEST_CASE(AllCheckNotEqualDouble_Array);
    REGISTER_TEST_CASE(AllCheckNotEqualDouble_Fails);
    REGISTER_TEST_CASE(AllCheckNotEqualFloat_Small);
    REGISTER_TEST_CASE(AllCheckNotEqualFloat_Large);
    REGISTER_TEST_CASE(AllCheckNotEqualFloat_Array);
    REGISTER_TEST_CASE(AllCheckNotEqualFloat_Fails);
    
    /* test-allcheck-gt.c */
    REGISTER_TEST_CASE(AllCheckGreaterThanInteger_Small);
    REGISTER_TEST_CASE(AllCheckGreaterThanInteger_Large);
    REGISTER_TEST_CASE(AllCheckGreaterThanInteger_Array);
    REGISTER_TEST_CASE(AllCheckGreaterThanInteger_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterThanUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckGreaterThanUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckGreaterThanUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckGreaterThanUnsigned_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterThanDouble_Small);
    REGISTER_TEST_CASE(AllCheckGreaterThanDouble_Large);
    REGISTER_TEST_CASE(AllCheckGreaterThanDouble_Array);
    REGISTER_TEST_CASE(AllCheckGreaterThanDouble_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterThanFloat_Small);
    REGISTER_TEST_CASE(AllCheckGreaterThanFloat_Large);
    REGISTER_TEST_CASE(AllCheckGreaterThanFloat_Array);
    REGISTER_TEST_CASE(AllCheckGreaterThanFloat_Fails);
    
    /* test-allcheck-ge.c */
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanInteger_Small);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanInteger_Large);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanInteger_Array);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanInteger_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanUnsigned_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanDouble_Small);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanDouble_Large);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanDouble_Array);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanDouble_Fails);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanFloat_Small);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanFloat_Large);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanFloat_Array);
    REGISTER_TEST_CASE(AllCheckGreaterEqualThanFloat_Fails);
    
    /* test-allcheck-lt.c */
    REGISTER_TEST_CASE(AllCheckLesserThanInteger_Small);
    REGISTER_TEST_CASE(AllCheckLesserThanInteger_Large);
    REGISTER_TEST_CASE(AllCheckLesserThanInteger_Array);
    REGISTER_TEST_CASE(AllCheckLesserThanInteger_Fails);
    REGISTER_TEST_CASE(AllCheckLesserThanUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckLesserThanUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckLesserThanUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckLesserThanUnsigned_Fails);
    REGISTER_TEST_CASE(AllCheckLesserThanDouble_Small);
    REGISTER_TEST_CASE(AllCheckLesserThanDouble_Large);
    REGISTER_TEST_CASE(AllCheckLesserThanDouble_Array);
    REGISTER_TEST_CASE(AllCheckLesserThanDouble_Fails);
    REGISTER_TEST_CASE(AllCheckLesserThanFloat_Small);
    REGISTER_TEST_CASE(AllCheckLesserThanFloat_Large);
    REGISTER_TEST_CASE(AllCheckLesserThanFloat_Array);
    REGISTER_TEST_CASE(AllCheckLesserThanFloat_Fails);
    
    /* test-allcheck-le.c */
    REGISTER_TEST_CASE(AllCheckLesserEqualThanInteger_Small);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanInteger_Large);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanInteger_Array);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanInteger_Fails);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanUnsigned_Small);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanUnsigned_Large);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanUnsigned_Array);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanUnsigned_Fails);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanDouble_Small);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanDouble_Large);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanDouble_Array);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanDouble_Fails);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanFloat_Small);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanFloat_Large);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanFloat_Array);
    REGISTER_TEST_CASE(AllCheckLesserEqualThanFloat_Fails);

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

    /* test-main-arg.c */
    REGISTER_TEST_CASE(MainArg_Check);
    REGISTER_TEST_CASE(MainArg_Fails);

    int ret = tinytest_run();
    tinytest_free();
    
    return ret;
}
