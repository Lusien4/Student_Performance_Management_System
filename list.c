#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void Mainmenu()
{
	printf ("\n");
	printf ("\t\t ____________________________________________________________\n");
	printf ("\t\t|------------------------------------------------------------|\n");
	printf ("\t\t|		Student Performance Management system        |\n");  
	printf ("\t\t|------------------------------------------------------------|\n");
	printf ("\t\t|		[1]----Enter student information             |\n");
	printf ("\t\t|		[2]----Browse student information            |\n");
	printf ("\t\t|		[3]----Query student information             |\n");
	printf ("\t\t|		[4]----Delete student information            |\n");
	printf ("\t\t|		[5]----Modify student information            |\n");
	printf ("\t\t|		[0]----Exit Management system                |\n");
	printf ("\t\t|------------------------------------------------------------|\n");
	printf ("\t\t|____________________________________________________________|\n");
	printf ("\n\n");
}

void WriteData()
{
	struct student *p0;

	p0 = (struct student *)malloc(LEN);
	printf("Please add the student's name: ");
	scanf("%s", p0->name);
	printf("Please add the student's number: ");
	scanf("%ld", &p0->num);
	printf("Please enter the Math grade: ");
	scanf("%d", &p0->grade);

	Insert (p0);
	printf("\nHere is the list:\n");
	puts("----------------------------------------------");
	puts("Name\t\tNum\t\tMath\t");
	puts("----------------------------------------------");
	Display(p0);
}

void Insert(struct student *stu)
{
	struct student *p0, *p1, *p2;

	p1 = head;
	p0 = stu;

	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num > p1->num)&&(p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num <= p1->num)
		{
			if (head == p1)
				head = p0;
			else
				p2->next = p0;
				p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}  
	} 
}

void Display(struct student *p)
{
	printf("%s\t\t%ld\t\t%d\n", p->name, p->num, p->grade);
}

void DisplayAll()
{
	struct student *p;
	p = head;

	if(head != NULL)
	{
		printf("\nHere is the list:\n");
		puts("----------------------------------------------");
		puts("Name\t\tNum\t\tMath\t");
		puts("----------------------------------------------");
		do
		{
			Display(p);
			p = p -> next;
		}
		while(p != NULL);
	}
	printf("\n");

	// FILE *fp;
	// char ch;

	// if((fp = fopen("DataList.dat", "r")) == NULL)
	// {
	// 	fputs("Can't open the \"DataList.dat\" file.\n", stderr);
	// 	exit(1);
	// }
	// else
	// {
	// 	printf("\nHere is the list:\n");
	// 	puts("----------------------------------------------");
	// 	puts("Name\t\tNum\t\tMath\t");
	// 	puts("----------------------------------------------");
	// 	while(( ch = fgetc(fp)) != EOF)
	// 	{
	// 		printf("%c", ch);  
	// 	}

	// fclose(fp);
	// }
}

void NumToQuery()
{
	long int num;
	struct student *p1;

	printf ("Please enter the student's number: ");
	scanf("%ld", &num);

	if(head == NULL)
	{
		puts("No student records!");
		return;
	}
	p1 = head;
	while(num != p1->num  && p1->next != NULL)
		p1 = p1->next;
	if(num == p1->num)
	{
		puts("----------------------------------------------");
		puts("Name\t\tNum\t\tMath\t");
		puts("----------------------------------------------");
		Display(p1);
	}
	else
		puts("No student records. Please check!");
}

void Delete()
{
	struct student *p1, *p2;
	long int num;

	if(head == NULL)
	{
		puts("No student records!");
		return;
	}
	puts("Please enter the student number you want to delete: ");
	scanf("%ld", &num);
	p1 = head;

	while(num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(num == p1->num)
	{
		if(p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		free(p1);
	}
	else
		puts("No student records. Please check!");
}

void Devise(struct student *p)
{
	int choice;
	
	do
	{
		printf ("\n");
		printf ("\t\t ____________________________________________________________\n");
		printf ("\t\t|------------------------------------------------------------|\n");
		printf ("\t\t|		Which content do you want to modify ?        |\n");  
		printf ("\t\t|------------------------------------------------------------|\n");
		printf ("\t\t|		[1]----The student's names                   |\n");
		printf ("\t\t|		[2]----The student's number                  |\n");
		printf ("\t\t|		[3]----The math scores                       |\n");
		printf ("\t\t|		[0]----Cancel                                |\n");
		printf ("\t\t|------------------------------------------------------------|\n");
		printf ("\t\t|____________________________________________________________|\n");
		printf ("\n\n");
		printf("Please enter the Serial number: \n");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 0:
				return;

			case 1:
				printf("Please enter the new name: ");
				scanf("%s", p->name);
				break;

			case 2:
				printf("Please enter the new number: ");
				scanf("%ld", &p->num);
				break;

			case 3:
				printf("Please enter the new grade: ");
				scanf("%d", &p->grade);
				break;

			default:
				printf("Sorry, the option entered is invalid.\n");
				break;
		}
	}
	while(choice != 0);
}

void Modify()
{
	struct student *p1, *p2;
	long int num;

	if(head == NULL)
	{
		puts("No student records!");
		return;
	}
	puts("Please enter the student number you want to modify: ");
	scanf("%ld", &num);
	p1 = head;

	while(num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if(num == p1->num)
		Devise(p1);
	else
		puts("No student records. Please check!");
}

void ReadFile()
{
	FILE *fp;
	struct student *p1, *p2;

	if((fp = fopen("DataList.dat", "r")) == NULL)
	{
		fputs("Can't open the \"DataList.dat\" file.\n", stderr);
		exit(1);
	}

	head = p1 = p2 = (struct student *)malloc(LEN);
	fscanf(fp,"%s\t\t%ld\t\t%d\n", p1->name, &p1->num, &p1->grade);
	while(!feof(fp))
	{
		p1 = (struct student *)malloc(LEN);
		fscanf(fp,"%s\t\t%ld\t\t%d\n", p1->name, &p1->num, &p1->grade);
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;

	fclose(fp);
}

void WriteFile()
{
	FILE *fp;
	struct student *p;

	if((fp = fopen("DataList.dat", "a+")) == NULL)
	{
		fputs("Can't open the \"DataList.dat\" file.\n", stderr);
		exit(1);
	}

	for(p = head; p != NULL ; p = p->next)
	{
		fprintf(fp, "%s\t\t%ld\t\t%d\n", p->name, p->num, p->grade);
	}

	fclose(fp);
}

void FreeAll()
{
	struct student *p1, *p2;
	p1 = p2 = head;

	while(p1)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
}
