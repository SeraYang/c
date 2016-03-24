#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getword(char *word, int lim);

main(){
    char word[10];
    word[0] = 'y';
    word[1] = 'a';
    word[2] = 'n';
    word[3] = 'g';
    word[4] = 'y';
    word[5] = 'i';
    word[6] = '\0';
    printf("%c \n",word[0]);
    printf("%c \n",*word);
    *word = 's';
    printf("%s \n",word);
    int x = getword(word,BUFSIZE);
    printf("%s \n",word);
    
    

//    int
    
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    printf("%s \n",w);
    while (isspace(c = getch()))
        ;
    if (c != EOF) 
        *(w++) = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void)     /* get a (possibly 
                       pushed-back) character */
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
