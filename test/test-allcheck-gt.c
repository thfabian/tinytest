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

/* ----------------------------------------- Integer -------------------------------------------- */

#define MALLOC_ARRAY(N) (int*) malloc((N) * sizeof(int))

 TEST_CASE(AllCheckGreaterThanInteger_Small)
{
    const int N = 3;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    ALLCHECK_GT_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanInteger_Large)
{
    const int N = 1024;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    ALLCHECK_GT_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanInteger_Array)
{
    int aa[] = {4, 5, 6}; 
    int bb[] = {1, 2, 3};

    ALLCHECK_GT_INTEGER(aa, bb, 3);
}

TEST_CASE(AllCheckGreaterThanInteger_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    aa[N/4] = aa[N/2] = -1;
    bb[N/2] = bb[N/4] = -1;

    ALLCHECK_GT_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

/* ----------------------------------------- Unsigned ------------------------------------------- */

#define MALLOC_ARRAY(N) (unsigned*) malloc((N) * sizeof(unsigned))

 TEST_CASE(AllCheckGreaterThanUnsigned_Small)
{
    const unsigned N = 3;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    ALLCHECK_GT_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanUnsigned_Large)
{
    const unsigned N = 1024;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    ALLCHECK_GT_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanUnsigned_Array)
{
    unsigned aa[] = {4, 5, 6}; 
    unsigned bb[] = {1, 2, 3};

    ALLCHECK_GT_UNSIGNED(aa, bb, 3);
}

TEST_CASE(AllCheckGreaterThanUnsigned_Fails)
{
#ifdef TEST_FAILS
    const unsigned N = 1024;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
    {
        aa[i] = i + 1;
        bb[i] = i;
    }

    aa[N/4] = aa[N/2] = -1;
    bb[N/2] = bb[N/4] = -1;

    ALLCHECK_GT_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

/* ----------------------------------------- Double --------------------------------------------- */

#define MALLOC_ARRAY(N) (double*) malloc((N) * sizeof(double))

 TEST_CASE(AllCheckGreaterThanDouble_Small)
{
    const int N = 3;
    
    double* aa = MALLOC_ARRAY(N);
    double* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = (double) i + 0.1;
        bb[i] = (double) i;
    }

    ALLCHECK_GT_DOUBLE(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanDouble_Large)
{
    const int N = 1024;
    
    double* aa = MALLOC_ARRAY(N);
    double* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = (double) i + 0.1;
        bb[i] = (double) i;
    }
    

    ALLCHECK_GT_DOUBLE(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanDouble_Array)
{
    double aa[] = {4, 5, 6};
    double bb[] = {1, 2, 3}; 

    ALLCHECK_GT_DOUBLE(aa, bb, 3);
}

TEST_CASE(AllCheckGreaterThanDouble_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    double* aa = MALLOC_ARRAY(N);
    double* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = i + 0.1;
        bb[i] = i;
    }

    aa[N/4] = aa[N/2] = -1;
    bb[N/2] = bb[N/4] = -1;

    ALLCHECK_GT_DOUBLE(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

/* ----------------------------------------- Float ---------------------------------------------- */

#define MALLOC_ARRAY(N) (float*) malloc((N) * sizeof(float))

 TEST_CASE(AllCheckGreaterThanFloat_Small)
{
    const int N = 3;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = (float) i + 0.1f;
        bb[i] = (float) i;
    }

    ALLCHECK_GT_FLOAT(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanFloat_Large)
{
    const int N = 1024;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = (float) i + 0.1f;
        bb[i] = (float) i;
    }

    ALLCHECK_GT_FLOAT(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckGreaterThanFloat_Array)
{
    float aa[] = {4, 5, 6}; 
    float bb[] = {1, 2, 3};

    ALLCHECK_GT_FLOAT(aa, bb, 3);
}

TEST_CASE(AllCheckGreaterThanFloat_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    float* aa = MALLOC_ARRAY(N);
    float* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
    {
        aa[i] = (float) i + 0.1f;
        bb[i] = (float) i;
    }

    aa[N/4] = aa[N/2] = -1;
    bb[N/2] = bb[N/4] = -1;

    ALLCHECK_GT_FLOAT(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY
