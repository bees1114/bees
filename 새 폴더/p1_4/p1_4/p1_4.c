#include <stdlib.h>
#include <stdio.h>
typedef struct student1 {
	char *name;
	int studentID;
	char *major;
}student;

int main(int argc, char *argv[]) {
	FILE *file = fopen(argv[1], "r");
	FILE *file1 = fopen(argv[2], "w");
	int input;
	int i;
	student *p;
	fscanf(file,"%d", &input);
	p = (student*)malloc(sizeof(student)*input);
	for(i = 0 ;i < input ; i++) {
		p[i].name = (char *)malloc(sizeof(char)*30);
		fscanf(file, "%s", p[i].name);
		fscanf(file, "%d", &p[i].studentID);
		p[i].major = (char *)malloc(sizeof(char)*30);
		fscanf(file, "%s", p[i].major);
	}
	for(i = 0 ;i < input ; i++) {
		fprintf(file1, "%s ", p[i].name);
		fprintf(file1, "%d ", p[i].studentID);
		fprintf(file1, "%s\n", p[i].major);
	}
}