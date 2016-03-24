/* this is called shell sort, which is to sort
 * an array, so that elements of this array are
 * increasing.
 *
 * Explanation: 
 *      1. is to determine
 *      the gap, which means the equally
 *      length between two elements compared.
 *
 *      2. is to increase the number of the 
 *      leading elements.
 *
 *      3. compare the leading element with 
 *      the one "gap" behind.
 *
 *      4. then, make sure the elements with
 *      "gap" distance are sorted.
 *
 *      5. change the length of the gap. And
 *      repeat the 1~4.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

void shellsort(int v[], int n){
    int gap, i, j, temp,count;

    count = 0;
    for(gap = n/2;gap > 0;gap /= 2){
        printf("gap is %d \n",gap);
        for(i = gap; i< n;i++){
            printf("i is %d \n",i);
            for(j = i-gap; j>=0 && v[j] > v[j+gap];j -= gap){
                //if(i == gap)
                //    printf("jjjjjjjj is %d \n",j);
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                count++;
            }
        }
    }
    printf("%d total changes\n",count);
}

main(){
    int v[MAXLINE];
    int len,i;

    len = 0;
    for(i = 0;i<100;i++){
        v[i] = i % 7;
        len++;
        printf("%d ",v[i]);
    }
    printf("\n");
    printf("length is %d \n",len);

    shellsort(v,len);
    for(i = 0;i < len;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
