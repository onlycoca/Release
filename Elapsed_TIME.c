#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int hours;
	int minutes;
	int seconds;
}Time; 

int main(void){
	Time currTime;
	Time *prevTimePtr;
	prevTimePtr = (Time*)malloc(sizeof(Time));

	char order[50];
	
	time_t timer;
	struct tm * t;
	timer = time(NULL);
	t = localtime(&timer);
	prevTimePtr->hours = t->tm_hour;
	prevTimePtr->minutes = t->tm_min;
	prevTimePtr->seconds = t->tm_sec;


	int num = 1;
	while (1) {
		printf("system> ");
		fgets(order, 50, stdin);
		timer = time(NULL);
		t = localtime(&timer);
		currTime.hours = t->tm_hour;
		currTime.minutes = t->tm_min;
		currTime.seconds = t->tm_sec;
		if (strcmp(order, "check\n") == 0) {
			
			printf("\n\tCheck Point #%02d\n", num);
			printf("\tCurrent Time = ");
			printf("%02d : %02d : %02d \n", currTime.hours, currTime.minutes, currTime.seconds);
			printf("\tPrevious Time = ");
			printf("%02d : %02d : %02d\n", prevTimePtr->hours, prevTimePtr->minutes, prevTimePtr->seconds);

			if ((*prevTimePtr).seconds > currTime.seconds) {
				currTime.minutes--;
				currTime.seconds += 60;
				currTime.seconds -= (*prevTimePtr).seconds;
			}
			else
				currTime.seconds -= (*prevTimePtr).seconds;
			if ((*prevTimePtr).minutes > currTime.minutes) {
				currTime.hours--;
				currTime.minutes += 60;
				currTime.minutes -= (*prevTimePtr).minutes;
			}
			else
				currTime.minutes -= (*prevTimePtr).minutes;
			currTime.hours -= (*prevTimePtr).hours;
			printf("\tElasped Time = ");
			printf("%02d : %02d : %02d\n\n", currTime.hours, currTime.minutes, currTime.seconds);
			num++;
			*prevTimePtr = currTime;
		}
		else if (strcmp(order, "quit\n") == 0) {
			break;
		}
	}
	return 0;
}
