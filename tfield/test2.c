/* pointer of the pointer */
#include <stdio.h>

void Findc(int**);
void abc(int*);

main(){
    int vals[] = {7,5,4,-1,4,5,4,2};
    int *f = vals;
    Findc(&f);
    //printf("%d \n",*f);
    //printf("%d \n",*vals);

    //abc(f);
    printf("%d \n", *f);

}

void abc(int* x){
    while(*x != 0)
        if(*x < 0) break;
        else {
            x++;
            printf("%d \n", *x);
        }
}

void Findc(int **f){
    while(**f!= 0)
        if(**f > 10) break;
        else{
            (**f)++;
            printf("%d \n",**f);
        }
}
