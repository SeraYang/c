#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n);

main(){
    /* test the operators >> and << */
    int a;
    //a=  4;
    //a = a << 1;
    //printf("a is %d \n", a);

    //a = 4;
    //a = a & 077;
    //char yi[100];
    //yi[0] = 'a';
    //yi[1] = 'b';
    //yi[2] = 'c';
    //yi[3] = 'd';
    //yi[4] = 'e';
    //a = strlen(yi);
    //printf("length of yi is %d \n",a);
    //int yang;
    //yang = ~0;
    //printf("yang is %d \n",yang);

    //a = 100;
    //a = getbits(a, 6,3);
    //printf("a is %d \n", a);

    unsigned x;
    x = 0;
    x = x ^ ~0;
    printf("x is %u \n",x);
}

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}
