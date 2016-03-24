#include <stdio.h>

#define MAXLINE 1024

int is_letter(char);
void expand(char[],char[]);

main(){
    char input[MAXLINE], output[MAXLINE];
    int i,j;
    char c;

    i = j = 0;
    //input[0] = 'a';
    //input[1] = '-';
    //input[2] = 'z';
    //input[3] = '\0';
    while((c = getchar()) != EOF){
        input[i++] = c;
    }
    input[i] = '\0';
    printf("%s \n", input);
    expand(input, output);
    printf("%s \n", output);
}

int is_letter(char x){
    if(x >= 'a' && x <= 'z' || 
            x >= 'A' && x <= 'Z' ||
            x >= '0' && x <= '9')
        return 1;

    return 0;
}

void expand(char s[],char t[]){
    int fill,count;
    int i,j,gap;
    char pre;

    j = 0;
    pre = s[0];
    count = 0;
    for(i = 0; s[i] != '\0';i++) {
        if(i > 0) pre = s[i-1];

        if(s[0] == '-' && is_letter(s[1]))
            count = 1;

        if(s[i] == '-' && pre == ' ')
            count = 1;
        //printf("%c \n",s[i+1]);
        if(s[i] == '-' && is_letter(pre) && 
                is_letter(s[i+1]) && count == 0)
        {
            //printf("I'm in!!! \n");
            if(pre < s[i+1]){
                for(gap = s[i+1] - pre, fill = 1; 
                        fill < gap;fill++)
                {
                    t[j++] = pre + fill;
                    //printf("111 \n");
                }
            }else if(pre > s[i+1]){
                for(gap = pre - s[i+1],fill = 1;
                        fill < gap; fill++)
                {
                    t[j++] = pre - fill;
                    //printf("222 \n");
                } 
            }else
                i++;
            
            count = 0;  
        }else if(s[i] == '-' && is_letter(pre) &&
                    is_letter(s[i+1]) && count == 1)
        {
            printf("I'm in!!! \n");
            if(pre < s[i+1]){
                t[j-1] = s[i+1];
                for(gap = s[i+1] - pre, fill =1;
                        fill < gap; fill++)
                    t[j++] = s[i+1] - fill;
                t[j++] = pre;
                i++;
            }else if(pre > s[i+1]){
                t[j-1] = s[i];
                for(gap = pre - s[i+1], fill = 1;
                        fill < gap; fill++)
                    t[j++] = s[i] + fill;
                t[j++] = s[i+1];
                i++;
            }else
                i++;
            count = 0;
        }
        else
            t[j++] = s[i];

    } 
}
