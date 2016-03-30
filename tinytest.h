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

#ifndef __TINYTEST_H__
#define __TINYTEST_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __clang__
#ifndef __INTEL_COMPILER
#pragma clang system_header
#endif
#elif defined __GNUC__
#pragma GCC system_header
#endif

/**************************************************************************************************\
 * CONFIGURATION
/**************************************************************************************************/

#define TINYTEST_VERSION_MAJOR 0
#define TINYTEST_VERSION_MINOR 0
#define TINYTEST_VERSION_PATCH 2

#if defined(__clang__)
#define TINYTEST_COMPILER_CLANG 1
#endif

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define TINYTEST_COMPILER_INTEL 1
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#define TINYTEST_COMPILER_GNU 1
#endif

#if defined(_MSC_VER)
#define TINYTEST_COMPILER_MSVC 1
#endif

#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)
#define TINYTEST_PLATFORM_WINDOWS 1
#elif defined(__linux__) || defined(__linux)
#define TINYTEST_PLATFORM_LINUX 1
#elif defined(__APPLE__)
#define TINYTEST_PLATFORM_APPLE 1
#endif

#if defined(__unix__) || defined(TINYTEST_PLATFORM_APPLE)
#define TINYTEST_PLATFORM_POSIX 1
#endif

#if defined(TINYTEST_COMPILER_GNU)
#define TINYTEST_NORETURN __attribute__((noreturn))
#elif defined(TINYTEST_COMPILER_MSVC)
#define TINYTEST_NORETURN __declspec(noreturn)
#else
#define TINYTEST_NORETURN
#endif

#if defined(TINYTEST_COMPILER_GNU)
#define TINYTEST_LIKELY(x) __builtin_expect(!!(x), 1)
#define TINYTEST_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define TINYTEST_LIKELY(x) x
#define TINYTEST_UNLIKELY(x) x
#endif

#if defined(TINYTEST_COMPILER_MSVC)
#define TINYTEST_FILENO(fd) _fileno((fd))
#else
#define TINYTEST_FILENO(fd) fileno((fd))
#endif

#define TINYTEST_CONCAT_IMPL(a, b) a##b
#define TINYTEST_CONCAT(a, b) TINYTEST_CONCAT_IMPL(a, b)

#ifndef TINYTEST_DEBUG
#define TINYTEST_DEBUG 0
#endif

#ifndef TINYTEST_VERBOSE
#define TINYTEST_VERBOSE 1
#endif

#ifndef TINYTEST_TERMINAL_WIDTH
#define TINYTEST_TERMINAL_WIDTH 80
#endif

#ifndef TINYTEST_PRINT_ALL
#define TINYTEST_PRINT_ALL 0
#endif

#ifdef TINYTEST_COMPILER_MSVC
#pragma warning(disable : 4113)
#endif

/**************************************************************************************************\
 * MACROS
\**************************************************************************************************/

/**
 * General purpose check
 */
#define TEST_CASE(name) TINYTEST_INTERNAL_TEST_CASE(name)

/**
 * Check if the expression evaluates to true
 */
#define CHECK(expr) TINYTEST_INTERNAL_CHECK(expr)

/**
 * Check if a == b
 */
#define CHECK_EQ_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(==, a, b)
#define CHECK_EQ_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(==, a, b)
#define CHECK_EQ_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(==, a, b)
#define CHECK_EQ_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(==, a, b)

/**
 * Check if a != b
 */
#define CHECK_NE_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(!=, a, b)
#define CHECK_NE_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(!=, a, b)
#define CHECK_NE_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(!=, a, b)
#define CHECK_NE_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(!=, a, b)

/**
 * Check if a < b
 */
#define CHECK_LT_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(<, a, b)
#define CHECK_LT_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(<, a, b)
#define CHECK_LT_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(<, a, b)
#define CHECK_LT_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(<, a, b)

/**
 * Check if a <= b
 */
#define CHECK_LE_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(<=, a, b)
#define CHECK_LE_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(<=, a, b)
#define CHECK_LE_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(<=, a, b)
#define CHECK_LE_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(<=, a, b)

/**
 * Check if a > b
 */
#define CHECK_GT_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(>, a, b)
#define CHECK_GT_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(>, a, b)
#define CHECK_GT_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(>, a, b)
#define CHECK_GT_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(>, a, b)

/**
 * Check if a >= b
 */
#define CHECK_GE_FLOAT(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(>=, a, b)
#define CHECK_GE_DOUBLE(a, b) TINYTEST_INTERNAL_CHECK_X_DOUBLE(>=, a, b)
#define CHECK_GE_INTEGER(a, b) TINYTEST_INTERNAL_CHECK_X_INTEGER(>=, a, b)
#define CHECK_GE_UNSIGNED(a, b) TINYTEST_INTERNAL_CHECK_X_UNSIGNED(>=, a, b)

/**
 * Checks if two doubles are equal within a tolerance
 */
#define CLOSE_DOUBLE(a, b, tol) TINYTEST_INTERNAL_CLOSE(a, b, tol)
#define CLOSE_FLOAT(a, b, tol) TINYTEST_INTERNAL_CLOSE(a, b, tol)

