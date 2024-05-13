#include "Application-Related.h"

void ARG_Parser(int* argc, char* argv[])
{
    if(*argc ==1){
        printUsage(argv[0]);
    }
    else{
        for(int c_arg =0; c_arg < *argc; c_arg++){
            if(argv[c_arg][0] == '-'){
               char arg_option = (argv[c_arg][1] == '-') ? optionTOchar(&argv[c_arg][2]) : argv[c_arg][1];
               switch (arg_option)
               {
               case 'm':
               printf("arg :m\n");
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
               } 
        }
    }
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