#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"



struct Inventory Player_inv;
struct memory chunk;
bool keepalive= false;

int main( int argc, char *argv[] )
{   
    cleanup_ritual cleanup= free_alloc;
    atexit(cleanup);
    ARG_Parser( &argc, argv );

    struct item_T* Viewed_Item = Player_inv.items;
    userinteraction(userdisplay,Viewed_Item);
    while(keepalive){
        userinteraction(userdisplay,Viewed_Item);
    }

    return 0;
}
