#include <stdio.h>
enum Date getDate(int year, int month, int day);
char* getDayOfWeek(enum Date currDate);
enum Date{sun = 0, mon , tue, wed, thu, fri, sat};
struct Calendar {
	int year, month, day;
	enum Date date;
	char* dateString;
};
void main(){
	struct Calendar cal;
	printf("Input Year : ");
	scanf("%d", &cal.year);
	printf("Input Month : ");
	scanf("%d", &cal.month);
	printf("Input Day : ");
	scanf("%d", &cal.day);
	cal.date =getDate(cal.year, cal.month, cal.day);
	cal.dateString = getDayOfWeek(cal.date);
	printf("%d-%02d-%02d is %s\n", cal.year, cal.month, cal.day, cal.dateString);
}

enum Date getDate(int year, int month, int day) {
	int date;
	if (month < 3) {
		date =((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + (13 * (month + 12) + 8) / 5 + day) % 7;
	}
	else {
		date =(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
	}
	return date;
}

char* getDayOfWeek(enum Date currDate) {
	if (currDate == sun) {
		return "Sunday";
	}
	if (currDate == tue) {
		return "Tuesday";
	}
	if (currDate == wed) {
		return "Wednesday";
	}
	if (currDate == thu) {
		return "Thursday";
	}
	if (currDate == fri) {
		return "Friday";
	}
	if (currDate == sat) {
		return "Saturday";
	}
	if (currDate == sun) {
		return "Sunday";
	}
}