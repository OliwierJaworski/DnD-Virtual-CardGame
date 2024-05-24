#include "Data-Related.h"

int fetch_url_data(char * url)
{
   CURL *curl = curl_easy_init(); 
    CURLcode res;
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Json_Data_CB);
        if(curl_easy_perform(curl))
        {
          throw_error("failed to fetch data from server:",NOT_FOUND);
        }
    }
    else throw_error("failed to initialize curl:",INTERNAL_ERROR);
    curl_easy_cleanup(curl);
    return OK;
}

size_t Json_Data_CB(void *data, size_t size, size_t nmemb, void *clientp)
{
  size_t realsize = size * nmemb;
  struct memory *mem = (struct memory *)clientp;
 
  char *ptr = realloc(mem->response, mem->size + realsize + 1);
  if(!ptr)
    throw_error("failed to allocate memory:",INTERNAL_ERROR);
 
  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;
  return realsize;
}

void Json_Parse(struct item_T *item, char* stream){
  size_t CATCount=0;
  char** category_ptr = (char**) calloc(CATCount,sizeof(char*));
  char* bufferPTR=NULL;
  category_ptr[CATCount] = strchr(stream,'{');
  printf("size of char** : %zu",sizeof(category_ptr));
  

  while( (bufferPTR = strchr(category_ptr[CATCount]+1,'{')) != NULL) {
      CATCount++;
      category_ptr = realloc(category_ptr, (CATCount+1) * sizeof(char*));
      category_ptr[CATCount] = bufferPTR;
  }
  printf("\n%s\n",category_ptr[2]);
 
  /*

 
  

       for(int i; i< CATCount; i++){
      
  }
      
      category_ptr[CATCount] = calloc(1,sizeof(char*));
      category_ptr[CATCount] = bufferPTR;

*/


/*
  

      while( strchr(categories_ptr[categories-1]+1,'{') != NULL ) {
            printf("\nis working still111!!\n");
            categories_ptr[0]= malloc(sizeof(char*));
            categories_ptr[categories-1] = strchr(categories_ptr[categories-1]+1,'{');
            categories++;
            printf("\nis working still222!!\n");
            categories_ptr = ((sizeof(categories_ptr) / sizeof(char*)) < categories-1)? realloc(categories_ptr, categories): categories_ptr;
      }
      for(int cat=0; cat< categories; cat++){
            printf("%c\n",categories_ptr[cat]);
      }*/
}



char* substr_to_Scope(int indent, char** destination){

      
}

      


  /*fetch_url_data(item->item_url);
  printf("\nresponse:%s\n",chunk.response);

  if(chunk.response != NULL){
  free(chunk.response);
  chunk.response= NULL;
  chunk.size=0;
  }*/

void throw_error(char * err_msg, int err_code){
  perror(err_msg);
  exit(err_code);
}

