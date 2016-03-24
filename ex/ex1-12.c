#include <stdio.h>

main(){
    int c;
    int state = 0;
    while((c = getchar()) != EOF){
        if(c == '\t' || c == ' '){  // Any character here will be ignored.
            state = 1;
        }else {
            if(state == 1) printf("\n");
            /* There should be no branch for the code below.
             * Because no matter what the "state" is, the code
             * below should be excuted.
             * */
            state = 0; 
            putchar(c);
            //printf("%c --- %d \n",c,c);
            //printf("%c",c);
        }
    }
        
}
