#include <stdio.h>

/* pirntd: print n in decimal */
void pinrtd(int n){
    if(n<0){
        putchar('-');
        n = -n;
    }

    if(n /10)
        printd(n /10);
    putchar(n % 10 + '0');
}
