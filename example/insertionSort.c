#include <stdio.h>

#define SIZE 100

void inserSort(int A[],int);

main(){
    int A[SIZE];

    int n = 0;
    int i;
    A[n++] = 6;
    A[n++] = 58;
    A[n++] = 4;
    A[n++] = 2;
    A[n++] = 7;
    A[n++] = 1;
    A[n++] = 0;

    for(i = 0;i < n;i++){
        printf("%d \n",A[i]);
    }
    printf("------------\n");
    inserSort(A,n);
    for(i = 0;i < n;i++){
        printf("%d \n",A[i]);
    }
}

void inserSort(int A[],int n){ // n is the length of the array A
    int exchange = 0;
    int temp = 0;
    int mark = 0;
    int i = 0;

    if(n < 2) return;

    //printf("temp is %d \n",temp);
    inserSort(A,n-1);

    while(i < n-1 && mark == 0){
        if(A[n-1] < A[i]){
            exchange = A[i];
            A[i] = A[n-1];
            mark = 1;
        }
        i++;
    }
    while(i < n && mark == 1){
        temp = exchange;
        exchange = A[i];
        A[i] = temp;
        i++;
    }

    return;
}
