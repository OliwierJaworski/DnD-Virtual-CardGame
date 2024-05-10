#include <stdio.h>

#include "dependencies/Data-Related.h"

int main(){
    FILE * fileptr = fopen("equipment.txt","w");
    fetchdata(NULL,1,fileptr);
    return 0;
}

 