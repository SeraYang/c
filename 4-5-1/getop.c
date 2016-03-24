#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int yang(){
    printf("I'm in yang \n");
}

/* getop: get next character or numeric operand */
int getop(char s[]){
    int i,c;
    int sign;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    i = 0;          /* if c is digit or is '.' */
    if(c == '-' && isdigit(c = getchar())) {
        s[i++] = '-';            
        s[i] = c;
    }
    if(!isdigit(c) && c != '.') {
        return c;   /* not a number */
    }

    if(isdigit(c))  /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')    /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            //printf(" c is %c \n",c);
    //printf("i is %d \n",i);
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
