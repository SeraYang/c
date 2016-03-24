#include <stdio.h>

main(){
    int i,sign,sum;
    char c;

    sign = sum = 0;
    while((c = getchar()) != EOF){  // the "tab" input equals EOF.
        if(sign == 0 && c == '0') sign++;
        if(sign == 1 && c == 'X' || sign == 1 && c == 'x') sign++;
        if(sign > 1 && c >= '0' && c <= '9') 
            sum = sum * 16 + (c - '0');
        if(sign > 1 && c >= 'A' && c <= 'F')
            sum = sum * 16 + 10 + (c - 'A');
        if(sign > 1 && c >= 'a' && c <= 'f')
            sum = sum * 16 + 10 + c - 'a';

        if(c == '\n') {
            if(sum > 0) printf("%d \n", sum);
            sign = sum = 0;
        }
    }
}
