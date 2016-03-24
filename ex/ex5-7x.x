#include <stdio.h>
#define MAX 10000

int my_readlines(char*[],int);
char *my_getline(int max);

main(){
    char *A[MAX];
    int i = 0;
    int n = 0;
    char *x;
    char a[] = "yangyifan";
    char b[] = " is a handsome man.";
    char c[] = "He is in Hofstra University.";

    //A[0] = a;
    //A[1] = b;
    //A[2] = c;
    n = my_readlines(A,MAX);
    printf("n is %d \n",n);
    for(;i < n;i++)
        printf("%s \n", A[i]);
}

int my_readlines(char *A[], int max){
    int i = 0;
    char *ptr;

    while((ptr = my_getline(max)) != -1){
        printf("ptr0000 is %d \n",ptr);
        A[i++] = ptr;
    }
    
    return i;
}

char *my_getline(int max){
    char s[max];
    char c;
    int i = 0;
    int n = 0;

    while((c = getchar()) != EOF && i < max-1){
        if(c == '\n'){
            s[i++] = '\n';
            s[i] = '\0';
            printf("s is %d \n",s);
            return s;
        }else{
            s[i++] = c;
        }
    }
    
    return -1;

}
