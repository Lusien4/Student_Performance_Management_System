#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(void)
{
	int choice;
	ReadFile();

	do
	{
		Mainmenu();
		printf("Please enter the Serial number: ");
		scanf("%d", &choice);
		getchar();	//若不加此行,结束输入的换行符留在缓冲区中，因此堵塞，造成无限循环。

		switch(choice)
		{
			case 0:	
				// WriteFile();
				FreeAll();
				puts("Thank you for using.");
				break;

			case 1:
				WriteData();
				WriteFile();
				break;

			case 2:
				DisplayAll();
				break;

			case 3:
				NumToQuery();
				break;

			case 4:
				Delete();
				break;

			case 5:
				Modify();
				break;

			default:
				printf("Sorry, the option entered is invalid.\n");
				break;
		}

	}while(choice != 0);

	return 0;
}