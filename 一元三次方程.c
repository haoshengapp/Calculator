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
		printf("请输入a:\n");
		scanf_s("%lf", &a);
		checkch();

		if (a != 0)//判断一元三次方程
		{
			printf("请输入b:\n");
			scanf_s("%lf", &b);
			checkch();
			printf("请输入c:\n");
			scanf_s("%lf", &c);
			checkch();
			printf("请输入d:\n");
			scanf_s("%lf", &d);
			checkch();

			x = equation3(a, b, c, d);
			printf("x1 = %lf.\n", x);

			//(x-x1)*(x-x2)*(x-x3) = x^3 - (x1+x2+x3)x^2 + (x1*x2 + x1*x3 + x2*x3)x - x1*x2*x3
			vieta(-b / a - x, c / a + x * (x + b / a), 2, 3);
		}
		else
			printf("非一元三次方程.\n");
	} while (quit());

	return 0;
}
