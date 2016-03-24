#include <stdio.h>

void squeeze(char s[], int c);  /* delete all c from s string */
void my_strcat(char s[], char t[]);    /* concatenate t to end of s; s must be big enough */
int bitcount(unsigned x);
int atoi(char[] s); /* convert s to integer; */
void shellsort(int v[],int n); /*sort int array into increasing order */

main(){
    
}

void squeeze(char s[], int c){
    int i,j;

    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void my_strcat(char s[], char t[]){
    int i,j;

    i = j = 0;
    while(s[i] != '\0') /* find end of s */
        i++;
    while((s[i++] = t[j++]) != '\0')    /* copy t */
        ;
}

int bitcount(unsigned x){
    int b;
    for(b = 0; x!=0; x>>= 1)
        if(x & 01)
            b++;
    return b;
}

int atoi(char[] s){
    int i,n,sign;

    for(i = 0;isspace(s[i]);i++) /*skip spaces*/
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') /*skip sign */
        i++;
    for(n = 0;isdigit(s[i]);i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

void shellsort(int v[], int n){
    int gap,i,j,temp;

    for(gap = n/2; gap > 0;gap /=2)
        for(i = gap; i<n;i++)
            for(j = i-gap;j>=0 && v[j]>v[j+gap];j-=gap){
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
            }
}
