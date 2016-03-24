#include <stdio.h>
#include <string.h>

main(){
    int i = 0;

    char *t = "yangyifan";
    char *s = "\0";

    //for(i = 0;t[i] != '\0';i++){
    //    printf("%c \n",t[i]);
    //}
    printf("%d \n",strend1(t,s));
}

int strend1(char *s, char *t){
    if(strlen(t) > strlen(s))
        return 0;
    
    int i,j;
    int status=0;

    for(i = 0,j = 0;s[i] != '\0';i++){
        if(s[i] == t[j]){
            j++;
            status = 1;
        }else{
            j = 0;
            status = 0;
        }
        
    }
    if(t[j] == '\0' && status == 1)
        return 1;
    else
        return 0;
}
