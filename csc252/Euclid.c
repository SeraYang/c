#include <stdio.h>

int gcd(int a, int b);
main(){
    int a = 90;
    int b = 10;

    printf("%d \n",gcd(b,a));
   
}

int gcd(int a, int b){
    if (a==0) return b; else return gcd(b%a,a);
}
