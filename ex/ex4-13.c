/*
EXERCISE 4-13 Gregory Pietsch
*/
#include <stdio.h>

static void swap(char*, char*, size_t);
void my_memrev(char*, size_t);
void reverse(char *s);


main(){
    char *s = "yangyifan";

    printf("%s \n",s);
    reverse(s);
    printf("%s \n",s);

}

static void swap(char *a, char *b, size_t n)
{
    while (n--) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
        a++;
        b++;
    }
}

void my_memrev(char *s, size_t n)
{
    switch (n) {
    case 0:
    case 1:
        break;
    case 2:
    case 3:
        swap(s, s + n - 1, 1);
        break;
    default:
        my_memrev(s, n / 2);
        my_memrev(s + ((n + 1) / 2), n / 2);
        swap(s, s + ((n + 1) / 2), n / 2);
        break;
    }
}

void reverse(char *s)
{
    char *p;

    for (p = s; *p; p++)
        ;
    my_memrev(s, (size_t)(p - s));
}
