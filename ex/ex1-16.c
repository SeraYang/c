#include <stdio.h>

main(){
    int count,max;
    char c;

    count = 0;max = 0;
    while((c = getchar()) != EOF){
        if(c != '\t' && c!=' '){
            if(c == '\n') {
                if(max < count) max = count;
                count = 0;
            }else{
                ++count; 
            }
        }
    }
    printf("%d \n", max);
}
