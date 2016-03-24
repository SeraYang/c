#include <stdio.h>
#include <stdlib.h>

typedef char * string;

main(){
    string s;
    //s = (string)malloc(100);
    s = "yangyifan";
    printf("%d \n",sizeof(s));
    int a = 100;
    printf("%d \n",sizeof(a));
}
