#include <stdio.h>

int bitlen(unsigned d);
unsigned rightrot(unsigned ,int);

main(){
    printf("rightrot(11,1) -> %u \n", rightrot(11,1));
    printf("rightrot(1024,14) -> %u \n", rightrot(1024,14));

}

int bitlen(unsigned d){
    int len = 0;

    for(; d; d >>= 1) {
        len++;
    }

    return len;
}
unsigned rightrot(unsigned x, int n){
    
    int len = bitlen(x);
    if(len){
        n %= len;
        if(n){
            unsigned right = x & ~(~0 << n);
            return right << len - n ^ x >> n;
        }else{
            return x;
        }
    }else{
        return 0;
    }
}
