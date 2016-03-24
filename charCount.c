#include <stdio.h>

/* count characters in input; 1st version */

//main()
//{
//    int nc;
//
//    nc = 0;
//    while(getchar() != EOF) 
//        nc += 1;
//    printf("%d \n", nc);
//
//}

//main(){
//    double nc;
//    for(nc = 0;getchar()!=EOF; ++nc)
//        //;
//    printf("%.0f\n", nc);
//}

//main(){
//    // Count the numbers of inputs which is either newline, tab, or blank.
//    int c,nl,bl,tl;
//
//    nl = 0;
//    bl = 0;
//    tl = 0;
//    char x = 'g';
//    while((c = getchar()) != EOF){
//        if(c == '\n')
//            ++nl;
//        if(c=='\t')
//            ++tl;
//        if(c == ' ')
//            ++bl;
//    }
//    printf("The number of newlines is %d\n",nl);
//    printf("The number of blanks is %d\n",bl);
//    printf("The number of tabs is %d\n",tl);
//    printf("%c\n",x);
//}
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
