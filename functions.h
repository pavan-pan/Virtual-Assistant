/*
 * functions.h
 *
 *  Created on: Feb 25, 2019
 *      Author: pavan
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <json-c/json_object.h>
#include <json-c/json_tokener.h>


#ifdef __cplusplus
extern "H" {
#endif


#ifdef __cplusplus
}
#endif


#define SPACE ' '

//Function used by libcurl to allocate memory to data received from the HTTP response

typedef struct MemoryStruct {
    char *memory;
    size_t size;
}MemoryStruct_t;


typedef struct{
    char *ptr;
    size_t len;
}string_t;

void init_string(string_t *s);


int find_restaurants(void);

int show_weather(char* weather) ;

#endif /* FUNCTIONS_H_ */
