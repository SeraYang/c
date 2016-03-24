/* how to use the function pointer */
#include <stdio.h>

int (*yang)(int a,int b);

main(){
    void *x;

    printf("%d \n",yang);
}

int (*yang)(int a,int b){
    return a+b;
}
