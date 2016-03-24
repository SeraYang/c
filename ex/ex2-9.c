#include <stdio.h>

int bitcount(unsigned);

main(){
    unsigned x = 124;
    int result;

    result = bitcount(x);
    printf("result is %d \n", result);
}

int bitcount(unsigned x){
    int count;

    for(count = 0; x > 0; x &= (x-1))
        count++;

    return count;
}
