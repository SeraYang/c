#include <stdio.h>

int binsearch(int,int[],int);

main(){
    int list[100];
    int len;
    int i,j;

    for(i = 0; i < 100; i++)
        list[i] = i*i + i/4;

    for(i = 0;i < 100; i++){
        //printf("list[%d] is %d. \n",i+1,list[i]);
        j = binsearch(list[i],list,100);
        if(j>0)
            printf("it works for %d, the position is %d \n",list[i],j);
        if(j<=0)
            printf("it NOT works for position %d \n", i);
    }

    //j = binsearch(7766,list,100);
    //printf("position j is %d \n", j);
}

int binsearch(int x, int v[],int n){
    int low, high, mid;

    low = 0;high = n-1;
    while(low <= high){
        mid = (low + high)/2;
        if(x < v[mid]){
            high = mid - 1;
            //printf("high is %d \n",high);
            //printf("mid is %d \n", mid);
        }
        else{
            low = mid + 1;
            //printf("low is %d \n",low);
            //printf("mid is %d \n", mid);
        }
    }

    if(x == v[mid])
        return mid;
    else if(x == v[low])
        return low;
    else if(x == v[high])
        return high;
    else
        return -1;
}
