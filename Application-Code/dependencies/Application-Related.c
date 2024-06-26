#include "Application-Related.h"


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
                    c_argc++;
                    struct Coin_T* current_C=NULL;

                    if( Player_inv.Coins == NULL ){
                        Player_inv.Coins = malloc( sizeof(struct Coin_T));

                        if (Player_inv.Coins == NULL) {
                        perror("Failed to allocate memory");
                        exit(EXIT_FAILURE);
                        }    
                        current_C = Player_inv.Coins;
                
                    } else {
                        current_C = Player_inv.Coins;
                        while( current_C->next_coin != NULL ){
                         current_C = current_C->next_coin;
                        }
                        current_C->next_coin =malloc(sizeof(struct Coin_T));
                        if (current_C->next_coin == NULL) {
                            perror("Failed to allocate memory");
                            exit(EXIT_FAILURE);
                            }

                        current_C = current_C->next_coin;     
                    }

                    while(c_argc < *argc && arg_iscoin(argv[c_argc]))
                    {
                        current_C->amount = Str_To_Float(argv[c_argc], &current_C->currency); 
                        if( c_argc+1 < *argc && arg_iscoin( argv[c_argc+1] ) ){
                            current_C->next_coin = (current_C->next_coin == NULL)? malloc(sizeof(struct Coin_T)) : current_C->next_coin;
                            if (current_C->next_coin == NULL) {
                            perror("Failed to allocate memory");
                            exit(EXIT_FAILURE);
                            } 
                            current_C = current_C->next_coin;
                            c_argc++;
                        }else break;
                    }
                    break;
               case 'w':
                  
                  if( c_argc+1 < *argc   ){
                  c_argc++;
                  Player_inv.weight = Str_To_Float(argv[c_argc], NULL);}
                break;
               case 'c':
                    printf("Code for arg: c seems to be missing\n");
                break;
                case 'x':
                case 'h':
               default:
                    if(arg_option != 'x') printUsage( argv[0] );
                    exit(0);
                break;
               }
            } else if( argv[c_argc][0] -'0' <=9 && argv[c_argc][0] -'0' >=0 ) {
                if( c_argc+1 == *argc || !arg_isitem(argv[c_argc+1])){ 
                    printUsage( argv[0] );
                    exit(0);
                }
                int item_amount = Str_To_Float(argv[c_argc],NULL);
                c_argc++;
                parse_item( argv[c_argc], item_amount );
            }else if( arg_isitem( argv[c_argc] ) ){
                parse_item( argv[c_argc], 1 );
            }else {
                 printUsage( argv[0] );
                 exit(0);
            }
        }
        struct item_T* Curr_Item = Player_inv.items;
        while(Curr_Item != NULL){
            fetch_url_data(Curr_Item->item_url);
            Json_Parse( Curr_Item, chunk.response);
            #ifdef debug
            printf("\nresponse:%s\n",chunk.response);
            printf("\ncurrent item ptr:%p\n",Curr_Item);
            #endif
            
            Curr_Item =Curr_Item->next_item;
            
            if(chunk.response != NULL){
            free(chunk.response);
            chunk.response= NULL;
            chunk.size=0;
            }
        }
        #ifdef debug
               Display_Weight(Player_inv.weight);
               loop_ITEMLIST(Player_inv.items);
               loop_COINLIST(Player_inv.Coins);
        #endif
    }
}
float Str_To_Float( char * source_STR, char** excluded_STR )
{
    float result =0;
    bool iscomma= false;
    int C_char = 0;
    int quotient=0;
    float wholevalue =0;
    float pointvalue =0;

    while ( source_STR[C_char] != '\0' && ( (source_STR[C_char] -'0' <=9 && source_STR[C_char] -'0' >=0) || source_STR[C_char] == '.') ){
        if( source_STR[C_char] == '.' ){
        iscomma =true;
        C_char++;
        }
        if( !iscomma ){
           wholevalue = ( wholevalue* 10 ) + ( source_STR[C_char] - '0' );
        }else{
            pointvalue = ( pointvalue* 10 ) + ( source_STR[C_char] - '0' );
            quotient++;
        }
      C_char++;
    }
    if( source_STR[C_char] != '\0' && excluded_STR != NULL){ 
    *excluded_STR =&source_STR[C_char]; 
    } 
    pointvalue = pointvalue / ( pow( 10, quotient ) ); 
    result = wholevalue+pointvalue;
    return result;
}

