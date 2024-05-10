#include "Data-Related.h"

int fetchdata(char * addr_begin, int addr_str_length, FILE * filepointer_CC){
    fprintf(filepointer_CC, "hello world\n");
    fclose(filepointer_CC);
}