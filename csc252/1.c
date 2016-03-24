#include <stdio.h>
#include <string.h>

main(){
    char * a = "abc";
    char * b = "def";
    int an = strlen(a);
    int bn = strlen(b);
    char * temp = (char *)malloc(an+bn+1);
    
    memcpy(temp,a,an);
    memcpy(temp + an,b,bn+1);

    printf("%s \n",temp);
    //deallocate
    //free(a);
    //free(temp);
    a = temp;
    printf("%s \n",a);
}