bool arg_isitem( char* arg )
{
    bool result = (strstr(arg, ".json")); //player can call .jsonn and it would still count -> BUG
    return result;
}
bool arg_iscoin( char *arg )
{
    char* currency = NULL; 
    float CoinValue = Str_To_Float(arg, &currency);
    bool result = (currency != NULL && CoinValue != 0);
    return result;
}
void parse_item( char* arg , int item_amount)
{
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

    C_item->item_url = (char*) malloc((strlen(DND_EQUIPMENT_URL)+1+strlen(filename)));
    strcpy(C_item->item_url, DND_EQUIPMENT_URL);
    strcat(C_item->item_url,filename);  
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
    if( strcasecmp( "exit", option ) == 0 )
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
            "  -x --exit                       exit the application\n",
	        programName );
}
void free_alloc( void )
{
   if(Player_inv.Coins != NULL){
      struct Coin_T* current_coin = Player_inv.Coins;
      struct Coin_T* next_coin = NULL;
      while( current_coin != NULL ){
        next_coin= current_coin->next_coin;
        free(current_coin);
        current_coin = next_coin;
      };
    Player_inv.Coins =NULL;

   }
     if(Player_inv.items != NULL){
      struct item_T* current_item =Player_inv.items;
      struct item_T* next_item = NULL;


      while( current_item != NULL ){
        next_item= current_item->next_item;
        
        #ifdef debug
                struct item_details* current_detail = current_item->item_details;
                struct item_details* next_detail= NULL;
                while( current_detail != NULL ){
                printf("key: %s, value:%d, description:%s\n",current_detail->name, current_detail->value,current_detail->description);
                current_detail = current_detail->next;
                }
        #endif
        struct item_details* current_detail = current_item->item_details;
            struct item_details* next_detail = NULL;
            while (current_detail != NULL) {
                next_detail = current_detail->next;
                free(current_detail->name);
                free(current_detail->description);
                free(current_detail);
                current_detail = next_detail;
            }        
        free(current_item->name);
        free(current_item->item_url);
        free(current_item);
        current_item = next_item;
      };
    Player_inv.items =NULL;
   }
   printf("\n"
           "       ________________   ___/-\\___     ___/-\\___     ___/-\\___\n"
           "     / /             ||  |---------|   |---------|   |---------|\n"
           "    / /              ||   |       |     | | | | |     |   |   |\n"
           "   / /             __||   |       |     | | | | |     | | | | |\n"
           "  / /   \\\\         I || |       |     | | | | |     | | | | |\n"
           " (-------------------||   | | | | |     | | | | |     | | | | |\n"
           " ||               == ||   |_______|     |_______|     |_______|\n"
           " ||   CODE TRASH CO  | =============================================\n"
           " ||          ____    |                                ____      |\n"
           "( | o      / ____ \\                                 / ____ \\    |)\n"
           " ||      / / . . \\ \\                              / / . . \\ \\   |\n"
           "[ |_____| | .   . | |____________________________| | .   . | |__]\n"
           "          | .   . |                                | .   . |\n"
           "           \\_____/                                  \\_____/\n");
}

 struct item_T* LL_PUSH(){

 }
 struct item_T* LL_POP(){

 }

struct item_T* LL_CYCLE(struct item_T *current_item) {
    if (current_item == NULL) {
        return NULL;
    }
    return current_item->next_item != NULL ? current_item->next_item : Player_inv.items;
}

 void userdisplay(struct item_T* displayedItem){

struct Coin_T* current_coin = Player_inv.Coins;
     printf("your maximum weightlimit is %f\n",Player_inv.weight);
    printf("this is what you brought with you\n");
    while (current_coin != NULL) {
      printf("Currency: %s, Amount: %d\n", current_coin->currency, current_coin->amount);
         current_coin = current_coin->next_coin;
    }
    printf("\n");
    struct item_details* next_detail= displayedItem->item_details;
    printf("current item         :%s\n",displayedItem->name);
    printf("current item amount  :%d\n",displayedItem->amount);
    printf("item info:\n");
    while( next_detail != NULL ){
    printf("| %s |,description:| %s |,value| %d |\n",next_detail->name,next_detail->description, next_detail->value);
    next_detail = next_detail->next;
    }
 }
 

void userinteraction(update_screen screenfunc, struct item_T* Citem) {
    char command[256];
    while (1) {
        screenfunc(Citem);

        printf("Type 'next' to view the next item or 'exit' to quit: ");
        fgets(command, sizeof(command), stdin);

        
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "next") == 0) {
            Citem = LL_CYCLE(Citem);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
            break;
        } else {
            printf("Invalid command. Please type 'next' to continue or 'exit' to quit.\n");
        }
    }
}
