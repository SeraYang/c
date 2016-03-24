#include <stdio.h>

main(){
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }
   // if(getchar()!=EOF) printf("true \n");
   // else printf("false \n");

   // printf("%d \n",EOF);

}
