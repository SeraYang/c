#include <stdio.h>

struct a{
    char c;
    int i;
};

main(){
    unsigned x = sizeof(struct a);
    printf("%u \n",x);
}
