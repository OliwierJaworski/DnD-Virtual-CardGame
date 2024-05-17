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
       printf("LinkedList, COIN name  :%s\n",coin->currency);
       printf("LinkedList, COIN amount:%d\n",coin->amount);
       coin= coin->next_coin;
    }
 }

 void Display_Weight( float weight ){
   printf("player max-weight is   :%.3f\n",weight);
 }
 void Return_Bstate(bool arg_state, char* iftrue, char* iffalse ){
    if(arg_state){
        printf("%s",iftrue);
    } else  printf("%s",iffalse);
 }

#endif