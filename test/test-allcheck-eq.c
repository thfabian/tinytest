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

/* ----------------------------------------- Integer -------------------------------------------- */

#define MALLOC_ARRAY(N) (int*) malloc((N) * sizeof(int))

 TEST_CASE(AllCheckEqualInteger_Small)
{
    const int N = 3;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLCHECK_EQ_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckEqualInteger_Large)
{
    const int N = 1024;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLCHECK_EQ_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckEqualInteger_Array)
{
    int aa[] = {1, 2, 3}; 
    int bb[] = {1, 2, 3};

    ALLCHECK_EQ_INTEGER(aa, bb, 3);
}

TEST_CASE(AllCheckEqualInteger_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();
    
    /* Trigger failure */
    aa[N/2] = -1;
    aa[N/4] = -1;

    ALLCHECK_EQ_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

/* ----------------------------------------- Unsigned ------------------------------------------- */

#define MALLOC_ARRAY(N) (unsigned*) malloc((N) * sizeof(unsigned))

 TEST_CASE(AllCheckEqualUnsigned_Small)
{
    const unsigned N = 3;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLCHECK_EQ_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckEqualUnsigned_Large)
{
    const unsigned N = 1024;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLCHECK_EQ_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllCheckEqualUnsigned_Array)
{
    unsigned aa[] = {1, 2, 3}; 
    unsigned bb[] = {1, 2, 3};

    ALLCHECK_EQ_UNSIGNED(aa, bb, 3);
}

TEST_CASE(AllCheckEqualUnsigned_Fails)
{
#ifdef TEST_FAILS
    const unsigned N = 1024;
    
    unsigned* aa = MALLOC_ARRAY(N);
    unsigned* bb = MALLOC_ARRAY(N);
    
    for(unsigned i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();
    
    /* Trigger failure */
    aa[N/2] = (unsigned) -1;
    aa[N/4] = (unsigned) -1;

    ALLCHECK_EQ_UNSIGNED(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

