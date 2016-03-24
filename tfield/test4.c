#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
};

struct {
    int len;
    char *str;
} *ptr;

struct abcd{
    int a;
    int b;
}haha;

/* makepoint: make a point from x and y components */
struct point makepoint(int x,int y);

main(){
    struct point yi; 
    yi = makepoint(10,20);

    printf("%d \n",yi.x);
    printf("%d \n",yi.y);
    
    ptr = malloc(sizeof(*ptr)); 
    struct abcd a; 
    struct ptr * xx;
    //xx = malloc(sizeof(*ptr));
    //xx->len = -10;
    
    ptr->len = 1000;
    printf("%d\n",ptr->len);
}

struct point makepoint(int x,int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}
