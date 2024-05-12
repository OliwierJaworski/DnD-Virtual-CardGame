#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"

int main(int argc, char *argv[]){
    for(int c_arg=0; c_arg < argc; c_arg++){
        //printf("argument :%d =%s\n",c_arg, argv[c_arg]);
    }
    ARG_Parser(&argc, argv); 
    //FILE * fileptr = fopen("equipment.txt","w");          --DEBUG
    //fetch_url_data(DND_EQUIPMENT_URL, fileptr);           --DEBUG
    return 0;
}



