/* show what is the bit fields */
#include <stdio.h>
#include <string.h>
/* define simple structure */
struct{  
    unsigned int widthValidated;  
    unsigned int heightValidated;
} status1;
struct{  
    unsigned int age : 3;
} Age;

/* define a structure with bit fields */
struct{  
    unsigned int widthValidated : 1;  
    unsigned int heightValidated : 1;
} status2; 

int main(){   
    printf( "Memory size occupied by status1 : %d\n", sizeof(status1));   
    printf( "Memory size occupied by status2 : %d\n", sizeof(status2));

    /* if the assignment extends
     * the boundary.......
     */
    printf("Below is to show an error when out of the bit-fields: \n");
    Age.age = 4;   
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );   
    printf( "Age.age : %d\n", Age.age );

    Age.age = 7;   
    printf( "Age.age : %d\n", Age.age );

    Age.age = 8;  // the output will be 0
    printf( "Age.age : %d\n", Age.age );

    return 0;

}

