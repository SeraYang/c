#include <stdio.h>

#define dprint(expr) printf(#expr " = %g \n", expr)
#define paste(front, back) front ## back

main(){
    double x = 10;
    int y = 5;

    dprint(x/y);

    char * a = "yang";
    char * b = "yifan";
    int yangyifan = 0;
    paste(yang,yifan) = 1000;
    printf("%d \n",yangyifan);
}
