#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"


struct Inventory Player_inv;
struct memory chunk;
bool keepalive= true;

int main( int argc, char *argv[] )
{   
    void (*cleanup_ritual) ( void ) = free_alloc;
    atexit(cleanup_ritual);
    ARG_Parser( &argc, argv );

    while(keepalive){
        userdisplay();
        userinteraction();
    }
    
    free_alloc();
    return 0;
}
