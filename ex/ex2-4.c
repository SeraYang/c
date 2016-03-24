#include <stdio.h>
#define MAXLINE 1024

void squeeze(char s1[],char s2[]);

main(){
    char s1[MAXLINE],s2[MAXLINE];
    int i,j;

    for(i = 0; i<4;i++) s1[i] = 'a';
    for(;i<10;i++) s1[i] = 'a' + i;
    s1[++i] = 'x';
    s1[i] = '\0';
    
    s2[0] = 'a';
    s2[1] = 'g';
    s2[2] = '\0';
    squeeze(s1,s2);
    printf("s1 is %s \n", s1);
}

void squeeze(char s1[], char s2[]){
    char buf[MAXLINE];
    int i,j;

    /* make sure there is no duplicate in the s2 */
    for(i = 0; s2[i] != '\0';i++)
        for(j = i+1; s2[i] != ' ' && s2[j] != '\0'; j++)
            if(s2[i] == s2[j]) s2[j] = ' ';
    printf("no duplicate s2 is %s \n",s2);
    /* make sure there is no spaces in the buf[] */
    j = 0;
    for(i = 0; s2[i] != '\0'; i++)
        if(s2[i] != ' ')
            buf[j++] = s2[i];
    buf[j] = '\0';

    for(i = 0; s1[i] != '\0'; i++)
        for(j = 0; buf[j] != '\0'; j++)
            if(s1[i] == buf[j]) s1[i] = '_';
}
