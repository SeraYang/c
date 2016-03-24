#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
    char *a[] = {"yangyifan","zhangfengmei","hofstra","university"};

    char *x;
    void *xx;
    int i;

    //for(i = 0;i < 4;i++)
    //    printf("%s \n",A[i]);
    //for(i = 0; i < 3 ;i++){
        //printf("%s \n",*++a[0]);
    //}
        printf("%c \n",*(a+1)[0]);
        printf("%c \n",*++a[2]);
        printf("%c \n",*a[0]);
        printf("%c \n",*++a[0]);
        printf("%c \n",*++a[0]);
        printf("%c \n",*++a[0]);
}
