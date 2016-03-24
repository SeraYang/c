#include <stdio.h>
#include <stdlib.h>

//typedef struct cell * list

struct cell{
    int item;
    struct cell * next;
};
typedef struct cell * list;

// constructor and accessors
list cons(int i,list n){
    list A = (list)malloc(sizeof(struct cell));
    A->item = i;
    A->next = n;
    return A;
}

int car(list A){return A->item;};
int cdr(list A){return A->next;};
int length(list A);
int last(list A);
list map(list M,int (*f)(int));
int reduce(list *M,int (*op)(int,int), int id);
void printlist(list A);
void freelist(list A);

int main(){
    list A = cons(2,cons(3,cons(5,cons(7,0))));
    printf("%d \n",car(cdr(A)));
    printlist(A);
    list B = cdr(cdr(A));

    return 0;
}

int length(list A){
    int len(list A,int ax){
        if(A == NULL) return ax;
        else return len(cdr(A),ax+1);
    }
    return len(A,0);
}

int last(list A){
    if (cdr(A) == NULL) return car(A);
    else return last(cdr(A));
}

// map /reduce
list map(list M,int (*f)(int)){
    if(M == NULL) return NULL;
    else return cons(f(car(M)),map(cdr(M),f));
}

int reduce(list *M,int (*op)(int,int), int id){
    int ax = id;
    for(;M != NULL; M = cdr(M))
        ax = op(ax,car(M));

    return ax;
}

void printlist(list A){
    for(;A != NULL;A = cdr(A))
        printf("%d \n",car(A));
    printf("\n");
}

void freelist(list A){
    list temp;
    while(A != NULL){
        temp = A;
        A = cdr(A);
        free(temp);
    }
}
