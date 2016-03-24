#include <stdio.h>
#include <ctype.h>

int atoi(char s[]){
    int i,n,sign;

    for(i = 0;isspace(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1:1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(n = 0;isdigit(s[i]);i++)
        n = 10*n + (s[i] - '0');
    return sign * n;
}

main(){
    char s[10];
    int result;
    s[0] = ' ';
    s[1] = ' ';
    s[2] = ' ';
    s[3] = '+';
    s[4] = '3';
    s[5] = ' ';
    s[6] = '8';
    s[7] = ' ';
    s[8] = '\0';

    result = atoi(s);

    printf("%d \n",result);
}
