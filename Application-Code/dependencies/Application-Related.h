#ifndef Application_Related 
#define Application_Related 

#include "Data-Related.h"
#include "Debug-Related.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
typedef void (*cleanup_ritual) ( void );
typedef void (*update_screen) ( struct item_T* items );

 void ARG_Parser  (int* argc, char** argv);
 void printUsage  ( char *programName );
 char optionTOchar(char * option);
float Str_To_Float( char * source_STR, char** excluded_STR );
 bool arg_isitem  ( char* arg );
 bool arg_iscoin  ( char *arg );
 void parse_item  ( char* arg , int item_amount); 
 void free_alloc  ( void );

 struct item_T* LL_PUSH();
 struct item_T* LL_POP();
 struct item_T* LL_CYCLE();
 void userdisplay(struct item_T* displayedItem);
 void userinteraction(update_screen screenfunc,struct item_T* Citem);
#endif



