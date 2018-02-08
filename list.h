#ifndef __LIST_H_
#define __LIST_H_
#include <stdbool.h>
#define LEN sizeof(struct student)

struct student
{
	char name[20];
	long int num;
	//int age;
	int grade;
	//int grade2;
	//int grade3;
	struct student *next;
};

struct student *head;

void Mainmenu();

void WriteData();

void Insert(struct student *stu);

void Display(struct student *stu);

void DisplayAll();

void NumToQuery();

void Delete(); 

void Devise(struct student *p);

void Modify();

void ReadFile();

void WriteFile();

void FreeAll();

#endif