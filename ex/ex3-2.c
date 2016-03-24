#include <stdio.h>

#define MAXLINE 1024

void escape(char[],char[]);
void unescape(char[],char[]);

main(){
    char x[MAXLINE];
    char xx[MAXLINE];
    char c;
    int i = 0;

    while((c = getchar()) != EOF){
        //printf("now c is %c \n",c);
        x[i++] = c;
    }
    x[i] = '\0';
    //printf("%s \n",x);
    //printf("string is finished \n");
    escape(x,xx);
    printf("%s \n",xx);
    unescape(xx,x);
    printf("%s \n",x);


}

void escape(char s[],char t[]){
    int i,j;

    i = 0;
    j = 0;
    while(s[i] != '\0'){
        //printf("In while \n");
        switch(s[i]){
            case '\\':
                if(s[i+1] != '\0' && s[i+1] == 't'){
                        t[j++] = '\t';
                        i += 2;
                    }else if(s[i+1] != '\0' && s[i+1] == 'n'){
                        t[j++] = '\n';
                        i += 2;
                    }else
                        t[j++] = s[i++]; 
                break;
            default:
                t[j++] = s[i++];
                break;
        }
    }
    t[j] = '\0';
}

void unescape(char t[], char s[]){
    int i,j;

    i = j = 0;
    while(t[i] != '\0'){
        switch(t[i]){
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                i++;
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                i++;
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}
