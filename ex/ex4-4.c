#include <stdio.h>

#define ARR_SIZE 1024

int pop(int[]);
int push(int[],int);
void show_top(int[]);
void copy(int[],int[]);
void swap_top2(int[]);
void clear(int[]);

main(){
    int s[ARR_SIZE];
    int i = 0;
    
    clear(s);
    s[i++] = 1;
    s[i++] = 2;
    s[i++] = 3;
    s[i++] = 4;
    s[i++] = 5;
    s[i++] = 6;
    s[i] = '\0';

    show_top(s);
    swap_top2(s);
    for(i--;i >= 0;i--)
        printf("%d \n",s[i]);
    //printf("%d \n", i);
    //s[0] = 0;
    //if(s[i] != '\0')
    //    printf("yes!! \n");
    //s[0] == '0';
    //if(s[i] != '\0')
    //    printf("yesssss \n");
}

int pop(int s[]){
    int len = 0;
    int d = 0;

    for(;s[len] != '\0';len++)
        ;
    if(len == 0)
        printf("The stack is EMPTY!!! \n");
    else{
        d = s[--len];
        s[len] = '\0';
        return d;
    }
    return '\0';
}

int push(int s[],int num){
    int i = 0;
    int len = 0;

    for(;s[len] != '\0';len++)
        ;
    if(len >= ARR_SIZE) {
        printf("The stack is FULL!!! \n");
        return 0;
    }

    s[len] = num;
    return 1;
}

void show_top(int s[]){
    int d = 0;

    d = pop(s);
    push(s,d);
    printf("The top element is %d \n",d);
}

void copy(int s[], int t[]){
    int i = 0;

    for(; i < ARR_SIZE; i++)
        t[i] = s[i];
}

void swap_top2(int s[]){
    int first,second;

    if((first = pop(s)) != '\0' && (second = pop(s)) != '\0'){
        push(s,first);
        push(s,second);
    }else{
        printf("There is less than two elements in the stack! \n");
    }
}

void clear(int s[]){
    int i = 0;

    for(;i < ARR_SIZE; i++)
        s[i] = '\0';
}
