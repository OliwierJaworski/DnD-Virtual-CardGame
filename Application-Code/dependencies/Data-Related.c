#include "Data-Related.h"

int fetch_url_data(char * url, FILE * filepointer_CC){
    CURL *curl = curl_easy_init();
    struct memory chunk = {0};  
    CURLcode res;
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
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

void throw_error(char * err_msg, int err_code){
        perror(err_msg);
        exit(err_code);
}

