#include <stdio.h>
#include <stdlib.h>

struct problem37
{
    int a;
    int b;
    int c;
};

int main()
{
    printf("Problem 37\n");

    //create struct
    struct problem37 myStruct;

    //create the pointer
    int* p;
    int* q;
    int* r;

    p = malloc(sizeof(int)); // this (int*) in the front is 
                             // not necessary.
    q = (int*)malloc(sizeof(int));
    r = (int*)malloc(sizeof(int));
    *p = 1;
    printf("here\n");
    *q = 5;
    *r = 8;

    printf("%d \n",*p);
    //read the data into the struct using the pointers
    myStruct.a = *p;
    myStruct.b = *q;
    myStruct.c = *r;

    printf("%d\n", myStruct.a);
    printf("%d\n", myStruct.b);
    printf("%d\n", myStruct.c);

    return 0;
}
