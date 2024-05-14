#ifndef Data_Related 
#define Data_Related 
#define DND_EQUIPMENT_URL "https://www.dnd5eapi.co/api/equipment"

#include <curl/curl.h>

//data-types
enum ACK_TYPE{
    OK =200,
    NOT_FOUND =404,
    INTERNAL_ERROR = 500
};
struct memory {
  char *response;
  size_t size;
};
struct item_T{
  char* name;
  int amount;
  struct item_T* next_item;
  struct item_T* previous_item;
};
struct Coin_T{
  char* currency;
  int amount;
  struct Coin_T* next_coin;
  struct Coin_T* previous_coin;
};

//functions
   int fetch_url_data(char * url, FILE * filepointer_CC);
size_t Data_CallBack(void *data, size_t size, size_t nmemb, void *clientp);
  void throw_error(char * err_msg, int err_code);
#endif





