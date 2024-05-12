#include "Data-Related.h"

int fetch_url_data(char * url, FILE * filepointer_CC)
{
    CURL *curl = curl_easy_init();
    struct memory chunk = {0};  
    CURLcode res;
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Data_CallBack);
        if(curl_easy_perform(curl))
        {
          throw_error("failed to fetch data from server:",NOT_FOUND);
        }
    }
    else throw_error("failed to initialize curl:",INTERNAL_ERROR);
    curl_easy_cleanup(curl);
    fwrite(chunk.response, sizeof(char),chunk.size, filepointer_CC);
    fclose(filepointer_CC);
    return OK;
}

size_t Data_CallBack(void *data, size_t size, size_t nmemb, void *clientp)
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

void throw_error(char * err_msg, int err_code){
        perror(err_msg);
        exit(err_code);
}

