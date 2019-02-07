#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	float mid, final, proj;
}Points;
enum Sex{
	Male, Female
};
typedef struct {
	int studentId; //학생 id
	char name[40]; //이름
	enum Sex sex; //성별(남=0, 여=1)
	float marks; // 성적 합계
	char grade[3]; //성적 등급
	Points subject; // {중간,기말,프젝}점수
}Grades;
Grades *student;

int main() {

	FILE * fp;
	int  size, i;
	char fname[30];
	char buf[60];
	printf("Input File Name : ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	fscanf(fp, "%d\n", &size);

	student = (Grades*)malloc(sizeof(Grades)*size);
	char s[10];

	for (int i = 0; i < size; i++){
		fgets(buf, 60, fp);
		sscanf(buf, "%d %*c %[^/] / %[^/] / %f /%f /%f", &student[i].studentId, student[i].name, s, &student[i].subject.mid, &student[i].subject.final, &student[i].subject.proj);
		if (strcmp(s,"Male ") == 0)
			student[i].sex = Male;
		else
			student[i].sex = Female;
		
		student[i].marks = student[i].subject.mid*0.3 + student[i].subject.final*0.3 + student[i].subject.proj * 0.4;
	}
	

	for (int i = 0; i < size; i++){
		if (student[i].marks < 50){
			student[i].grade[0] = 'F';
			student[i].grade[1] = '\0';
			continue;
		}
		else if (student[i].marks  >= 80) {
			student[i].grade[0] = 'A';
			student[i].grade[1] = '+';
			student[i].grade[2] = '\0';
		}
		else if (student[i].marks >= 70) {
			student[i].grade[0] = 'B';
			student[i].grade[1] = '+';
			student[i].grade[2] = '\0';
		}
		else{
			student[i].grade[0] = 'C';
			student[i].grade[1] = '+';
			student[i].grade[2] = '\0';
		}
	}
	printf("--Student List--\n");
	for (i = 0; i < size; i++) {
		printf("\tId : %d\n", student[i].studentId);
		if (student[i].sex == 1)
			printf("\tName : %s (1)\n", student[i].name);
		else
			printf("\tName : %s (0)\n", student[i].name);
		printf("\tGrade(mid) : %.2f\n", student[i].subject.mid);
		printf("\tGrade(final) : %.1f\n", student[i].subject.final);
		printf("\tGrade(project) : %.1f\n", student[i].subject.proj);
		printf("\tGrade : %c (%.2f)\n\n", student[i].grade[0], student[i].marks);
	}
	return 0;
}