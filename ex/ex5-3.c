#include <stdio.h>

void strcat1(char*,char*);

main(){
    char m[100];
    char n[100];
    int i = 0;

    m[i] = 'y';
    n[i++] = 'y';
    m[i] = 'a';
    n[i++] = 'i';
    m[i] = 'n';
    n[i++] = 'f';
    m[i] = '\0';
    n[i] = '\0';
    printf("%s \n",m);
    strcat1(m,n);
    printf("%s \n",m);

}

void strcat1(char *m,char *n){
    while(*m != '\0')
        m++;
    while(*n != '\0'){
        *m = *n;
        m++;
        n++;
    }
}
