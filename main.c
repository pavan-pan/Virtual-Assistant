/*
 ============================================================================
 Name        : code_restructuring_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <json-c/json_object.h>
#include <json-c/json_tokener.h>

#include "interface.h"
#include "parameter.h"

int main(void) {

	//Getting home directory out of configuration file

	char str[1000];

	if (get_parameters())
		return 1;

	do{
		send_to_ui ("Hey, How can I help you?");
		get_from_ui (str);

		printf ("user input is :%s\n", str);

		analyse_user_input(str);

	}while ((strcmp(str, "stop") != 0));

	return EXIT_SUCCESS;
}
