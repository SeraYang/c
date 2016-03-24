#include <stdio.h>

unsigned setbits(unsigned x, int a,int b, unsigned y);

main(){
    unsigned x,y;
    int a,b;
    unsigned result;

    x = 127;
    y = 97;

    a = 4;
    b = 2;
    
    result = setbits(x,a,b,y);
    printf("result is %u \n", result);
}

unsigned setbits(unsigned x, int a, int b, unsigned y){
    if(a >= b)
        return (x & ~(~(~0 << b) << (a-b)))   // this empties the characters between.
                |
                (y & ~(~0 << b) << (a-b));  // this cut out the bits needed.
}
