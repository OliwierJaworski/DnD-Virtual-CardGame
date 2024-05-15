#include "Application-Related.h"
#include "Player-Related.h"
void ARG_Parser(int* argc, char** argv)
{
    if(*argc ==1){
        printUsage(argv[0]);
    }
    else{
        for(int c_arg_pos =1; c_arg_pos < *argc; c_arg_pos++)
        {
            if(argv[c_arg_pos][0] == '-') 
            {
               char arg_option = (argv[c_arg_pos][1] == '-') ? optionTOchar(&argv[c_arg_pos][2]) : argv[c_arg_pos][1];
               switch (arg_option)
               {
               case 'm':
                    c_arg_pos++;
                    struct Float_Nleftover Temp_CoinData;
                    Player_inv.Coins = malloc(sizeof(struct Coin_T));
                    struct Coin_T* CurrentC =Player_inv.Coins;
                    while(c_arg_pos < *argc && arg_iscoin(argv[c_arg_pos],&Temp_CoinData) && !arg_isitem(argv[c_arg_pos]))
                    {
                        CurrentC->amount = Temp_CoinData.value;
                        CurrentC->currency = malloc(sizeof(strlen(Temp_CoinData.leftover)+1));
                        strcpy(CurrentC->currency,Temp_CoinData.leftover);
                        CurrentC->next_coin = malloc(sizeof(struct Coin_T));
                        CurrentC = CurrentC->next_coin;
                        c_arg_pos++;
                    }
                    CurrentC =NULL;
                    #ifdef debug
                    //tests if the values are correctly saved
                        CurrentC =Player_inv.Coins;
                        while(CurrentC->next_coin != NULL)
                        {
                            printf("value stored in linkedlist :%d\n",CurrentC->amount);
                            CurrentC = CurrentC->next_coin;
                        }
                    #endif
                    break;
               case 'w':
                  printf("arg :w\n");
                break;
               case 'h':
                    printUsage( argv[0] );
                    exit(0);
                break;
               case 'c':
                    printf("arg :c\n");
                break;
               case 'x':
                    printf("arg :x\n");
                break;
               default:
                break;
               }
            }
            else if( arg_isitem( argv[c_arg_pos]) )
            {
                parse_item(argv[c_arg_pos],1);
            }
             else if( ( argv[c_arg_pos][0] -'0' <=9 && argv[c_arg_pos][0] -'0' >=0 ) )
            {
                bool item_supplied = ( c_arg_pos < *argc && arg_isitem( argv[c_arg_pos+1] ) );
                if(item_supplied)
                {
                   parse_item(argv[c_arg_pos],1);
                } 
                else 
                {
                    printUsage( argv[0] );
                    exit(0);
                }
                printf("argument is a digit!\n");
            }    
        }
         struct item_T* current_item = Player_inv.items;
         while(current_item->next_item != NULL)
        {
           printf("value stored in linkedlist :%s\n",Player_inv.items->name);
           current_item = current_item->next_item;
        }
    }
}
char optionTOchar(char * option){
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

struct Float_Nleftover TO_FLOAT(char * convert_string)
{
    struct Float_Nleftover RESULT;
    RESULT.value = 0;
    RESULT.leftover =NULL;
    int C_char=0;
    while(convert_string[C_char] != '\0')
    {
        if(convert_string[C_char] -'0' <=9 && convert_string[C_char] -'0' >=0)
        {
            RESULT.value= (RESULT.value * 10) + (convert_string[C_char] -'0');
        }else 
        {
            RESULT.leftover = &convert_string[C_char]; 
            return RESULT;
        }
        C_char++;
    }
    return RESULT;
}

bool arg_iscoin(char* arg, struct Float_Nleftover* datadump)
{   
    *datadump = TO_FLOAT(arg);
    bool result = (datadump->leftover != NULL && datadump->value !=0);
    if(result)
    {
        printf("iscoin!");
    }
    return result;
}

bool arg_isitem(char* arg)
{
   bool result = (strstr(arg,".json")!=NULL) ? true : false;
   if(result) printf("isitem\n"); else printf("isnotitem\n");
   return result;
}
void parse_item( char* arg , int item_amount)
{
    Player_inv.items = (Player_inv.items == NULL)? malloc(sizeof(struct item_T)): Player_inv.items;
    struct item_T* curr_item = Player_inv.items;
    while(curr_item->next_item != NULL)
    {
      curr_item = curr_item->next_item;
    }
    curr_item->next_item = malloc(sizeof(struct item_T));
    curr_item = curr_item->next_item;
    char filename[strlen(arg)+1];
    strcpy(filename, arg);
    char *loc = strstr(filename, ".json");
    if(loc != NULL) 
    {
        *loc = '\0';
    }
    curr_item->name = malloc(strlen(filename)+1);
    strcpy(curr_item->name, filename);
    curr_item->amount = item_amount;
    printf("\nitem name: %s\n", filename);
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
   if(Player_inv.Coins != NULL)
   {
    struct Coin_T* old_coin =NULL;
    struct Coin_T* next_coin = Player_inv.Coins->next_coin;
    
    while(next_coin != NULL)
    {
        old_coin= next_coin;
        next_coin = next_coin->next_coin;
        free(old_coin);
    };
    Player_inv.Coins =NULL;
   }

   if(Player_inv.items != NULL)
   {
    struct item_T* old_item =NULL;
    struct item_T* next_item = Player_inv.items->next_item;
    while(next_item != NULL)
    {
        old_item= next_item;
        next_item = next_item->next_item;
        free(old_item);
    };
    Player_inv.items =NULL;
   }
    return 0;
}