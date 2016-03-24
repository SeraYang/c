#include <stdio.h>

#define ARRSIZE 1024

void TopDownSplitMerge(int[],int,int,int[]);
void TopDownMerge(int[],int,int,int,int[]);
void CopyArray(int[],int,int,int[]);

main(){
    int A[ARRSIZE], B[ARRSIZE];
    int i = 0,j = 0;

    A[i++] = 5;
    A[i++] = 6;
    A[i++] = 40;
    A[i++] = 3;
    A[i++] = 2;
    A[i++] = 28;
    A[i] = 10;
    TopDownSplitMerge(A,0,i,B);

    for(j = 0;j < i; j++){
        printf("%d \n",A[j]);
    }

}

/* iBegin is inclusive; 
 * iEnd is exclusive;
 * (A[iEnd] is not in the set);
 * */
void TopDownSplitMerge(int A[],int iBegin, int iEnd, int B[]){
    if(iEnd - iBegin < 2) // if run size == 1
        return; // consider it sorted
    // recursively split runs into two halves
    // until run size == 1, then merge them
    // and return back up the call chain.
    int iMiddle = (iEnd + iBegin) / 2; // iMiddle = mid point.
    TopDownSplitMerge(A,iBegin,iMiddle,B); //split merge left half
    TopDownSplitMerge(A,iMiddle,iEnd,B); // split merge right half
    TopDownMerge(A,iBegin,iMiddle,iEnd,B); // Merge the two half runs
    CopyArray(B,iBegin,iEnd,A); // copy the merged runs back to A
}

// left half is A[iBegin: iMiddle-1]
// right half is A[iMiddle: iEnd-1]
void TopDownMerge(int A[],int iBegin,int iMiddle,int iEnd,int B[]){
    int m = iBegin,n = iMiddle; /* m is for former part
                                   n is for later part */
    int j;

    // while there are elements in the left or right runs
    for(j = iBegin;j < iEnd; j++){
        // If left run head exists and is
        // <= existing right run head.
        if(m < iMiddle && (n >= iEnd 
                || A[m] <= A[n])){
            B[j] = A[m];
            m++;
        }else{
            B[j] = A[n];
            n++;
        }
    }
}

void CopyArray(int B[],int iBegin,int iEnd,int A[]){
    int k = 0;
    for(k = iBegin; k < iEnd; k++){
        A[k] = B[k];
    }
}
