#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main(){
    unsigned x,result;
    int p,n;

    x = 119;
    p = 4;
    n = 2;
    result = invert(x,p,n);
    printf("result is %u \n", result);

}

unsigned invert(unsigned x, int p, int n){
    if(p >= n)
        //return (((((x >> p) ^ 0) << n) 
        //    |
        //    (~(~0 << n) & x >> (p-n))) ^ 0)  <<  (p-n)
        //        |
        //    (~(~0 << p-n) & x);
        return ~((~(x >> p) << n)
                |
                (~(~0 << n) & x >> (p-n))) << (p-n)
                    |
                (~(~0 << p-n) & x);

}
