#include <stdio.h>
main() /* rudimentary calculator */
{
    double sum, v;
    sum = 0;
    //while (scanf("%lf", &v) == 1)
    //    printf("\t%.2f\n", sum += v);
    int day, year;
    char line[100];
    char month[20];
    //scanf("%d %s %d", &day,month,&year);
    //printf("%d %s %d \n",day,month,year);
    while (getline(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); /* 25 Dec 1988 form */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line); /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line); /* invalid form */
    }

    return 0;
}
