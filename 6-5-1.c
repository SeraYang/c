/* Title: Self-referential Structures */
/* This is about the building binary search tree */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode *my_addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *my_strdup(char *);

struct tnode   // the tree node:
{
    char *word; // points to the text
    int count;  // number of occurrences
    struct tnode *left;  // left child
    struct tnode *right; // right child
};

/* word frequency count */
main()
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = my_addtree(root, word);
    treeprint(root);
    return 0;
    
}

/* my_addtree: add a node with w, at or below p */
struct tnode *my_addtree(struct tnode *p, char *w){
    int cond;

    if(p == NULL){  // a new word has arrived 
        p = talloc();  // make a new node
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w,p->word)) == 0)
        p->count++; // repeated word
    else if(cond < 0)   // less than into left subtree
        p->left = my_addtree(p->left,w);
    else            // greater than into right subtree
        p->right = my_addtree(p->right,w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p){
    if(p!=NULL){
        treeprint(p->left);
        printf("%4d %s\n",p->count,p->word);
        treeprint(p->right);
    }
}
