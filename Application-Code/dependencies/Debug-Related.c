#ifdef debug
#include "Debug-Related.h"

 void loop_ITEMLIST( struct item_T* item ){
    while( item != NULL ){
       printf("LinkedList, item name  :%s\n",item->name);
       printf("LinkedList, item amount:%d\n",item->amount);
       item= item->next_item;
    }
 }
  void loop_COINLIST( struct Coin_T* coin ){
    while( coin != NULL ){
       printf("LinkedList, item name  :%s\n",coin->currency);
       printf("LinkedList, item amount:%d\n",coin->amount);
       coin= coin->next_coin;
    }
 }
 void Return_PRINTF(bool arg_state, char* iftrue, char* iffalse ){
    if(arg_state){
        printf("%s",iftrue);
    } else  printf("%s",iffalse);
 }

#endif