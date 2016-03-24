#include <stdio.h>

#define MAXLINE 1024
#define NAME "yangyifan"

double atof(char[]);

main(){
    int i = 0;
    double d = 0;
    char s[MAXLINE];
    char c;

    //printf("%d \n",MAXLINE);
    //printf("%s \n",NAME);
    while((c = getchar()) != EOF){
        i = 0;
        s[i++] = c;
        while((c = getchar()) != EOF && c != '\n'){
            s[i++] = c;
        }
        s[i] = '\0';
        d = atof(s);
        printf("%f \n",d);
    }
    printf("I'm out \n");

}

double atof(char s[]){
    int i,power,sign,exp,divisor;
    double result;

    for(i = 0; isspace(s[i]); i++)
        ;
    if(s[i] == '-' && isdigit(s[i+1])){
        sign = -1;
        i++;
    }else 
        sign = 1;
    for(result = 0.0;isdigit(s[i]);i++)
        result = result * 10 + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 0;isdigit(s[i]);i++){
        result = result * 10 + (s[i] - '0');
        power++;
    }

    //printf("power is %d \n",power);
    if(s[i] == 'e' && s[i+1] == '-' ||
            s[i] == 'E' && s[i+1] == '-'){
        for(i+=2,exp = 0;isdigit(s[i]);i++)
            exp = exp * 10 + (s[i] - '0');
        power += exp;
        for(divisor = 1;power > 0; power--)
            divisor *= 10;
        result = sign * result / divisor; 
    }else if(s[i] == 'e' && s[i+1] == '+' ||
            s[i] == 'E' && s[i+1] == '+'){
        for(i+=2,exp = 0;isdigit(s[i]);i++)
            exp = exp * 10 +(s[i] - '0');
        power -= exp;
        if(power >= 0) {
            for(divisor = 1; power > 0; power--)
                divisor *= 10;
            result = sign * result / divisor;
        }else{
            for(divisor = 1; power < 0; power++)
                divisor *= 10;
            result = sign * result * divisor;
        }
    }else{
        for(divisor = 1;power > 0; power--)
            divisor *= 10;
        //printf("divisor is %d \n", divisor);
        //printf("sign is %d \n", sign);
        //printf("result is %f \n", result);
        result = sign * result / divisor;
    }
    //printf("%f \n",result);
    return result;
}
