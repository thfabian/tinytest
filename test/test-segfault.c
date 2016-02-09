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

#ifdef TINYTEST_PLATFORM_POSIX
#include <signal.h>
#endif

#define MALLOC_ARRAY_D(N) (double*) malloc((N) * sizeof(double))
#define MALLOC_ARRAY_I(N) (int*) malloc((N) * sizeof(int))

TEST_CASE(Segfault_Check)
{
#if defined(TEST_SIGNAL) && defined(TINYTEST_PLATFORM_POSIX)
    int* ptr = (int*) 0;
    CHECK((*ptr = 5) == 5);
#endif
}

TEST_CASE(Segfault_Allclose)
{
#if defined(TEST_SIGNAL) && defined(TINYTEST_PLATFORM_POSIX)
    const int N = 3;
    
    double* aa = MALLOC_ARRAY_D(N);
    double* bb = MALLOC_ARRAY_D(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = ((double) rand()) / RAND_MAX;
    
    ALLCLOSE_DOUBLE(aa, bb, 5 * N, 1e-08, 1e-05);
    
    free(aa);
    free(bb);
#endif
}

TEST_CASE(Segfault_Allequal)
{
#if defined(TEST_SIGNAL) && defined(TINYTEST_PLATFORM_POSIX)
    const int N = 3;
    
    int* aa = MALLOC_ARRAY_I(N);
    int* bb = MALLOC_ARRAY_I(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();
    
    ALLEQUAL_INTEGER(aa, bb, 5 * N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY
