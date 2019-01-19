#include <stdio.h>
#include <stdlib.h>
void checkch(void);
int quit(void);
int equation2(void);
int open2(int k);
int closed2(int k);

int coffee_equation2(void)
{
	int choice;

	printf("1.一元二次方程;\n2.一元二次不等式.\n");
	scanf_s("%d", &choice);
	checkch();

	if (choice == 1)
	{
		equation2();
	}
	else if (choice == 2)
	{
		do
		{
			system("cls");
			printf("1.ax^2+bx+c>0;\n2.ax^2+bx+c<0;\n");
			printf("3.ax^2+bx+c>=0;\n4.ax^2+bx+c<=0;\n");
			scanf_s("%d", &choice);
			checkch();

			switch (choice)
			{
			case(1):open2(0); break;
			case(2):open2(1); break;
			case(3):closed2(0); break;
			case(4):closed2(1); break;
			default:break;
			};
		} while (quit());
	}
	else;

	return 0;
}