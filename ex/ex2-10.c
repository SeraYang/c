#include <stdio.h>

char lower(char);

main(){
    char a;

    a = lower('A');
    printf("%c \n",a);
}

char lower(char a){
    if(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z')
        return a >= 'a' && a <= 'z' ? a : a+32;
}
