#ifndef Data_Related 
#define Data_Related 
#define DND_EQUIPMENT_URL "https://www.dnd5eapi.co/api/equipment/"
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include "Player-Related.h"
#define JSON_EXAMPLE "{\"desc\":[],\"special\":[],\"index\":\"shield\",\"name\":\"Shield\",\"equipment_category\":{\"index\":\"armor\",\"name\":\"Armor\",\"url\":\"/api/equipment-categories/armor\"},\"armor_category\":\"Shield\",\"armor_class\":{\"base\":2,\"dex_bonus\":false},\"str_minimum\":0,\"stealth_disadvantage\":false,\"weight\":6,\"cost\":{\"quantity\":10,\"unit\":\"gp\"},\"url\":\"/api/equipment/shield\",\"contents\":[],\"properties\":[]}"

//data-types
enum ACK_TYPE{
    OK =200,
    NOT_FOUND =404,
    INTERNAL_ERROR = 500
};

extern struct memory {
  char *response;
  size_t size;
}chunk;

struct item_details{
  char* name;
  char* description;
  int value;
  struct item_details* next;
};


struct item_T{
  char* item_url;
  char* name;
  int amount;
  struct item_details* item_details;
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
int fetch_url_data(char * url);
void Json_Parse(struct item_T *item, char* stream);
size_t Json_Data_CB(void *data, size_t size, size_t nmemb, void *clientp);
void throw_error(char * err_msg, int err_code);

#endif





