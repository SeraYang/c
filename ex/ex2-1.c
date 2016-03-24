/* Write a program to determine the range of char, short,
 * int, and long variables, both signed and unsigned, by 
 * printing appropriate values from standard headers and
 * by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point 
 * types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define YANG '\013'
#define YI '0XF'
#define FAN '\x1f'

int i;
i = '\054';

main(){

    printf("Variable limits from headers: \n");
    printf("number of bits in byte  [%d] \n",
                CHAR_BIT);
    printf("maximum number of bytes in a multibyte character: [%d] \n", MB_LEN_MAX);
    printf("signed char     [%d, %d] \n",
                SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char   [%d, %d] \n",
                0,UCHAR_MAX);
    printf("char    [%d, %d] \n",
                CHAR_MIN, CHAR_MAX);
    printf("short int       [%hd, %hd] \n",
                SHRT_MIN, SHRT_MAX);
    printf("unsigned short      [%hu, %hu] \n",
                0,USHRT_MAX);
    printf("int         [%d, %d] \n",
                INT_MIN, INT_MAX);
    printf("unsigned int    [%d, %u] \n",
                0, UINT_MAX);
    printf("long int    [%ld, %ld] \n",
                LONG_MIN, LONG_MAX);
    printf("unsigned long   [%d, %lu] \n",
                0, ULONG_MAX);
    printf("long long int   [%lld, %lld] \n",
                LLONG_MIN,LLONG_MAX);
    printf("unsigned long long int   [%d, %llu] \n",
                0,ULLONG_MAX);
    printf("YANG is(this is octal): %d \n", YANG);
    
    printf("i is(this is octal): %o \n", i);

    printf("YI is(this is hex): %u \n", YI);

    printf("FAN is(this is hex): %x \n", FAN);
}
/* According to the printf() function output format,
 * take caution of the specifiers.
 */
