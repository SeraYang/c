#include <stdio.h>

#define SIZE 100

void BottomUpMergeSort(int[],int[],int);
void BottomUpMerge(int[],int,int,int,int[]);
void CopyArray(int[],int[],int);
int min(int,int);

main(){
    int A[SIZE],B[SIZE];
    int i = 0,j = 0;

    A[i++] = 10;
    A[i++] = 9;
    A[i++] = 8;
    A[i++] = 7;
    A[i++] = 6;
    A[i++] = 5;
    A[i++] = 4;
    A[i++] = 3;
    A[i++] = 2;
    A[i++] = 1;

    for(j = 0;j<i;j++){
        printf("%d \n",A[j]);
    }
    printf("----------------\n");
    BottomUpMergeSort(A,B,i);
    
    for(j = 0;j<i;j++){
        printf("%d \n",A[j]);
    }
}

/* array A[] has the items to sort; 
 * array B[] is a work array */
void BottomUpMergeSort(int A[],int B[],int n){
    int i,width;
    /* Each 1-element run in A is already "sorted". */
    /* Make successively longer sorted runs of length
     * 2,4,8,16... until whole array is sorted. */
    for(width = 1;width < n; width = 2 * width){
        /* Array A is full of runs of length width. */
        for( i = 0; i<n; i+=2*width){
            /* Merge two runs: A[i:i+width-1]
             * and A[i+width:i+2*width-1] to
             * B[] or copy A[i:n-1] to B[]
             * (if(i+width >= n))
             */
            BottomUpMerge(A,i,min(i + width, n),
                        min(i + 2*width,n),B);
        }
        /* Now work array B is full of runs of length
         * 2*width. 
         * Copy array B to array A for next iteration.
         * A more efficient implementation would
         * swap the roles of A and B
         */
        CopyArray(B,A,n);
        /* Now array A is full of runs of length
         * 2*width.
         */
    }
}

void BottomUpMerge(int A[],int iLeft,int iRight,int iEnd,
                   int B[]){
    int m = iLeft;
    int n = iRight;
    int j;

    /* While there are elements in the left or
     * right runs.
     */
    for(j = iLeft; j < iEnd;j++){
        /* If left run head exists and is <= existing
         * right run head
         */
        if(m < iRight && (n >= iEnd ||
                            A[m] <= A[n]))
        {
            B[j] = A[m];
            m++;
        }else{
            B[j] = A[n];
            n++;
        }
    }
}

void CopyArray(int B[], int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        A[i] = B[i];
    }
}

int min(int a,int b){
    return (a < b)? a : b;
}
