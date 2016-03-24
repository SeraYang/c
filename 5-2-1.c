#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int bufp = 0;
int buf[100];

main(){
    int *pn;
    int x;

    pn = &x;
    while( (x = getint(pn)) != EOF)
        printf("%d \n",*pn);
    
        
}

/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    for(*pn = 0;isdigit(c);c = getch())
        *pn = 10 * (*pn) + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}

int getch(){
    if(bufp > 0) printf("in here is %c \n",buf[bufp-1]);
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= 100)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}