/**
 * Checks if two double arrays are element-wise equal within a tolerance
 */
#define ALLCLOSE_DOUBLE(a, b, N, atol, rtol) TINYTEST_INTERNAL_ALLCLOSE_DOUBLE(a, b, N, atol, rtol)
#define ALLCLOSE_DOUBLE_3(a, b, N) TINYTEST_INTERNAL_ALLCLOSE_DOUBLE(a, b, N, 1e-08, 1e-05)

/**
 * Checks if two float arrays are element-wise equal within a tolerance
 */
#define ALLCLOSE_FLOAT(a, b, N, atol, rtol) TINYTEST_INTERNAL_ALLCLOSE_FLOAT(a, b, N, atol, rtol)
#define ALLCLOSE_FLOAT_3(a, b, N) TINYTEST_INTERNAL_ALLCLOSE_FLOAT(a, b, N, 1e-08f, 1e-05f)

/**
 * Check for every element: a[i] == b[i]
 */
#define ALLCHECK_EQ_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(==, a, b, N)
#define ALLCHECK_EQ_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(==, a, b, N)

/**
 * Check for every element: a[i] != b[i]
 */
#define ALLCHECK_NE_FLOAT(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(!=, a, b, N)
#define ALLCHECK_NE_DOUBLE(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(!=, a, b, N)
#define ALLCHECK_NE_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(!=, a, b, N)
#define ALLCHECK_NE_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(!=, a, b, N)

/**
 * Check for every element: a[i] > b[i]
 */
#define ALLCHECK_GT_FLOAT(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(>, a, b, N)
#define ALLCHECK_GT_DOUBLE(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(>, a, b, N)
#define ALLCHECK_GT_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(>, a, b, N)
#define ALLCHECK_GT_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(>, a, b, N)

/**
 * Check for every element: a[i] >= b[i]
 */
#define ALLCHECK_GE_FLOAT(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(>=, a, b, N)
#define ALLCHECK_GE_DOUBLE(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(>=, a, b, N)
#define ALLCHECK_GE_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(>=, a, b, N)
#define ALLCHECK_GE_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(>=, a, b, N)

/**
 * Check for every element: a[i] < b[i]
 */
#define ALLCHECK_LT_FLOAT(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(<, a, b, N)
#define ALLCHECK_LT_DOUBLE(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(<, a, b, N)
#define ALLCHECK_LT_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(<, a, b, N)
#define ALLCHECK_LT_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(<, a, b, N)

/**
 * Check for every element: a[i] <= b[i]
 */
#define ALLCHECK_LE_FLOAT(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(<=, a, b, N)
#define ALLCHECK_LE_DOUBLE(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(<=, a, b, N)
#define ALLCHECK_LE_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(<=, a, b, N)
#define ALLCHECK_LE_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(<=, a, b, N)

/**
 * @brief Checks if two integer arrays are element-wise equal
 */
#define ALLEQUAL_INTEGER(a, b, N) TINYTEST_INTERNAL_ALLEQUAL_INTEGER(a, b, N)

/**
 * @brief Checks if two unsigned integer arrays are element-wise equal
 */
#define ALLEQUAL_UNSIGNED(a, b, N) TINYTEST_INTERNAL_ALLEQUAL_UNSIGNED(a, b, N)

/* ---------------------------------- Internal macros ------------------------------------------- */

#define TINYTEST_INTERNAL_TEST_CASE(name) void name##__TINY_TEST_CASE__()

/* CHECK */
#define TINYTEST_INTERNAL_CHECK(expr)                                                              \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        (*tinytest_assertCounter_ptr)++;                                                           \
        if(TINYTEST_UNLIKELY((expr) == 0))                                                         \
            tinytest_assertFail(#expr);                                                            \
    } while(tinytest_isSame(0));

