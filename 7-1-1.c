#include <stdio.h>
#include <ctype.h>
#define YANG 1999

main() /* lower: convert input to lower case*/
{
    int c;
    printf ("%d \n",YANG);
    while ((c = getchar()) != EOF)
        putchar(tolower(c)); // tolower() is to convert
                             // the capital
                             // letters to lower letters.
    return 0;
}
