#include <stdio.h>

double atof(char s[]);

main(){
    char s[20];
    double d;

    s[0] = '1';
    s[1] = '2';
    s[2] = '5';
    s[3] = '7';
    s[4] = '.';
    s[5] = '8';
    s[6] = '0';
    s[7] = '\0';

    d = atof(s);
    printf("%f \n",d);
}

double atof(char s[]){
    double val, power;
    int i,sign;

    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.')
        i++;
    for(power = 1.0;isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
        power *= 10;
    return sign * val /power;

}