#define TINYTEST_INTERNAL_CHECK_X_DOUBLE(CMP, a, b)                                                \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        (*tinytest_assertCounter_ptr)++;                                                           \
        if(TINYTEST_UNLIKELY(!((a) CMP(b))))                                                       \
        {                                                                                          \
            tinytest_assertFail("%s %s %s", #a, #CMP, #b);                                         \
            fprintf(stderr, "with:\n  %s = %f\n  %s = %f\n\n", #a, a, #b, b);                      \
        }                                                                                          \
    } while(tinytest_isSame(0));

#define TINYTEST_INTERNAL_CHECK_X_INTEGER(CMP, a, b)                                               \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        (*tinytest_assertCounter_ptr)++;                                                           \
        if(TINYTEST_UNLIKELY(!((a) CMP(b))))                                                       \
        {                                                                                          \
            tinytest_assertFail("%s %s %s", #a, #CMP, #b);                                         \
            fprintf(stderr, "with:\n  %s = %i\n  %s = %i\n\n", #a, a, #b, b);                      \
        }                                                                                          \
    } while(tinytest_isSame(0));

#define TINYTEST_INTERNAL_CHECK_X_UNSIGNED(CMP, a, b)                                              \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        (*tinytest_assertCounter_ptr)++;                                                           \
        if(TINYTEST_UNLIKELY(!((a) CMP(b))))                                                       \
        {                                                                                          \
            tinytest_assertFail("%s %s %s", #a, #CMP, #b);                                         \
            fprintf(stderr, "with:\n  %s = %u\n  %s = %u\n\n", #a, a, #b, b);                      \
        }                                                                                          \
    } while(tinytest_isSame(0));

/* CLOSE_DOUBLE / CLOSE_FLOAT */
#define TINYTEST_INTERNAL_CLOSE(a, b, tol)                                                         \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        (*tinytest_assertCounter_ptr)++;                                                           \
        if(TINYTEST_UNLIKELY(fabs(a - b) > tol))                                                   \
        {                                                                                          \
            tinytest_assertFail("fabs(%s - %s) <= tol", #a, #b);                                   \
            fprintf(stderr, "with:\n  %s = %f\n  %s = %f\n\n", #a, a, #b, b);                      \
        }                                                                                          \
    } while(tinytest_isSame(0));

/* ALLCLOSE_DOUBLE */
#define TINYTEST_INTERNAL_ALLCLOSE_DOUBLE(a, b, N, atol, rtol)                                     \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        tinytest_allclose_double(a, b, N, atol, rtol, #a, #b);                                     \
    } while(tinytest_isSame(0));

/* ALLCLOSE_FLOAT */
#define TINYTEST_INTERNAL_ALLCLOSE_FLOAT(a, b, N, atol, rtol)                                      \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        tinytest_allclose_float(a, b, N, atol, rtol, #a, #b);                                      \
    } while(tinytest_isSame(0));

/* ALLEQUAL_INTEGER */
#define TINYTEST_INTERNAL_ALLEQUAL_INTEGER(a, b, N)                                                \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        tinytest_allequal_int(a, b, N, #a, #b);                                                    \
    } while(tinytest_isSame(0));

/* ALLEQUAL_UNSIGNED */
#define TINYTEST_INTERNAL_ALLEQUAL_UNSIGNED(a, b, N)                                               \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        (*tinytest_lineInfo_ptr) = li;                                                             \
        tinytest_allequal_unsigned(a, b, N, #a, #b);                                               \
    } while(tinytest_isSame(0));

/* ALLCHECK_X_DOUBLE */
#define TINYTEST_INTERNAL_ALLCHECK_X_DOUBLE(CMP, a, b, N)                                          \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        int numError = 0;                                                                          \
        int printedHeader = 0;                                                                     \
                                                                                                   \
        for(int i = 0; i < N; ++i)                                                                 \
        {                                                                                          \
            if(TINYTEST_UNLIKELY(!(a[i] CMP b[i])))                                                \
            {                                                                                      \
                if((!numError++) || TINYTEST_PRINT_ALL)                                            \
                {                                                                                  \
                    if(!printedHeader)                                                             \
                    {                                                                              \
                        printedHeader = 1;                                                         \
                        tinytest_printAssertFailHeader();                                          \
                        fprintf(stderr, "%s(%i):", li.file, li.line);                              \
                        tinytest_colorPrintf(stderr, COLOR_RED, " FAILED: \n\n");                  \
                    }                                                                              \
                    tinytest_colorPrintf(stderr, COLOR_YELLOW, "%s[%i] %s %s[%i]\n", #a, i, #CMP,  \
                                         #b, i);                                                   \
                    fprintf(stderr, "\nwith:\n %s[%i] = %f\n  %s[%i] = %f\n\n", #a, i, a[i], #b,   \
                            i, b[i]);                                                              \
                }                                                                                  \
                (*tinytest_assertErrorCounter_ptr)++;                                              \
            }                                                                                      \
        }                                                                                          \
        if((numError > 1) && !TINYTEST_PRINT_ALL)                                                  \
            fprintf(stderr, " ... failed also at %i other positon%s ... \n\n", numError - 1,       \
                    numError == 2 ? "" : "s");                                                     \
        (*tinytest_assertCounter_ptr) += N;                                                        \
        fflush(stderr);                                                                            \
    } while(tinytest_isSame(0));

/* ALLCHECK_X_INTEGER */
#define TINYTEST_INTERNAL_ALLCHECK_X_INTEGER(CMP, a, b, N)                                         \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        int numError = 0;                                                                          \
        int printedHeader = 0;                                                                     \
                                                                                                   \
        for(int i = 0; i < N; ++i)                                                                 \
        {                                                                                          \
            if(TINYTEST_UNLIKELY(!(a[i] CMP b[i])))                                                \
            {                                                                                      \
                if((!numError++) || TINYTEST_PRINT_ALL)                                            \
                {                                                                                  \
                    if(!printedHeader)                                                             \
                    {                                                                              \
                        printedHeader = 1;                                                         \
                        tinytest_printAssertFailHeader();                                          \
                        fprintf(stderr, "%s(%i):", li.file, li.line);                              \
                        tinytest_colorPrintf(stderr, COLOR_RED, " FAILED: \n\n");                  \
                    }                                                                              \
                    tinytest_colorPrintf(stderr, COLOR_YELLOW, "\t%s[%i] %s %s[%i]\n", #a, i, #CMP,\
                                         #b, i);                                                   \
                    fprintf(stderr, "\nwith:\n  %s[%i] = %i\n  %s[%i] = %i\n\n", #a, i, a[i], #b,  \
                            i, b[i]);                                                              \
                }                                                                                  \
                (*tinytest_assertErrorCounter_ptr)++;                                              \
            }                                                                                      \
        }                                                                                          \
        if((numError > 1) && !TINYTEST_PRINT_ALL)                                                  \
            fprintf(stderr, " ... failed also at %i other positon%s ... \n\n", numError - 1,       \
                    numError == 2 ? "" : "s");                                                     \
        (*tinytest_assertCounter_ptr) += N;                                                        \
        fflush(stderr);                                                                            \
    } while(tinytest_isSame(0));

/* ALLCHECK_X_INTEGER */
#define TINYTEST_INTERNAL_ALLCHECK_X_UNSIGNED(CMP, a, b, N)                                        \
    do                                                                                             \
    {                                                                                              \
        tinytest_LineInfo_t li = TINYTEST_LINEINFO;                                                \
        int numError = 0;                                                                          \
        int printedHeader = 0;                                                                     \
                                                                                                   \
        for(unsigned i = 0; i < N; ++i)                                                            \
        {                                                                                          \
            if(TINYTEST_UNLIKELY(!(a[i] CMP b[i])))                                                \
            {                                                                                      \
                if((!numError++) || TINYTEST_PRINT_ALL)                                            \
                {                                                                                  \
                    if(!printedHeader)                                                             \
                    {                                                                              \
                        printedHeader = 1;                                                         \
                        tinytest_printAssertFailHeader();                                          \
                        fprintf(stderr, "%s(%i):", li.file, li.line);                              \
                        tinytest_colorPrintf(stderr, COLOR_RED, " FAILED: \n\n");                  \
                    }                                                                              \
                    tinytest_colorPrintf(stderr, COLOR_YELLOW, "\t%s[%u] %s %s[%u]\n", #a, i, #CMP,\
                                         #b, i);                                                   \
                    fprintf(stderr, "\nwith:\n  %s[%u] = %u\n  %s[%u] = %u\n\n", #a, i, a[i], #b,  \
                            i, b[i]);                                                              \
                }                                                                                  \
                (*tinytest_assertErrorCounter_ptr)++;                                              \
            }                                                                                      \
        }                                                                                          \
        if((numError > 1) && !TINYTEST_PRINT_ALL)                                                  \
            fprintf(stderr, " ... failed also at %i other positon%s ... \n\n", numError - 1,       \
                    numError == 2 ? "" : "s");                                                     \
        (*tinytest_assertCounter_ptr) += N;                                                        \
        fflush(stderr);                                                                            \
    } while(tinytest_isSame(0));

#define REGISTER_TEST_CASE(name) YOU_NEED_TO_DEFINE_TINYTEST_MAIN_BEFORE_INCLUDING_TINYTEST

/**************************************************************************************************\
 * DECLARATION
\**************************************************************************************************/

#include <stdio.h>

/**
 * @brief Number of assertions
 */
extern int* tinytest_assertCounter_ptr;

/**
 * @brief Number of failed assertions
 */
extern int* tinytest_assertErrorCounter_ptr;

/**
 * @brief Information about the current line in the source code
 */
typedef struct tinytest_LineInfo
{
    const char* file;
    int line;
} tinytest_LineInfo_t;
#define TINYTEST_LINEINFO                                                                          \
    {                                                                                              \
        .file = __FILE__, .line = (int) __LINE__                                                   \
    }

extern tinytest_LineInfo_t* tinytest_lineInfo_ptr;

/**
 * @brief Get parameters passed to main
 *
 * This simply assigns the parameters, hence returns a refrence to the orginal
 * parameters.
 */
extern void tinytest_getMainArg(int* argc, char*** argv);

/**
 * @brief Return input value unmodified
 *
 * This is to avoid compiler warnings with macro constants.
 */
extern int tinytest_isSame(int value);

/**
 * @brief See CHECK
 */
extern void tinytest_assertFail(const char* exprStr, ...);

/**
 * @brief See ALLCLOSE_DOUBLE
 *
 * Relies on global variable: tinytest_lineInfo_ptr
 */
extern void tinytest_allclose_double(const double* a,
                                     const double* b,
                                     const int N,
                                     const double atol,
                                     const double rtol,
                                     const char* aStr,
                                     const char* bStr);
/**
 * @brief See ALLCLOSE_FLOAT
 *
 * Relies on global variable: tinytest_lineInfo_ptr
 */
extern void tinytest_allclose_float(const float* a,
                                    const float* b,
                                    const int N,
                                    const float atol,
                                    const float rtol,
                                    const char* aStr,
                                    const char* bStr);

/**
 * Colors
 */
typedef enum tinytest_Color
{
    COLOR_DEFAULT,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW
} tinytest_Color_t;

/**
 * Colored printf (internal function)
 */
extern void tinytest_colorPrintf(FILE* stream, tinytest_Color_t color, const char* fmt, ...);

/**
 * Print a header for an assertion (internal function)
 */
extern void tinytest_printAssertFailHeader();

/**************************************************************************************************\
 * DEFINITION
\**************************************************************************************************/

#ifdef TINYTEST_MAIN

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef TINYTEST_COMPILER_MSVC
#pragma warning(disable : 4024)
#pragma warning(disable : 4047)
#pragma warning(disable : 4244)
#pragma warning(disable : 4312)
#endif

#ifdef TINYTEST_PLATFORM_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <io.h>
#include <windows.h>

#else /* TINYTEST_PLATFORM_POSIX */
#include <unistd.h>
#endif

#define TINYTEST_FREE(ptr)                                                                         \
    free(ptr);                                                                                     \
    ptr = NULL;

#ifdef REGISTER_TEST_CASE
#undef REGISTER_TEST_CASE
#endif
#define REGISTER_TEST_CASE(name)                                                                   \
    do                                                                                             \
    {                                                                                              \
        void name##__TINY_TEST_CASE__();                                                           \
        tinytest_register(#name, &name##__TINY_TEST_CASE__);                                       \
    } while(tinytest_isSame(0))

typedef void (*tinytest_TestCaseType)(void);

/* Forward declarations */
static TINYTEST_NORETURN void tinytest_fatalError(const char* str);
static void tinytest_init(int argc, char* argv[]);
static void tinytest_free();
static int tinytest_run();
static void tinytest_printBar(FILE* stream, tinytest_Color_t color, int width, int newLine, char c);
static void tinytest_register(const char* name, tinytest_TestCaseType testCase);
static int tinytest_shouldUseColor(int stdout_is_tty);

#ifdef TINYTEST_PLATFORM_WINDOWS
static WORD tinytest_getColorAttribute(tinytest_Color_t color);
#else
static const char* tinytest_getAnsiColorCode(tinytest_Color_t color);
#endif

/* Global variables */
int* tinytest_assertCounter_ptr;
int* tinytest_assertErrorCounter_ptr;
tinytest_LineInfo_t* tinytest_lineInfo_ptr;

/* Static variables */
static int tinytest_isInitialized = 0;
static int tinytest_testCounter = 0;
static int tinytest_testErrorCounter = 0;
static int tinytest_inColorMode = -1;
static int tinytest_currrentFileNo = -1;
static int tinytest_printedHeader = 0;
static const char* tinytest_curTestName;

/**
 * @brief Store parameters passed to main
 */
typedef struct tinytest_MainArg
{
    int argc;
    char** argv;
} tinytest_MainArg_t;

static tinytest_MainArg_t* tinytest_mainArg_ptr;


/**
 * @brief Print a bar of length @c width using character @c c
 */
static void tinytest_printBar(FILE* stream, tinytest_Color_t color, int width, int newLine, char c)
{
    char* bar = (char*) malloc(sizeof(char) * width);
    memset(bar, c, width);
    bar[width - 1] = '\0';
    tinytest_colorPrintf(stream, color, bar);
    if(newLine)
        fputs("\n", stream);
    free(bar);
}

/**
 * @brief Representation of a test case
 */
typedef struct tinytest_TestCaseNode
{
    const char* name;
    tinytest_TestCaseType testCase;
    struct tinytest_TestCaseNode* next;
} tinytest_TestCaseNode_t;

/**
 * @brief List of all registred test cases
 */
typedef struct tinytest_TestCaseList
{
    tinytest_TestCaseNode_t* head;
} tinytest_TestCaseList_t;

static tinytest_TestCaseList_t* tinytest_testCaseList_ptr;

/**
 * @brief Register a test case
 */
static void tinytest_register(const char* name, tinytest_TestCaseType testCase)
{
    if(!tinytest_isInitialized)
        tinytest_fatalError("tinytest error: tinytest is not initialized!\n");

    /* Allocate test case */
    tinytest_TestCaseNode_t* node
        = (tinytest_TestCaseNode_t*) malloc(sizeof(tinytest_TestCaseNode_t));
    node->name = name;
    node->testCase = testCase;
    node->next = NULL;

    /* Register test case */
    tinytest_TestCaseNode_t* curNode = tinytest_testCaseList_ptr->head;
    if(curNode == NULL)
        tinytest_testCaseList_ptr->head = node;
    else
    {
        tinytest_TestCaseNode_t* prev = curNode;
        while(curNode != NULL)
        {
            prev = curNode;
            curNode = curNode->next;
        }
        prev->next = node;
    }

    if(TINYTEST_DEBUG)
        printf("tinytest: registering test case '%s'\n", name);
}


/**
 * @brief Print error string to stderr and exit program with EXIT_FAILURE(1)
 */
static TINYTEST_NORETURN void tinytest_fatalError(const char* str)
{
    if(tinytest_isInitialized)
        tinytest_free();
    fputs(str, stderr);
    fflush(stderr);
    exit(EXIT_FAILURE);
}

/**
 * @brief Initialize the library
 */
static void tinytest_init(int argc, char* argv[])
{
    if(TINYTEST_DEBUG)
        printf("tinytest: allocating memory\n");

    tinytest_assertCounter_ptr = (int*) malloc(sizeof(int));
    tinytest_assertCounter_ptr[0] = 0;

    tinytest_assertErrorCounter_ptr = (int*) malloc(sizeof(int));
    tinytest_assertErrorCounter_ptr[0] = 0;

    tinytest_testErrorCounter = 0;
    tinytest_testCounter = 0;

    /* LineInfo */
    tinytest_lineInfo_ptr = (tinytest_LineInfo_t*) malloc(sizeof(tinytest_LineInfo_t));

    /* TestList */
    tinytest_testCaseList_ptr = (tinytest_TestCaseList_t*) malloc(sizeof(tinytest_TestCaseList_t));
    tinytest_testCaseList_ptr->head = NULL;

    /* MainArg */
    tinytest_mainArg_ptr = (tinytest_MainArg_t*) malloc(sizeof(tinytest_MainArg_t));
    tinytest_mainArg_ptr->argc = argc;
    tinytest_mainArg_ptr->argv = argv;

    tinytest_isInitialized = 1;
}

/**
 * @brief Fee all memory used by the the library
 */
static void tinytest_free()
{
    if(tinytest_isInitialized)
    {
        if(TINYTEST_DEBUG)
            printf("tinytest: freeing memory\n");

        TINYTEST_FREE(tinytest_assertCounter_ptr);
        TINYTEST_FREE(tinytest_assertErrorCounter_ptr);
        TINYTEST_FREE(tinytest_lineInfo_ptr);

        tinytest_TestCaseNode_t* node = tinytest_testCaseList_ptr->head;
        while(node != NULL)
        {
            tinytest_TestCaseNode_t* oldNode = node;
            node = node->next;
            TINYTEST_FREE(oldNode);
        }
        TINYTEST_FREE(tinytest_testCaseList_ptr);
        TINYTEST_FREE(tinytest_mainArg_ptr);
    }
}

/**
 * @brief Run all the registred test cases
 *
 * The final result will be reported to stdout.
 */
static int tinytest_run()
{
    if(!tinytest_isInitialized)
        tinytest_fatalError("tinytest error: tinytest is not initialized!\n");

    /* Run tests */
    tinytest_TestCaseNode_t* node = tinytest_testCaseList_ptr->head;
    while(node != NULL)
    {
        tinytest_curTestName = node->name;
        tinytest_printedHeader = 0;
        tinytest_testCounter++;

        if(TINYTEST_VERBOSE)
            printf("tinytest: running '%s' ...\n", tinytest_curTestName);

        int curError = *tinytest_assertErrorCounter_ptr;
        node->testCase();

        if(*tinytest_assertErrorCounter_ptr > curError)
            tinytest_testErrorCounter++;

        node = node->next;
    }

    /* Report final results */
    if(tinytest_testErrorCounter)
    {
        int redBarWidth
            = tinytest_testErrorCounter / ((float) tinytest_testCounter) * TINYTEST_TERMINAL_WIDTH;
        if(redBarWidth == 0)
            redBarWidth = 1;
        int greenBarWidth = TINYTEST_TERMINAL_WIDTH - redBarWidth;

        tinytest_printBar(stderr, COLOR_RED, redBarWidth + 1, greenBarWidth == 0, '=');

        if(greenBarWidth != 0)
            tinytest_printBar(stderr, COLOR_GREEN, greenBarWidth, 1, '=');

        /* Asserts */
        fprintf(stderr, "assertions:  %6i |", *tinytest_assertCounter_ptr);
        tinytest_colorPrintf(stderr, COLOR_GREEN, "%6i passed",
                             *tinytest_assertCounter_ptr - *tinytest_assertErrorCounter_ptr);
        fputs(" |", stderr);
        tinytest_colorPrintf(stderr, COLOR_RED, "%6i failed\n", *tinytest_assertErrorCounter_ptr);
        /* Test cases */
        fprintf(stderr, "test cases:  %6i |", tinytest_testCounter);
        tinytest_colorPrintf(stderr, COLOR_GREEN, "%6i passed",
                             tinytest_testCounter - tinytest_testErrorCounter);
        fputs(" |", stderr);
        tinytest_colorPrintf(stderr, COLOR_RED, "%6i failed\n", tinytest_testErrorCounter);
    }
    else
    {
        tinytest_printBar(stderr, COLOR_GREEN, TINYTEST_TERMINAL_WIDTH, 1, '=');
        tinytest_colorPrintf(stderr, COLOR_GREEN, "All tests passed ");
        fprintf(stderr, "(%i assertion%s in %i test case%s)\n", *tinytest_assertCounter_ptr,
                *tinytest_assertCounter_ptr > 1 ? "s" : "", tinytest_testCounter,
                tinytest_testCounter > 1 ? "s" : "");
    }
    fflush(stderr);

    return tinytest_testErrorCounter ? 1 : 0;
}

int tinytest_isSame(int value)
{
    return value;
}

void tinytest_getMainArg(int* argc, char*** argv)
{
    *argc = tinytest_mainArg_ptr->argc;
    *argv = tinytest_mainArg_ptr->argv;
}

#ifdef TINYTEST_PLATFORM_WINDOWS

/**
 * @brief Returns the character attribute for the given color
 */
static WORD tinytest_getColorAttribute(tinytest_Color_t color)
{
    switch(color)
    {
        case COLOR_RED:
            return FOREGROUND_RED;
        case COLOR_GREEN:
            return FOREGROUND_GREEN;
        case COLOR_YELLOW:
            return FOREGROUND_RED | FOREGROUND_GREEN;
        default:
            return 0;
    }
}

#else

/**
 * @brief Returns the ANSI color code for the given color
 *
 * COLOR_DEFAULT is an invalid input.
 */
static const char* tinytest_getAnsiColorCode(tinytest_Color_t color)
{
    switch(color)
    {
        case COLOR_RED:
            return "1";
        case COLOR_GREEN:
            return "2";
        case COLOR_YELLOW:
            return "3";
        default:
            return NULL;
    };
}
#endif /* TINYTEST_PLATFORM_WINDOWS */

/**
 * @brief Returns 1 iff tinytest should use colors in the output
 */
int tinytest_shouldUseColor(int stdout_is_tty)
{
#if TINYTEST_PLATFORM_WINDOWS
    return stdout_is_tty;
#else
    const char* const term = getenv("TERM");

    /* It may happen that TERM is undefined, then just cross fingers */
    if(term == NULL)
        return stdout_is_tty;

    const int termSupportsColor
        = (strcmp(term, "xterm") == 0) || (strcmp(term, "xterm-color") == 0)
          || (strcmp(term, "xterm-256color") == 0) || (strcmp(term, "screen") == 0)
          || (strcmp(term, "screen-256color") == 0) || (strcmp(term, "rxvt-unicode") == 0)
          || (strcmp(term, "rxvt-unicode-256color") == 0) || (strcmp(term, "linux") == 0)
          || (strcmp(term, "cygwin") == 0);

    return stdout_is_tty && termSupportsColor;
#endif /* TINYTEST_PLATFORM_WINDOWS */
}

/**
 * @brief Printing colored strings to stdout.
 *
 * This routine will change the color using the Win API on Windows or emitting special characters on
 * other platforms.
 */
void tinytest_colorPrintf(FILE* stream, tinytest_Color_t color, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int fd = TINYTEST_FILENO(stream);

    if(tinytest_inColorMode < 0 || fd != tinytest_currrentFileNo)
    {
#ifdef TINYTEST_PLATFORM_WINDOWS
        tinytest_inColorMode = 1;
        tinytest_currrentFileNo = fd;
#else /* TINYTEST_PLATFORM_POSIX */
        tinytest_inColorMode = tinytest_shouldUseColor(isatty(fd)) != 0;
        tinytest_currrentFileNo = fd;
#endif
    }

    int useColor = tinytest_inColorMode && (color != COLOR_DEFAULT);

#ifdef TINYTEST_NOCOLOR
    useColor = 0;
#endif

    if(!useColor)
    {
        vfprintf(stream, fmt, args);
        va_end(args);
        return;
    }

#ifdef TINYTEST_PLATFORM_WINDOWS
    const HANDLE streamHandle = (HANDLE) _get_osfhandle(TINYTEST_FILENO(stream));

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(streamHandle, &bufferInfo);
    const WORD oldColorAttrs = bufferInfo.wAttributes;

    fflush(stream);
    SetConsoleTextAttribute(streamHandle, tinytest_getColorAttribute(color) | FOREGROUND_INTENSITY);
    vfprintf(stream, fmt, args);

    fflush(stream);
    SetConsoleTextAttribute(streamHandle, oldColorAttrs);

#else /* TINYTEST_PLATFORM_POSIX */
    fprintf(stream, "\033[0;3%sm", tinytest_getAnsiColorCode(color));
    vfprintf(stream, fmt, args);
    fprintf(stream, "\033[m");
#endif

    va_end(args);
}

/**
 * @brief Print information about the current failed testcase
 *
 * Relies on tinytest_lineInfo_ptr
 */
void tinytest_printAssertFailHeader()
{
    if(!tinytest_printedHeader++)
    {
        tinytest_printBar(stderr, COLOR_DEFAULT, TINYTEST_TERMINAL_WIDTH, 1, '-');
        fprintf(stderr, "%s (%s)\n", tinytest_curTestName, tinytest_lineInfo_ptr->file);
        tinytest_printBar(stderr, COLOR_DEFAULT, TINYTEST_TERMINAL_WIDTH, 1, '-');
    }
}

/**
 * @brief Print a failed assertion
 *
 * Relies tinytest_lineInfo_ptr
 */
void tinytest_assertFail(const char* exprStr, ...)
{
    va_list args;
    va_start(args, exprStr);

    (*tinytest_assertErrorCounter_ptr)++;
    tinytest_printAssertFailHeader();

    fprintf(stderr, "%s(%i):", tinytest_lineInfo_ptr->file, tinytest_lineInfo_ptr->line);
    tinytest_colorPrintf(stderr, COLOR_RED, " FAILED: \n\n");

    /* temporarly store the string in a char array to make use of colorPrintf */
    char expr[256];
    vsnprintf(expr, 256, exprStr, args);
    tinytest_colorPrintf(stderr, COLOR_YELLOW, "\t%s\n\n", expr);

    fflush(stderr);
    va_end(args);
}


#define TINYTEST_ALLCLOSE_IMPL(type)                                                               \
void tinytest_allclose_##type(const type* a, const type* b, const int N, const type atol,          \
                              const type rtol, const char* aStr, const char* bStr)                 \
{                                                                                                  \
        tinytest_LineInfo_t li = *tinytest_lineInfo_ptr;                                           \
        int numError = 0;                                                                          \
        int printedHeader = 0;                                                                     \
                                                                                                   \
        int errorUnequal = 0;                                                                      \
        int errorHasNaN = 0;                                                                       \
        int errorHasInf = 0;                                                                       \
        int aIsNaN = 0;                                                                            \
        int bIsNaN = 0;                                                                            \
        int aIsInf = 0;                                                                            \
        int bIsInf = 0;                                                                            \
                                                                                                   \
        for(int i = 0; i < N; ++i)                                                                 \
        {                                                                                          \
            errorUnequal = (fabs(a[i] - b[i]) > (atol + rtol * fabs(b[i])));                       \
            errorHasNaN = ((aIsNaN = isnan(a[i])) || (bIsNaN = isnan(b[i])));                      \
            errorHasInf = ((aIsInf = isinf(a[i])) != (bIsInf = isinf(b[i])));                      \
            if(errorUnequal || errorHasNaN || errorHasInf)                                         \
            {                                                                                      \
                if((!numError++) || TINYTEST_PRINT_ALL)                                            \
                {                                                                                  \
                    if(!printedHeader)                                                             \
                    {                                                                              \
                        printedHeader = 1;                                                         \
                        tinytest_printAssertFailHeader();                                          \
                        fprintf(stderr, "%s(%i):", li.file, li.line);                              \
                        tinytest_colorPrintf(stderr, COLOR_RED, " FAILED: \n\n");                  \
                    }                                                                              \
                                                                                                   \
                    if(errorHasNaN || errorHasInf)                                                 \
                    {                                                                              \
                        tinytest_colorPrintf(stderr, COLOR_YELLOW, "\t%s[%i] != %s[%i]\n", aStr,   \
                                             i, bStr, i);                                          \
                        fputs("\nwith:\n", stderr);                                                \
                        if(aIsInf || aIsNaN)                                                       \
                            fprintf(stderr, "\t%s[%i] = %s\n", aStr, i, aIsInf ? "inf" : "nan");   \
                        else                                                                       \
                            fprintf(stderr, "\t%s[%i] = %f\n\n", aStr, i, a[i]);                   \
                                                                                                   \
                        if(bIsInf || bIsNaN)                                                       \
                            fprintf(stderr, "\t%s[%i] = %s\n\n", bStr, i, bIsInf ? "inf" : "nan"); \
                        else                                                                       \
                            fprintf(stderr, "\t%s[%i] = %f\n\n", bStr, i, b[i]);                   \
                    }                                                                              \
                    else                                                                           \
                    {                                                                              \
                        tinytest_colorPrintf(stderr, COLOR_YELLOW,                                 \
                                             "\tfabs(%s[%i] - %s[%i]) <= (atol + rtol "            \
                                             "* fabs(%s[%i]))\n",                                  \
                                             aStr, i, bStr, i, bStr, i);                           \
                        fprintf(stderr, "\nwith:\n  atol = %3.1e\n  rtol = "                       \
                                        "%3.1e\n  %s[%i] = %f\n  %s[%i] = %f\n\n",                 \
                                atol, rtol, aStr, i, a[i], bStr, i, b[i]);                         \
                    }                                                                              \
                }                                                                                  \
                (*tinytest_assertErrorCounter_ptr)++;                                              \
            }                                                                                      \
        }                                                                                          \
        if((numError > 1) && !TINYTEST_PRINT_ALL)                                                  \
            fprintf(stderr, " ... failed also at %i other positon%s ... \n\n", numError - 1,       \
                    numError == 2 ? "" : "s");                                                     \
        (*tinytest_assertCounter_ptr) += N;                                                        \
        fflush(stderr);                                                                            \
}

TINYTEST_ALLCLOSE_IMPL(double)
TINYTEST_ALLCLOSE_IMPL(float)

#endif /* TINYTEST_MAIN */

#ifdef __cplusplus
}
#endif

#endif /* __TINYTEST_H__ */
