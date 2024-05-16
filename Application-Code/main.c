#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"
#include "dependencies/Player-Related.h"

struct Inventory Player_inv;

int main(int argc, char *argv[])
{
    void (*cleanup_ritual) ( void ) = free_alloc;
    atexit(cleanup_ritual);

    ARG_Parser(&argc, argv);

    return free_alloc;
}



//FILE * fileptr = fopen("equipment.txt","w");          --DEBUG
    //fetch_url_data(DND_EQUIPMENT_URL, fileptr);           --DEBUG