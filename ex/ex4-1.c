#include <stdio.h>

#define MAXLINE 1024

int strindex2(char[], char[]);
int my_getline(char s[], int lim);

char pattern[] = "yang";

main(){
    char line[MAXLINE];
    int found = 0;

    while(my_getline(line, MAXLINE) > 0){
        found = strindex2(line,pattern);
        if(found >= 0)
            printf("Position is %d \n",found + 1);
        else 
            printf("Pattern not match. \n");
    }
    
}

int my_getline(char s[], int lim){
    int i;
    char c;

    i = 0;
    while(--lim > 1 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex2(char s[],char t[]){
    int i,j,k,position;

    position = -1;
    i = j = k = 0;
    //printf("44\n");
    while(s[i] != '\0'){
        for(j = i, k = 0;
                t[k] != '\0' && s[j] != '\0' && s[j] == t[k];
                j++,k++) ;
        if(k > 0 && t[k] == '\0')
            position = i;
        i++;
    }
    return position;
    
}
