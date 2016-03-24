#include <stdio.h>

main(){
    int c,i,count;
    int index[10];
    c = 0; count = 0;
    for(i = 0;i<10;i++){
        index[i] = 0;
    }
    while((c=getchar())!=EOF){
        if(c=='\t' || c == ' ' || c == '\n'){   // c=="\t" is incorrect
            if(count > 0 && count<10){
                ++index[count-1];
                count = 0;
            }
            if(count>9) ++index[9];
        }else{
            ++count;
        }
    }

    for(i = 0;i<10;i++){
        printf(" %d",index[i]);
    }
    printf("\n");

    printf(">10 |");
    for(i=0;i<10;i++){
        if(index[i] > 10) printf(" * ");
        else printf("   ");
    } printf("\n");

    printf("  9 |");
    for(i=0;i<10;i++){
        if(index[i] == 9) printf(" * ");
        else printf("   ");
    } printf("\n");

    printf("  8 |");
    for(i=0;i<10;i++){
        if(index[i] == 8) printf(" * ");
        else printf("   ");
    } printf("\n");

    printf("  7 |");
    for(i=0;i<10;i++){
        if(index[i] == 7) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  6 |");
    for(i=0;i<10;i++){
        if(index[i] == 6) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  5 |");
    for(i=0;i<10;i++){
        if(index[i] == 5) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  4 |");
    for(i=0;i<10;i++){
        if(index[i] == 4) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  3 |");
    for(i=0;i<10;i++){
        if(index[i] == 3) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  2 |");
    for(i=0;i<10;i++){
        if(index[i] == 2) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("  1 |");
    for(i=0;i<10;i++){
        if(index[i] == 1) printf(" * ");
        else printf("   ");
    } printf("\n");
    
    printf("    +");
    for(i = 0;i<10;i++){
        printf("---");
    }
    printf("\n");

    printf("     ");
    for(i = 0;i<9;i++)printf(" %d ",i+1);
    printf(" >%d",i+1);
    printf("\n");
}
