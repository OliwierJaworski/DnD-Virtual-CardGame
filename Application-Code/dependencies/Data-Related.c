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

void Json_Parse(struct item_T *item, char* stream) {
    size_t File_EOF = (strrchr(stream, '}') - stream);
    if (!File_EOF) {
        perror("file format not recognised");
        exit(1);
    }

    size_t File_CC = 0;
    char* bufferPTR = NULL;
    char* previosPTR = stream;
    char* str_buffer = NULL;

    while (File_CC <= File_EOF) {
        bufferPTR = strpbrk(previosPTR + 1, ",{");
        if (bufferPTR == NULL) {
            bufferPTR = stream + File_EOF;
        }

        File_CC = bufferPTR - previosPTR;
        str_buffer = (str_buffer == NULL) ? calloc(File_CC + 1, sizeof(char)) : realloc(str_buffer, File_CC + 1);
        if (str_buffer == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }

        strncpy(str_buffer, previosPTR, File_CC);
        str_buffer[File_CC] = '\0';

        char *key = strtok(str_buffer, ":");
        char *value = strtok(NULL, ":");
        if (key) {
            key = strtok(key, "\" \t\n{");
            value = (value != NULL) ? strtok(value, "\" \t\n") : value;

            struct item_details* detail = malloc(sizeof(struct item_details));
            if (detail == NULL) {
                perror("Memory allocation failed");
                exit(1);
            }
            detail->next = NULL;

            if (strcmp(key, "name") == 0 || strcmp(key, "url") == 0) {
                free(detail);
                detail = NULL;
            } else if (value != NULL) {
                int valid_int = 1;
                for (size_t i = 0; i < strlen(value); i++) {
                    if (!isdigit(value[i])) {
                        valid_int = 0;
                        break;
                    }
                }

                detail->name = strdup(key);
                if (valid_int) {
                    detail->value = atoi(value);
                    detail->description = NULL;
                } else {
                    detail->value = -1;
                    detail->description = strdup(value);
                }
            } else {
                detail->name = strdup(key);
                detail->value = -1;
                detail->description = NULL;
            }

            if (detail != NULL) {
                if (item->item_details == NULL) {
                    item->item_details = detail;
                } else {
                    struct item_details* last_detail = item->item_details;
                    while (last_detail->next != NULL) {
                        last_detail = last_detail->next;
                    }
                    last_detail->next = detail;
                }
            }
        }

        previosPTR = bufferPTR + 1;
        File_CC = previosPTR - stream;
    }

    free(str_buffer);
}


void throw_error(char * err_msg, int err_code){
  perror(err_msg);
  exit(err_code);
}

