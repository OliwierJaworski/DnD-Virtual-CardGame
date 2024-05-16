#include "Application-Related.h"
#include "Player-Related.h"
void ARG_Parser(int* argc, char** argv)
{
    if(*argc ==1){
        printUsage(argv[0]);
    }
    else{
        for(int c_argc =1; c_argc < *argc; c_argc++)
        {
            if( argv[c_argc][0] == '-'){
               char arg_option = (argv[c_argc][1] == '-') ? optionTOchar(&argv[c_argc][2]) : argv[c_argc][1];
               switch (arg_option)
               {
               case 'm':
                    break;
               case 'w':
                  printf("arg :w\n");
                break;
               case 'c':
                    printf("arg :c\n");
                break;
               case 'x':
                    exit(0);
                break;
                case 'h':
               default:
                    printUsage( argv[0] );
                    exit(0);
                break;
               }
            } else if( argv[c_argc][0] -'0' <=9 && argv[c_argc][0] -'0' >=0 ) {
                if( c_argc+1 == *argc || !arg_isitem(argv[c_argc+1])){ 
                    printUsage( argv[0] );
                    exit(0);
                }
                int item_amount = argv[c_argc][0]-'0';
                c_argc++;
                parse_item( argv[c_argc], item_amount );
                c_argc++;
            }else if( arg_isitem( c_argc ) ){
                parse_item( argv[c_argc], 1 );
            }
        }
        #ifdef debug
               loop_ITEMLIST(Player_inv.items);
        #endif
    }
}
bool arg_isitem(char* arg)
{
    printf("arg : %s\n",arg);
    bool result = (strstr(arg, ".json")); //player can call .jsonn and it would still count -> BUG

   return result;
}
void parse_item( char* arg , int item_amount)
{
     #ifdef debug
               printf("parse_item function is called");
     #endif
    struct item_T* C_item;
    char filename[strlen(arg)+1];
    strcpy(filename, arg);

    if(Player_inv.items == NULL) {
        Player_inv.items = malloc(sizeof(struct item_T));
        C_item = Player_inv.items;
    } else {
        C_item = Player_inv.items;
        while(C_item->next_item != NULL) {
            C_item = C_item->next_item;
        }
        C_item->next_item = malloc(sizeof(struct item_T));
        C_item = C_item->next_item;
    }

    C_item->name = malloc(strlen(filename)+1);
    char *loc = strstr(filename, ".json");
    if(loc != NULL){
        *loc = '\0';
    }
    strcpy(C_item->name, filename);
    C_item->amount = item_amount;
}
char optionTOchar( char * option ){
    if( strcasecmp( "money", option ) == 0 )
        return 'm';
    if( strcasecmp( "max-weight", option ) == 0 )
        return 'w';
    if( strcasecmp( "camp-file", option ) == 0 )
        return 'c';
    if( strcasecmp( "help", option ) == 0 )
        return 'h';
    if( strcasecmp( "cancel ", option ) == 0 )
        return 'x';
}
void printUsage( char *programName )
{
	printf( "Usage : %s equipment-files [number-of-items] [-w max-weight] [-m money] [-c camp-file]\n"
	        "Options:\n"
	        "  number-of-items <number>          Optional per file to define the number in the inventory\n"
	        "  -m --money <number><currency>     List of coins and types (cp, sp, ep, gp, pp)\n"
	        "  -w --max-weight <number>          Maximum weight before becoming encumbered\n"
	        "  -c --camp-file <filename.log>     Optional camp file for all discovered items during play that stay in camp\n"
	        "  -h --help                         Print this help menu.\n"
            "  -x --cancel                       exit the application\n",
	        programName );
}
void free_alloc( void )
{
    /*TO DEALLOC!!*/
    /*
    1.CurrentC->currency
    2.CurrentC->item_t
    */
   if(Player_inv.Coins != NULL){
      struct Coin_T* old_coin =NULL;
      struct Coin_T* next_coin = Player_inv.Coins->next_coin;
      while(next_coin != NULL){
        old_coin= next_coin;
        next_coin = next_coin->next_coin;
        free(old_coin);
      };
    Player_inv.Coins =NULL;
   }

   if(Player_inv.items != NULL){
      struct item_T* old_item =NULL;
      struct item_T* next_item = Player_inv.items->next_item;
      while(next_item != NULL){
        old_item= next_item;
        next_item = next_item->next_item;
        free(old_item);
      };
    Player_inv.items =NULL;
   }
    return 0;
}
