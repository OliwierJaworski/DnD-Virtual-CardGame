#ifndef Application_Related 
#define Application_Related 

#include "Data-Related.h"
#include "Debug-Related.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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
 void userdisplay();
 void userinteraction();
#endif



