#ifndef Data_Related 
#define Data_Related 

#include <curl/curl.h>

//data-types
enum ACK_TYPE{
    OK =200,
    NOT_FOUND =403,
};

//functions
int fetchdata(char * addr_begin, int addr_str_length, FILE * filepointer_CPY);

#endif