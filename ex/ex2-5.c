#include <stdio.h>

#define MAXLINE 1024

void any(char s1[],char s2[]);

main(){
    char s1[MAXLINE],s2[MAXLINE];
    int i,j;

    for(i = 0;i < 4;i++)
        s1[i] = 'b' + i;
    s1[i++] = 'y';
    s1[i++] = 'a';
    s1[i++] = 'n';
    s1[i++] = 'g';
    s1[i] = '\0';

    j = 0;
    s2[j++] = 'y';
    s2[j++] = 'i';
    s2[j++] = 'f';
    s2[j++] = 'a';
    s2[j++] = 'n';
    s2[j] = '\0';

    any(s1,s2);
    printf("%s \n",s1);

    
}

void any(char s1[], char s2[]){
    char buf[MAXLINE];
    int i,j;

    /* Make sure there is no duplicate in s2 */
    for(i = 0; s2[i] != '\0'; i++)
        for(j = i+1; s2[i] != ' ' && s2[j] != '\0';j++)
            if(s2[i] == s2[j]) s2[j] = ' ';
    printf("no duplicate s2 is %s \n",s2);

    /* Make sure there is no space ' ' in buf */
    j = 0;
    for(i = 0;s2[i] != '\0';i++)
        if(s2[i] != ' ') buf[j++] = s2[i];
    buf[j] = '\0';

    for(i = 0; s1[i] != '\0';i++)
        for(j = 0;s1[i] != ' '&& buf[j] != '\0';j++)
            if(s1[i] == buf[j]) {
                s1[i] = '_';
                printf("%s \n", s1);
                return;
            }
    printf("-1 \n");
}
