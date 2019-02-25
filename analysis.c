/*
 * requests.c
 *
 *  Created on: Feb 25, 2019
 *      Author: pavan
 */

#include "analysis.h"
#include "response.h"
#include <stdio.h>
//for weather---------------

char *weather_class[10][10] = {
    {"please", "show", "outside", "condition"},
    {"how", " ", "weather", "today"},
    {"weather", " ", "desired", "place"}
};

//for greeting--------------

char *greeting_class[10][10] = {
    {"hey", "how", "are", "you"},
    {"how", " ", " ", "doing"},
    {"hello", "there", " ", " "}
};

//for google----------------

char *google_class[10][10] = {
    {"open", "google", "for", "me"},
    {"I", "want", "search", "browse"},
    {"can", "you", "open", "google"}
};

//for media-----------------

char *media_class[10][10] = {
    {"can", "you", "list", "media"},
    {"video", "listen", "play", "music"},
    {"play", "something", "nice", "song "}
};

//for Restaurant

char *restaurant_class[10][10] = {
    {"Please", "find", "some", "restaurants"},
    {"Find", " ", "some", "restaurants"},
    {"Show", " ", " ", "restaurants"},
    {"Find", "places", "to", "eat"}
};

int weather_score, greeting_score, media_score, google_score,
		calendar_score, youtube_score, help_score, restaurant_score;

void analyse_user_input (char *example){



	int compare[10];
	char split[10][10] = {0};
	int k = 0, n, j = 0, w = 0, g = 0, go = 0, me = 0, res = 0, c = 0, u = 0, h = 0, temp = 0;
	char result[20];

	//request analysis

	for (int i = 0; i < strlen(example); i++) {
	    if (example[i] == ' ') {
	        if (example[i + 1] != ' ') {
	            split[k][j] = '\0';
	            j = 0;
	            k++;
	        }
	        continue;
	    } else {
	        split[k][j++] = example[i];
	    }
	}

	split[k][j] = '\0';


	//For Weather---------------------------------------

	for (int v = 0; v <= k; v++)
	    for (int b = 0; b < 3; b++) {

	        for (int c = 0; c < 4; c++) {
	            if (strcmp(weather_class[b][c], split[v]) == 0) {
	                w++;

	            }
	        }
	    }
	weather_score = w;

	//For Greeting-----------------------------------

	for (int v = 0; v <= k; v++)
	    for (int b = 0; b < 3; b++) {
	        for (int c = 0; c < 4; c++) {
	            if (strcmp(greeting_class[b][c], split[v]) == 0) {
	                g++;
	            }
	        }
	    }
	greeting_score = g;


	//For Google-------------------------------------

	for (int v = 0; v <= k; v++)
	    for (int b = 0; b < 3; b++) {
	        for (int c = 0; c < 4; c++) {
	            if (strcmp(google_class[b][c], split[v]) == 0) {
	                go++;
	            }
	        }
	    }
	google_score = go;


	//For Media---------------------------------------

	for (int v = 0; v <= k; v++)
	    for (int b = 0; b < 3; b++) {
	        for (int c = 0; c < 4; c++) {
	            if (strcmp(media_class[b][c], split[v]) == 0) {
	                me++;
	            }
	        }
	    }
	media_score = me;

	//For Restaurant-----------------------------------
	for (int v = 0; v <= k; v++)
	    for (int b = 0; b < 3; b++) {
	        for (int c = 0; c < 4; c++) {
	            if (strcmp(restaurant_class[b][c], split[v]) == 0) {
	                res++;
	            }
	        }
	    }
	restaurant_score = res;



	if (weather_score > greeting_score) {
	    if (weather_score > media_score) {
	        if (weather_score > restaurant_score) {
	            if (weather_score > google_score)
	                strcpy(result, "weather");
	            else
	                strcpy(result, "google");
	        } else {
	            if (restaurant_score > google_score)
	                strcpy(result, "restaurant");
	            else
	                strcpy(result, "google");
	        }
	    } else {
	        if (media_score > restaurant_score) {
	            if (media_score > google_score)
	                strcpy(result, "media");
	            else
	                strcpy(result, "google");
	        } else {
	            if (restaurant_score > google_score)
	                strcpy(result, "restaurant");
	            else
	                strcpy(result, "google");
	        }
	    }
	} else {
	    if (greeting_score > media_score) {
	        if (greeting_score > restaurant_score) {
	            if (greeting_score > google_score)
	                strcpy(result, "greeting");
	            else
	                strcpy(result, "google");
	        } else {
	            if (restaurant_score > google_score)
	                strcpy(result, "restaurant");
	            else
	                strcpy(result, "google");
	        }
	    } else {
	        if (media_score > restaurant_score) {

	            if (media_score > google_score)
	                strcpy(result, "media");
	            else
	                strcpy(result, "google");
	        } else {
	            if (restaurant_score > google_score)
	                strcpy(result, "restaurant");
	            else
	                strcpy(result, "google");
	        }
	    }
	}

	get_response (result, example);
	printf ("result is %s \n:", result);
}

