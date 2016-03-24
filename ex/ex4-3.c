#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXVAL 100  /* maximum depth of val stack */
#define MAXOP 100
#define NUMBER '0'

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor \n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty \n");
        return 0.0;
    }
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

int getch(void)     /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}
