## tinytest - C testing framework (0.0.1) [![Build Status](https://travis-ci.org/thfabian/tinytest.svg?branch=master)](https://travis-ci.org/thfabian/tinytest)

### DESCRIPTION

Tinytest is a header-only, cross-platform, C testing framework. The library is inspired by the excellent C++ testing framework [Catch](https://github.com/philsquared/Catch) as well as Googles testing framework [GTest](https://github.com/google/googletest). 

### BUILD

The library consists of a single header file [tinytest.h](https://github.com/thfabian/tinytest/blob/master/tinytest.h). The intention behind this design is that one file serves as a main file, thus provides all the implementation, while all other files simply define testcases. 

The library should build with every sane C99 conformant compiler on Linux, Mac and Windows. The library was successfully tested with the GNU, Clang, Visual C, PGI and Intel compiler.

### USAGE

The usage of the library is rather straightforward: Define testcases, register them and eventually run them.

##### 1. Define testcases

The process of defining a testcase is encapsulated in a macro:

* `TEST_CASE(name) { ... }` 

	This defines a testcase called `name` and can be seen as a normal function definition. In fact, it defines a function called `void name__TINY_TEST_CASE__(void)`).

The perform the _actual_ testing the library offers several macros:

* `CHECK(expr)` 

	Check if the expression evaluates to true. If the check fails, an error message will be printed to stderr and the execution _continues_. To get better diagnostics, it is advised to use the specialized macros described in the following.

* `CHECK_[OP]_[TYPE](a, b)`

	The available specialization for the `CHECK` macro are:

	| *Assertion* | *Types* | *Verifies* |
|:--------------------|:-------------|:-------------:|
|`CHECK_EQ_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a == b` |
|`CHECK_NE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a != b` |
|`CHECK_GT_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a > b` |
|`CHECK_GE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a >= b` |
|`CHECK_LT_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a < b` |
|`CHECK_LE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a <= b` |

	Note: to compare real numbers within a tolerance, use `CLOSE_DOUBLE(a, b)`. If the check fails, an error message will be printed to stderr and the execution _continues_.
	
* `CLOSE_DOUBLE(a, b, tol)` and `CLOSE_FLOAT(a, b, tol)` 

	Checks if values `a` and `b` equal within a tolerance. The tolerance `tol` is a positive, typically very small double precision number.
	
	<img src="https://raw.githubusercontent.com/thfabian/tinytest/master/doc/close.png" alt="Close"/>
	
	If an assertion fails, an error message will be printed to stderr and the execution _continues_.

* `ALLCHECK_[OP]_[TYPE](a, b, N)` 

	The following macros operator elementwise on the array `a` and `b` of length `N`:

	| *Assertion* | *Types* | *Verifies* |
|:--------------------|:-------------|:-------------:|
|`ALLCHECK_EQ_[TYPE](a, b);`| `INTEGER, UNSIGNED` | `a[i] == b[i]` |
|`ALLCHECK_NE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a[i] != b[i]` |
|`ALLCHECK_GT_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a[i] > b[i]` |
|`ALLCHECK_GE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a[i] >= b[i]` |
|`ALLCHECK_LT_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a[i] < b[i]` |
|`ALLCHECK_LE_[TYPE](a, b);`| `DOUBLE, FLOAT, INTEGER, UNSIGNED` | `a[i] <= b[i]` |

	If an assertion fails, an error message will be printed to stderr and the execution _continues_. Only the _first_ error will create a detailed diagnostic message, to alter this behaviour define `TINYTEST_PRINT_ALL` before including `tinytest.h`. 
	
* `ALLCLOSE_DOUBLE(a, b, N, atol, rtol)` and `ALLCLOSE_FLOAT(a, b, N, atol, rtol)` 


	Checks if two double arrays `a` and `b` of length `N` are _element-wise_ equal within a tolerance. The tolerance values are positive, typically very small double precision numbers. The relative difference (rtol * abs(b)) and the absolute difference atol are added together to compare against the absolute difference between `a` and `b`.

	<img src="https://raw.githubusercontent.com/thfabian/tinytest/master/doc/all_close.png" alt="Allcose"/>
  
	If either array contains one or more NaNs, the check fails. Infs are treated as equal if they are in the same place and of the same sign in both arrays.
  
	If an assertion fails, an error message will be printed to stderr and the execution _continues_. Only the _first_ error will create a detailed diagnostic message, to alter this behaviour define `TINYTEST_PRINT_ALL` before including `tinytest.h`.

	Note: There is a shorhand macro `ALLCLOSE_DOUBLE_3(a, b, N)` which automatically sets `atol = 1e-08` and `rtol = 1e-05`. 


To get access to those macros include `tinytest.h` (this will in addition include `<stdio.h>`).  Further library functions of intrest:

* `tinytest_getMainArg(int* argc, char*** argv)` 

	 Get parameters passed to main and registered by `tinytest_init`. Note that this simply assigns the parameters, hence returns a refrence to the orginal parameters!

##### 2. Resgiter/Run testcases

To run our defined testcases, we have to create a main file and define `TINYTEST_MAIN` before including `tinytest.h`. This will make sure that the implementation is going to be pulled in and further allows us to register testcases. The following methods are of intrest:

* `tinytest_init(int* argc, char*** argv)` 

	Initialize the library by allocating necessary memory. This _needs_ to be called before any other library call.

* `REGISTER_TEST_CASE(name)` 

	Register a testcase, where `name` should be the name of a defined 
testcase. This macro creates a local definition of the test case function which can be picked up by the linker. Testcases can be registered multiple times. 

* `tinytest_run()` 

	Run all the registred test cases and report the results to stdout. The testcases are run in the order in which they were registred. Any failures are being reported to stderr.

* `tinytest_free()` 

	Tear down the library and free all allocated memory.

##### Example

The following example showcases the procedure of defining/registering testcases and running them.

###### test.c

```c++
#include "tinytest.h"

TEST_CASE(MyTest)
{
    /* Simple check */
    int five = 2 + 3;
    CHECK_EQ_INTEGER(five, 5);

    /* Ranged check */
    double a[] = {1, 2, 3}; 
    double b[] = {1, 2, 3};

    ALLCLOSE_DOUBLE( a, b, 3, 1e-08, 1e-05 );
}

```

###### main.c

```c++
#define TINYTEST_MAIN
#include "tinytest.h"

int main(int argc, char* argv[])
{
    tinytest_init(argc, argv);
   
    REGISTER_TEST_CASE(MyTest);
    
    int ret = tinytest_run();
    tinytest_free();
    return ret;
}
```

To compile:

```sh
gcc -c -o test.o test.c 
gcc -c -o main.o main.c
gcc main.o test.o -o test 
```

Note that we could have also defined all the tests in `main.c`.

### LICENSE

#####  GNU GENERAL PUBLIC LICENSE (Version 3)
Copyright (c) 2016 Fabian Thuring

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
