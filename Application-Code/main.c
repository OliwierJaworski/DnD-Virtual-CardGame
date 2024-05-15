#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependencies/Data-Related.h"
#include "dependencies/Application-Related.h"
#include "dependencies/Player-Related.h"


int free_alloc( void );

struct Inventory Player_inv;

int main(int argc, char *argv[])
{
//setup
    
    ARG_Parser(&argc, argv);

//program
    
    

//cleanup
    return free_alloc;
}

int free_alloc( void )
{
    /*TO DEALLOC!!*/
    /*
    1.CurrentC->currency
    2.
    */
    struct Coin_T* old_coin =NULL;
    struct Coin_T* next_coin = Player_inv.Coins->next_coin;
    
    while(next_coin != NULL)
    {
        old_coin= next_coin;
        next_coin = next_coin->next_coin;
        free(old_coin);
    };
    Player_inv.Coins =NULL;

    struct item_T* old_item =NULL;
    struct item_T* next_item = Player_inv.items->next_item;
    while(next_item != NULL)
    {
        old_item= next_item;
        next_item = next_item->next_item;
        free(old_item);
    };
    Player_inv.items =NULL;

    return 0;
}

//FILE * fileptr = fopen("equipment.txt","w");          --DEBUG
    //fetch_url_data(DND_EQUIPMENT_URL, fileptr);           --DEBUG