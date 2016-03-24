#include <stdio.h>

main()
{
    int c,item;
    item = 0;

    while((c = getchar()) != EOF){
        if(c!=' ') item = 0;
        if(c==' ') ++item;
        if( item < 2){
            putchar(c);   
        }
    }
}
