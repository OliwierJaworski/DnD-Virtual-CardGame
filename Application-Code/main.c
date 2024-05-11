#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dependencies/Data-Related.h"

int main(){
    FILE * fileptr = fopen("equipment.txt","w");
    fetch_url_data(DND_EQUIPMENT_URL, fileptr);
    return 0;
}



