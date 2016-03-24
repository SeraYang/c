#include <stdio.h>

//int power(int,int); // This is a normal declaration.
int power();

main(){
    
}

power(base,n)
    int base,n;
{
    int i,p;

    p = 1;
    for(i = 1;i <=n;i++)
        p = p*base;
    return p;
}
