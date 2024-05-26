#ifdef debug
#include "Application-Related.h"
#include "Data-Related.h"

#include <stdbool.h>

void loop_ITEMLIST( struct item_T* item );
void loop_COINLIST( struct Coin_T* coin );
void Display_Weight( float weight );
void Return_Bstate( bool arg_state, char* iftrue, char* iffalse );
#endif
