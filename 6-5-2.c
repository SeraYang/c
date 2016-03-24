/* show talloc in stdlib.h */
#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void) // alloc memory for a tnode.
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)  // make a duplicate of s
{
    char *p;

    p = (char *) malloc(strlen(s) + 1); // +1 for '\0'
    if(p!=NULL)
        strcpy(p,s);
    return p;
}
