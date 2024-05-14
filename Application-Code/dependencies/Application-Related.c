#include "Application-Related.h"
#include "Player-Related.h"
void ARG_Parser(int* argc, char* argv[])
{
    if(*argc ==1){
        printUsage(argv[0]);
    }
    else{
        static int c_arg_pos;
        for(c_arg_pos =0; c_arg_pos < *argc; c_arg_pos++){
            if(argv[c_arg_pos][0] == '-')
            {
               char arg_option = (argv[c_arg_pos][1] == '-') ? optionTOchar(&argv[c_arg_pos][2]) : argv[c_arg_pos][1];
               switch (arg_option)
               {
               case 'm':
                    struct Float_Nleftover RESULT;
                    while(strstr(argv[c_arg_pos],".json")==NULL && (RESULT = TO_FLOAT(argv[c_arg_pos])).leftover != NULL)
                    {   
                        printf("result value: %f, result leftover:%s",RESULT.value,RESULT.leftover);
                        c_arg_pos++;
                    }
                    
                    break;
               case 'w':
                  printf("arg :w\n");
                break;
               case 'h':
               printf("arg :h\n");
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
            }else if(argv[c_arg_pos][0] -'0' <=9 && argv[c_arg_pos][0] -'0' >=0)
            {
                
            }
            
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
bool iscoin(char* arg)
{

}
bool isitem(char* arg)
{

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