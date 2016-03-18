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

#define MALLOC_ARRAY(N) (int*) malloc((N) * sizeof(int))

 TEST_CASE(AllequalInteger_Small)
{
    const int N = 3;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLEQUAL_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllequalInteger_Large)
{
    const int N = 1024;
    
    int* aa = MALLOC_ARRAY(N);
    int* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = rand();

    ALLEQUAL_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
}

TEST_CASE(AllequalInteger_Array)
{
    int aa[] = {1, 2, 3}; 
    int bb[] = {1, 2, 3};

    ALLEQUAL_INTEGER(aa, bb, 3);
}

TEST_CASE(AllequalInteger_Fails)
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

    ALLEQUAL_INTEGER(aa, bb, N);
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY
