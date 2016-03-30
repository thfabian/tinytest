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

TEST_CASE(CustomMsgCheck_Fails)
{
#ifdef TEST_FAILS
    int a = 5;
    int b = 6;
    
    CHECK_MSG(a == b, "a doesn't equal to b");
#endif
}

TEST_CASE(CustomMsgCheckEqual_Fails)
{
#ifdef TEST_FAILS
    int a = 5;
    int b = 6;
    
    CHECK_EQ_INTEGER_MSG(a, b, "a doesn't equal to b");
#endif
}

TEST_CASE(CustomMsgClose_Fails)
{
#ifdef TEST_FAILS
    double a = 5;
    double b = 6;
    
    CLOSE_DOUBLE_MSG(a, b, 1e-05, "a doesn't equal to b");
#endif
}


#define MALLOC_ARRAY(N) (double*) malloc((N) * sizeof(double))

TEST_CASE(CustomMsgAllclose_Fails)
{
#ifdef TEST_FAILS
    const int N = 1024;
    
    double* aa = MALLOC_ARRAY(N);
    double* bb = MALLOC_ARRAY(N);
    
    for(int i = 0; i < N; ++i)
        aa[i] = bb[i] = ((double) rand()) / RAND_MAX;
    
    /* Trigger failure */
    aa[N/2] = 2;
    aa[N/4] = 2;
    
    ALLCLOSE_DOUBLE_MSG(aa, bb, N, 1e-08, 1e-05, "aa is not close to bb");
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

#define MALLOC_ARRAY(N) (int*) malloc((N) * sizeof(int))

TEST_CASE(CustomMsgAllCheckEqualInteger_Fails)
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

    ALLCHECK_EQ_INTEGER_MSG(aa, bb, N, "aa is not equal to bb");
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

#define MALLOC_ARRAY(N) (unsigned*) malloc((N) * sizeof(unsigned))

TEST_CASE(CustomMsgAllCheckEqualUnsigned_Fails)
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

    ALLCHECK_EQ_UNSIGNED_MSG(aa, bb, N, "aa is not equal to bb");
    
    free(aa);
    free(bb);
#endif
}

#undef MALLOC_ARRAY

