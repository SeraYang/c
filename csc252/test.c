#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(){
    char * name = "yangyifan";
    
    printf("%s \n",name);
    free(name);
}
