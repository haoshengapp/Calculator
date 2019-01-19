#include <stdio.h>
void checkch(void);
int quit(void);
int vieta(double p, double q, int no1, int no2);
double equation3(double a, double b, double c, double d);

double coffee_equation3(void)
{
	do
	{
		double a, b, c, d, x;
		printf("ax^3 + bx^2 + cx + d = 0\n");
		printf("������a:\n");
		scanf_s("%lf", &a);
		checkch();

		if (a != 0)//�ж�һԪ���η���
		{
			printf("������b:\n");
			scanf_s("%lf", &b);
			checkch();
			printf("������c:\n");
			scanf_s("%lf", &c);
			checkch();
			printf("������d:\n");
			scanf_s("%lf", &d);
			checkch();

			x = equation3(a, b, c, d);
			printf("x1 = %lf.\n", x);

			//(x-x1)*(x-x2)*(x-x3) = x^3 - (x1+x2+x3)x^2 + (x1*x2 + x1*x3 + x2*x3)x - x1*x2*x3
			vieta(-b / a - x, c / a + x * (x + b / a), 2, 3);
		}
		else
			printf("��һԪ���η���.\n");
	} while (quit());

	return 0;
}
