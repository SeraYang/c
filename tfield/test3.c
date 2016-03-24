#include <stdio.h>

main(){
    char* ss[]={"yang","yifan","hofstra","university"};
    printf("%s \n",*(ss+1));
    printf("%c \n",*(*(ss+1)+2));

    int (*daytab)[3];
    (*daytab)[0] = 1;
    (*daytab)[1] = 2;
    (*daytab)[2] = 3;
}
