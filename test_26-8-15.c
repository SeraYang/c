#include <stdio.h>

#define MAXLINE 1024

main(){
    int i;
    char s[MAXLINE];
    i = 0;
    while(i<10){
        i++;
        continue;   
        printf("111\n");    /* won't be executed */
    }

    if(i > 0)
        goto yang;

    yang:
        printf("11111  \n");

    s = getline();
}
