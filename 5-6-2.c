#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void qsort1(char *v[], int left, int right);
void swap(char *v[], int i, int j);

main(){
    //int *v[20];
    //int val[20];
    //int i = 0;
    //int j = 0;

    //srand(time(NULL));
    //for(i = 0; i < 20;i++)
    //    val[i] = rand() % 100;
    //for(j = 0; j < i;j++)
    //    printf("%d \n",val[j]);
    //for(j = 0;j < i;j++)
    //    v[j] = &val[j];
    //printf("--------------\n");
    //for(j = 0;j < i;j++)
    //    printf("%d \n",*v[j]);
    //printf("--------------\n");

    //qsort1(v,0,i);
    //for(j = 0;j < i;j++)
    //    printf("%d \n",*v[j]);
    char *v[200];
    char s[] = "yangyifan is a handsome man.";
    int i= 0;
    int j = 0;

    for(i = 0; s[i]!='\0';i++)
        v[i] = &s[i];
    for(j = 0;j < i;j++)
        printf("%c \n",*v[j]);
    qsort1(v,0,i);
    for(j = 0;j < i;j++)
        printf("%c \n",*v[j]);
}

void qsort1(char *v[], int left, int right){
    int i,last;
    void swap(char *v[], int i, int j);
    if(left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v,left,(left + right)/2);
    last = left; /* last is to store the value 
                    int the middle */
    for(i = left + 1;i <= right; i++)
        if(strcmp(v[i],v[left]) < 0)
            swap(v, ++last, i);
    swap(v,left, last);
    qsort1(v, left, last-1);
    qsort1(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){
    char * temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
