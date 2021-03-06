#include <stdio.h>

void my_qsort(int[],int,int);
void swap1(int[],int,int);

main(){
    int a[10];
    int i;

    i = 0;
    a[i++] = 10;
    a[i++] = 5;
    a[i++] = 4;
    a[i++] = 8;
    a[i++] = 7;
    a[i++] = 3;
    a[i++] = 1;
    a[i++] = 0;

    for(i = 0;i < 8;i++)
        printf("%d \n",a[i]);
    my_qsort(a,0,8);
    printf("-------------- \n");
    for(i = 0;i < 8;i++)
        printf("%d \n",a[i]);
}
/* my_qsort: sort v[left] ... v[right] into increasing order */

void my_qsort(int v[], int left, int right){
    int i, last;
    //void swap1(int v[], int i, int j);
    if(left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    
    //printf("left is %d \n",left);
    //printf("right is %d \n",right);

    swap1(v,left, (left + right) /2); /* move partition element */
    last = left; /* to v[0] */
    //printf("last is %d \n", last);
    for(i = left + 1; i<=right; i++) /* partition */
        if(v[i] < v[left])
            swap1(v,++last, i);
    swap1(v,left, last); /* restore partition element */
    my_qsort(v,left,last-1);
    my_qsort(v,last+1,right);
}

/* swap1: interchange v[i] and v[j] */
void swap1(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
