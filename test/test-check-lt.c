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
 
#include "tinytest.h"
#include <stdio.h>
#include <stdlib.h>

TEST_CASE(CheckLesserThanDouble)
{
    double arg1 = 4.0;
    double arg2 = 5.0;
    CHECK_LT_DOUBLE(arg1, arg2);
}

TEST_CASE(CheckLesserThanDoubleFails)
{
#ifdef TEST_FAILS
    double arg1 = 6.0;
    double arg2 = 5.1;
    CHECK_LT_DOUBLE(arg1, arg2);
#endif
}

TEST_CASE(CheckLesserThanFloat)
{
    float arg1 = 4.0f;
    float arg2 = 5.0f;
    CHECK_LT_FLOAT(arg1, arg2);
}

TEST_CASE(CheckLesserThanFloatFails)
{
#ifdef TEST_FAILS
    float arg1 = 6.0f;
    float arg2 = 5.1f;
    CHECK_LT_FLOAT(arg1, arg2);
#endif
}

TEST_CASE(CheckLesserThanInteger)
{
    int arg1 = 3;
    int arg2 = 5;
    CHECK_LT_INTEGER(arg1, arg2);
}

TEST_CASE(CheckLesserThanIntegerFails)
{
#ifdef TEST_FAILS
    int arg1 = 5;
    int arg2 = 5;
    CHECK_LT_INTEGER(arg1, arg2);
#endif
}

TEST_CASE(CheckLesserThanUnsigned)
{
    unsigned arg1 = 3;
    unsigned arg2 = 5;
    CHECK_LT_UNSIGNED(arg1, arg2);
}

TEST_CASE(CheckLesserThanUnsignedFails)
{
#ifdef TEST_FAILS
    unsigned arg1 = 5;
    unsigned arg2 = 5;
    CHECK_LT_UNSIGNED(arg1, arg2);
#endif
}
