#include <stdio.h>
#define MAX 1000

int my_getline(char[]);
void reverse(char[],char[],int);

main(){
    char input[MAX];
    char re[MAX];
    int  count;

    while((count = my_getline(input))>0){
         reverse(input,re,count);
         printf("%s \n",re);
    }

    return 0;
}


int my_getline(char input[]){
    char c;
    int i;
    
    for(i = 0;i< MAX-1 && (c = getchar()) != EOF && c != '\n';i++)
        input[i] = c;
    
    input[i] = '\0';
    return i-1;
}

void reverse(char a[],char b[],int x){
    int i;
    for(i = 0;i<x+1; i++){
        b[i] = a[x-i];
    }
    b[i] = '\0';
}
