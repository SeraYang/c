#include <stdio.h>
#define MAXLINE 20   /* maximum input line length */

int my_getline(char line[], int maxline);

/* print the longest input line */
main(){
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */

    max = 0;
    while((len = my_getline(line, MAXLINE)) >0){
        if(len < MAXLINE)
            printf("%s \n",line);
    }

    return 0;

}


/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim){
    int c,i;

    for(i = 0;i < lim-1 && (c = getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';    // this '\0' is the string termination sign.
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
