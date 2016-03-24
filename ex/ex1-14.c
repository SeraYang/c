#include <stdio.h>

main(){
    int alpha[26];
    int c,i,total;

    total = 0;
    for(i = 0;i<26;i++){
        alpha[i] = 0;
    }

    while((c = getchar()) !=EOF){
        //printf("%d ",c);
        if(c > 64 && c < 91){
            alpha[c-65]++;
            total++;
        }
        if(c > 96 && c < 123){
            alpha[c-97]++;
            total++;
        }
    }

    for(i = 0;i<26;i++) printf("%d ",alpha[i]);
    printf("\n");
    printf("total is %d \n", total);

    /* Below is the print histogram code */
    if(total > 0){
        int percent[26];
        int acc; 
        acc = 0;

        for(i = 0;i<26;i++) {
            percent[i] = alpha[i]*1000/total;
            printf(" %d",percent[i]);
            acc += percent[i];
        }
        //percent[25] = 1000 - acc;
        printf("\n");
        
        float count = 1;
        int k = 100; // this k is for cut off the final decimal 1
        while(k > 0){
            printf("%.2f |",count);
            //printf("%f |",count);
            for(i = 0;i<26;i++){
                if(percent[i] >= count * 1000) printf("* ");
                else printf("  ");
            }
            printf("\n");
            count -= 0.01;
            k -= 1;
        }
        printf("   0 +");
        for(i = 0;i<26;i++) printf("--");
        printf("\n");
        
        /* Below there is for print the x-axis */
        char C;
        C = 65;
        printf("      ");
        for(i = 0;i<26;i++){
            printf("%c ",C);
            C += 1;
        }
        printf("\n");

    }
    
}
