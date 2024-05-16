#include "Player-Related.h"

struct Float_Nleftover Str_To_Float(char * convert_string)
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
    *datadump = Str_To_Float(arg);
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

                    else if( arg_isitem( argv[c_arg_pos]) )
            {
                parse_item(argv[c_arg_pos],1);
            }
             else if( ( argv[c_arg_pos][0] -'0' <=9 && argv[c_arg_pos][0] -'0' >=0 ) )
            {
                bool item_supplied = ( c_arg_pos < *argc && arg_isitem( argv[c_arg_pos+1] ) );
                if(item_supplied)
                {
                   parse_item(argv[c_arg_pos+1],argv[c_arg_pos][0]-'0');
                } 
                else 
                {
                    printUsage( argv[0] );
                    exit(0);
                }
                printf("argument is a digit!\n");
            }    


            /*
-w 180.75 
greatsword.json 
-m 4gp 42sp 69cp 
22 explorers-pack.json
-c camp.log 
small-knife.json 
2 waterskin.json 
leather-armor.json 
*/