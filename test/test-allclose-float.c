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

#define MALLOC_ARRAY(N) (float*) malloc((N) * sizeof(float))

 TEST_CASE(AllcloseFloat_Small)
{
    const int N = 3;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = ((float) rand()) / RAND_MAX;

    ALLCLOSE_FLOAT(aa, bb, N, 1e-08f, 1e-05f);
    ALLCLOSE_FLOAT_3(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllcloseFloat_Large)
{
    const int N = 1024;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = ((float) rand()) / RAND_MAX;

    ALLCLOSE_FLOAT(aa, bb, N, 1e-08f, 1e-05f);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllcloseFloat_Array)
{
    float aa[] = {1, 2, 3}; 
    float bb[] = {1, 2, 3};

    ALLCLOSE_FLOAT(aa, bb, 3, 1e-08f, 1e-05f);
}

TEST_CASE(AllcloseFloat_Infinity)
{
    const int N = 3;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = INFINITY;

    ALLCLOSE_FLOAT(aa, bb, N, 1e-08f, 1e-05f);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllcloseFloat_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = ((float) rand()) / RAND_MAX;
    
    /* Trigger failure */
    aa[N/2] = 2;
    aa[N/4] = 2;
    
    ALLCLOSE_FLOAT(aa, bb, N, 1e-08f, 1e-05f);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY
