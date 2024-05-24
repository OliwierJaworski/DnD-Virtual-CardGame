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
  category_ptr[CATCount] = strpbrk(stream,"{}");

  while( (bufferPTR = strpbrk(category_ptr[CATCount]+1,"{}")) != NULL) {
      CATCount++;
      category_ptr = realloc(category_ptr, (CATCount+1) * sizeof(char*));
      category_ptr[CATCount] = bufferPTR;
  }

  for( int elem =1; elem<=CATCount; elem++ ){
      int maxchar=category_ptr[elem]-stream; 
      printf("\n");

      for(int i=category_ptr[elem-1]-stream;i<=maxchar; i++){
            printf("%c",stream[i]);
      }
  }

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

