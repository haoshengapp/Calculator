#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
void checkch(void);
int quit(void);
void asterisks(void);

int f5i(void)
{
	double m, n, p, s;

	printf("������\nm: ");
	scanf_s("%lf", &m);
	checkch();
	printf("n: ");
	scanf_s("%lf", &n);
	checkch();
	printf("(mx + ny): ");
	scanf_s("%lf", &s);
	checkch();
	asterisks();

	p = (s*s) / (4 * m*n);
	printf("P <= %lf.\n", p);

	return 0;
}

int f5ii(void)
{
	double m, n, p, s;

	printf("������\nm: ");
	scanf_s("%lf", &m);
	checkch();
	printf("n: ");
	scanf_s("%lf", &n);
	checkch();
	printf("xy: ");
	scanf_s("%lf", &p);
	checkch(); 
	asterisks();
	s = 2 * sqrt(m*n*p);
	printf("S >= %lf.\n", s);

	return 0;
}

int inequality(void)
{
	int index = 0;

	do
	{
		printf("1.��֪(mx + ny),��xy��ȡֵ��Χ;\n2.��֪xy,��(mx + ny)��ȡֵ��Χ.\n");
		scanf_s("%d", &index);
		switch (index)
		{
		case 1:f5i(); break;
		case 2:f5ii(); break;
		}
	} while (quit());
	return 0;
}