#include <stdio.h>

#define MAXLINE 1024

void itoa(int,char[]);
void itoa2(int, char[]);
void itoa3(int, char[],int);
void reverse(char[]);

main(){
    int i,j,k;
    char s[MAXLINE];
    char t[MAXLINE];
    char u[MAXLINE];

    i = 2147483647;
    j = -2147483648;
    k = -2147483648;
    //itoa(i, s);
    itoa2(i,t);
    itoa2(j,s);
    itoa3(k,u,12);
    printf("%s \n",s);
    printf("%s \n",t);
    printf("%s \n",u);

}

void itoa(int n, char s[]){
    int i,sign;

    for(i = 0; i < MAXLINE; i++){
        s[i] = ' ';
    }

    if((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int len,i,j;
    char temp;

    len = i = j = 0;
    while(s[i] != '\0') {
        i++;
    }
    len = i;    /* obtain the length */

    if(len > 0)
        for(i = 0,j = len-1; i < j ;i++,j--){
            temp = s[j];        
            s[j] = s[i];
            s[i] = temp;
        }
}

void itoa2(int n, char s[]){
    int i,j;
    int sign;
    char c;

    for(i = 0; i < MAXLINE; i++){
        s[i] = ' ';
    }
    i = j = 0;
    if(n < 0) {
        i = n % 10;
        i *= -1;
        s[j++] = i + '0';
        n /= -10;
        sign = -1;
    }

    do{
        s[j++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if(sign < 0)
        s[j++] = '-';
    s[j] = '\0';
    reverse(s);
}

void itoa3(int n, char s[], int width){
    int i,j;
    int sign;
    char c;

    i = j = 0;
    for(i = 0; i < MAXLINE; i++){
        s[i] = ' ';
    }
    if(n < 0) {
        i = n % 10;
        i *= -1;
        s[j++] = i + '0';
        n /= -10;
        sign = -1;
    }

    do{
        s[j++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if(sign < 0)
        s[j++] = '-';
    s[width] = '\0';

    reverse(s);
}
