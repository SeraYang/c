#include <stdio.h>

#define MAXLINE 1024

void itob(int, char[], int);
void reverse(char[]);

main(){
    int n,b;
    char s[MAXLINE];

    n = -43124244;
    b = 16;
    itob(n,s,b);
    printf("%s \n", s);

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

void itob(int n,char s[], int b){
    int sign,first_digit,incre;
    int remainder;
    char c;

    if(b <= 0 || b > 35) return;

    sign = first_digit = incre = 0;
    if(n < 0){
        sign = -1;
        first_digit = (n % b);
        first_digit *= -1;
        if(first_digit >= 0 && first_digit <= 9)
            s[incre++] = first_digit + '0';
        else
            s[incre++] = first_digit - 10 + 'A';
        n /= b * -1;
    }

    do{
        remainder = n % b;
        if(remainder >= 0 && remainder <= 9)
            s[incre++] = remainder + '0';
        else
            s[incre++] = remainder - 10 + 'A';
    }while((n /= b) > 0);

    if(sign < 0)
        s[incre++] = '-';
    s[incre] = '\0';
    reverse(s);
}
