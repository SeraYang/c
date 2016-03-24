#include <stdio.h>
#include <string.h>

#define ROW 10
#define COL 10

void strcpy1(char*, char*);
void strcpy2(char*, char*);
int strcmp1(char *, char*);
void printf2d(int (*x)[COL]);

main(){
    //char *s,*t;
    //char a;
    //int i,m;
    //int *x;
    //
    //i = 0;
    //x = &i;
    //m = 100;
    //*x++ = m;
    //*x = i;
    //printf("%d \n",i);
    //void *a;
    //int *b;
    //char *c;
    //int x[10];
    //int i = 0;
    //char y[10];

    //x[i++] = 10;
    //x[i++] = 9;
    //x[i++] = 8;
    //x[i++] = 7;
    //y[0] = 'a';
    //y[1] = 'b';
    //y[2] = 'c';
    //y[3] = 'd';
    //y[4] = '\0';
    //b = x;
    //c = y;
    //printf("%d \n",*b);
    //
    //b = b+1;
    //printf("%c \n",*b);
    
    char *ptr = NULL;
    char s[10];
    int i = 0,j = 0;

    int yang[ROW][COL] ={
        {1,2,3,4,5,6,7,8,9},
        {11,12,13,14,15,16,17,18,19},
        {21,22,23,24,25,26,27,28,29}
    };

    //for(i = 0;i<ROW;i++){
    //    printf("\n");
    //    for(j = 0;j < COL;j++)
    //        printf("%d ",yang[i][j]);
    //}
    printf2d(yang);
    

    //if(ptr == NULL)
    //    printf("yes \n");
    //printf("%c \n",ptr);
    //ptr = s;
    //ptr[0] = 'a';
    //ptr[1] = 'b';
    //ptr[2] = 'x';
    //ptr[3] = 'y';
    //ptr[4] = 'z';
    //ptr[5] = '\0';

    //for(i = 0;i<5;i++)
    //    printf("%c \n",*(ptr+i));
    //printf("%s \n",ptr);
    //ptr = -1;
    //printf("%d \n",ptr);
    //printf("%s \n",s);
    
}

void strcpy1(char *s, char *t){
    int i;

    i = 0;
    while((*s = *t)!= '\0'){
        s++;
        t++;
    }
    printf("%c \n",*(s++));
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy2(char *s, char *t){
    while (*s++ = *t++)
        ;
}

int strcmp1(char *s, char *t){
    int i;

    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

void printf2d(int (*x)[COL]){
    int i,j;

    for(i = 0;i < ROW;i++){
        printf("\n");
        for(j = 0;j < COL;j++)
            printf("%d ",x[i][j]);
    }
    printf("\n");
}
