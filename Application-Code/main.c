#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"
#include "dependencies/Player-Related.h"

struct Inventory Player_inv;

int main( int argc, char *argv[] )
{
    
    FILE * fileptr =NULL;
    void (*cleanup_ritual) ( void ) = free_alloc;
    atexit(cleanup_ritual);

    ARG_Parser( &argc, argv );
    fileptr =fopen("equipmentlist.txt","r+");
    fileptr = (!fileptr) ? fopen("equipmentlist.txt","w+") :fileptr;
    if( (fgetc( fileptr )) == EOF ){
        //fetch_url_data(DND_EQUIPMENT_URL, fileptr);
    } 
    fclose(fileptr); 
    return free_alloc;
}
