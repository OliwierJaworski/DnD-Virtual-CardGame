#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"
#include "dependencies/Player-Related.h"


struct Inventory Player_inv;
struct memory chunk;

int main( int argc, char *argv[] )
{   
    void (*cleanup_ritual) ( void ) = free_alloc;
    atexit(cleanup_ritual);

    ARG_Parser( &argc, argv );
    struct item_T* Curr_Item = Player_inv.items;
    //while(Curr_Item != NULL){
        Json_Parse( Curr_Item, JSON_EXAMPLE );
        //Curr_Item =Curr_Item->next_item;
    //}
    free_alloc();
    return 0;
}
