#ifndef Application_Related 
#define Application_Related 
#include "Data-Related.h"

#include <math.h>
#include <stdbool.h>
#include <string.h>
struct Float_Nleftover{
    float value;
    char* leftover;
};

void ARG_Parser(int* argc, char*argv[]);
void printUsage( char *programName );
char optionTOchar(char * option);
struct Float_Nleftover TO_FLOAT(char * convert_string);
bool iscoin(char* arg);
bool isitem(char* arg);
#endif



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