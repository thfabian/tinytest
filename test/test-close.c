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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

TEST_CASE(CloseDouble)
{
    double a = 5.0;
    double b = 5.00001;
    
    CLOSE_DOUBLE(a, b, 1e-4);
}

TEST_CASE(CloseFloat)
{
    float a = 5.0f;
    float b = 5.00001f;
    
    CLOSE_FLOAT(a, b, 1e-4f);
}

TEST_CASE(CloseDouble_Fails)
{
#ifdef TEST_FAILS
    double arg1 = 5.0;
    double arg2 = 5.00001;
    
    CLOSE_DOUBLE(arg1, arg2, 1e-6);
#endif
}

TEST_CASE(CloseFloat_Fails)
{
#ifdef TEST_FAILS
    float arg1 = 5.0f;
    float arg2 = 5.00001f;
    
    CLOSE_DOUBLE(arg1, arg2, 1e-6f);
#endif
}

