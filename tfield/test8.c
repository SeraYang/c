/* typedef a pointer of a function */
#include <stdio.h>

typedef int (*prin)();

main(){
    prin a;
    (*a)();
}

int (*prin)()
{
    return 0;
}
