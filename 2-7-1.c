#include <stdio.h>

int atoi(char[]);

main(){
    char s[10];
    int i;

    s[0] = '5';
    s[1] = '3';
    s[2] = '2';
    s[3] = '1';
    s[4] = '0';
    s[5] = '3';
    s[6] = '\0';

    i = atoi(s);
    printf("%d \n", i);
}

int atoi(char s[]){
    int i,n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9';++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
