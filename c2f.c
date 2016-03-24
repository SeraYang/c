#include <stdio.h>

//main(){
//    int fahr, celsius;
//    int lower, upper, step;
//
//    lower = 0;  //lower limit of temperature scale
//    upper = 300; //upper limit of temperature scale
//    step = 20; // step size
//
//    fahr = lower;
//    while(fahr <= upper){
//        celsius = 5 *(fahr-32) / 9;
//        printf("%d \t %d \n", fahr, celsius);
//        fahr = fahr + step;
//    }
//}
main(){
    int fahr;
    for(fahr=300;fahr>=0;fahr = fahr-20)
        printf("%3d %10.1f \n", fahr, (5.0/9.0)*(fahr-32));
}
