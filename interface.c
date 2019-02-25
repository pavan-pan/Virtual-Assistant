/*
 * interface.c
 *
 *  Created on: Feb 25, 2019
 *      Author: pavan
 */

#include "interface.h"

void send_to_ui (char *str){
	printf("%s\n", str);
}

void get_from_ui (char * str){
	fgets(str, 1000, stdin);
	if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
			    str[strlen(str) - 1] = '\0';

	//change uppercase letters in str to lowercase for convenience
	int i, s = strlen(str);
	for (i = 0; i < s; i++)
		str[i] = tolower(str[i]);
}


