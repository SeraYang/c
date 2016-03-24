/* *******************************************************
 * In this program, it's to count the length of each word.
 * Then give histogram.
 * Use array to store the  amount of each length.
 * 
 * ********************************************************/
#include <stdio.h>
#define MAXWORDLEN 10

int main(void)
{
    int c;
    int inspace = 0;
    long lengtharr[MAXWORDLEN + 1];     // Array whose length is 11;
    int wordlen = 0;
    //int firstletter = 1; // this is useless. Maybe just declare this is the first letter.
    int thisval = 0;
    long maxval = 0;
    int thisidx = 0;
    int done = 0;
    for (thisidx = 0; thisidx <= MAXWORDLEN; thisidx++)
    {
        lengtharr[thisidx] = 0;  // Initialize the array.
    }
/* This is for getting the values from the input stream.
 * 
 * First, get an input character. If the one is a nomal character except for
 * space( ),tab(    ),newline(\n), or EOF(Ctrl + D). It will go to the else 
 * branch. The inspace and firstletter are all not 1. The word length will 
 * increase.
 *
 * Once there is one of these SPECIAL characters, and now, inspace is 0.
 * firstletter = 0 is just a reset.
 * 
 * Inspace = 1 is an assignment to make sure that if the following character
 * is also a SPECIAL character, there is no other actions.
 * 
 * If inspace == 0, reset the inspace = 1;
 * Then judge if the length of the word is larger than the maximum word length.
 *  */
    while (0 == done)
    {
        c = getchar();  // get the character from the input stream;
        if (c == ' ' || c == '\t' || c == '\n' || c == EOF){
            if (inspace == 0){
                //firstletter = 0;
                inspace = 1;
                if (wordlen <= MAXWORDLEN){
                    if (wordlen > 0){   // This just make sure the word has a length.
                        thisval = ++lengtharr[wordlen - 1];
                        if (thisval > maxval){  // Just as below, always keep maxval is the max value which is useful in printing the graph from top to bottom.
                            maxval = thisval;
                        }
                    }
                }else{
                    thisval = ++lengtharr[MAXWORDLEN];
                    if (thisval > maxval){  // This is the same like above.
                        maxval = thisval;
                    }
                }
            }
            if (c == EOF){
                done = 1;
            }
        }else{
            if(inspace == 1){
            //if (inspace == 1 || firstletter == 1){
                wordlen = 0;    // Reset this variable and count word from start.
                //firstletter = 0; // 
                inspace = 0;
            }
            ++wordlen;
            //printf("I'm in!!!!");
        }
    }

    for (thisval = maxval; thisval > 0; thisval--){
        printf("%4d  |", thisval);  // print the y-axis and the scales.
        for (thisidx = 0; thisidx <= MAXWORDLEN; thisidx++){
            //if (lengtharr[thisidx] >= thisval){ // check from the max to 0. This will ensure the graph printed correctly.
            if(thisval <= lengtharr[thisidx]){ // print "*" as long as the scale is less than the number in Array lengtharr[thisidx].
                printf(" * ");
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }


/********************************************************************/
    printf("      +");      // This is to print the origin of the coordinate.
    for (thisidx = 0; thisidx <= MAXWORDLEN; thisidx++){ // This is to print the x-axis.
        printf("---");
    }

    printf("\n       ");
    for (thisidx = 0; thisidx <= MAXWORDLEN; thisidx++){
        printf("%2d ", thisidx + 1);
    }
    printf(">%d\n", MAXWORDLEN);
    return 0;
}
