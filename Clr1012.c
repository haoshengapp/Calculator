# include <stdio.h>
# include <math.h>

int U1(void);
int U2(void);
int U3(void);
int U4(void);
int U5(void);

int main(void)
{
	int u;
	char ch;

	do
	{
		printf("***********************************\n");
		printf("请输入编号(0---菜单)：");
		scanf_s("%d", &u);
		while ((ch = getchar()) != '\n')
			continue;
		printf("***********************************\n");

		if (u == 0)
		{
			printf("1---解方程:ax^2 + bx + c = 0\n");
			printf("2---解不等式:ax^2 + bx + c ＞ 0\n");
			printf("3---解不等式:ax^2 + bx + c ≥ 0\n");
			printf("4---心形点阵\n");
			printf("5---基本不等式(正实数)\n");
			scanf_s("%d", &u);
			while ((ch = getchar()) != '\n')
				continue;
			printf("***********************************\n");
		}
		else;

		if (u == 1)
		{
			U1();
		}

		else if (u == 2)
		{
			U2();
		}

		else if (u == 3)
		{
			U3();
		}

		else if (u == 4)
		{
			U4();
		}
		else if (u == 5)
		{
			U5();
		}
		else;

		u++;
		printf("***********************************\n");
		printf("输入0重新开始:");
		scanf_s("%d", &u);
	} while (u == 0);
	return 0;
}

int U1(void)
{
	float a;
	float b;
	float c;
	double x1;
	double x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%f", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%f", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%f", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");

	if (a == 0)
	{
		if (b != 0)
		{
			x1 = -c / b;
			printf("x = %lf.\n", x1);
		}
		else if (c != 0)
		{
			printf("无解.\n");
		}
		else
		{
			printf("任意复数.\n");
		}
	}

	else
	{
		float delta = b * b - 4 * a * c;

		if (delta > 0)
		{
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("x1 = %lf, x2 = %lf,\n", x1, x2);
		}

		else if (delta == 0)
		{
			x1 = -b / (2 * a);
			printf("x1 = x2 = %lf,\n", x1);
		}
		else
		{
			x1 = -b / (2 * a);
			x2 = sqrt(-delta) / (2 * a);
			printf("x = %lf ± %lf * i,\n", x1, x2);
		}

		float y = (4 * a * c - b * b) / (4 * a);

		if (a > 0)
		{
			printf("Min(y) = %f.\n", y);
		}

		else
		{
			printf("Max(y) = %f.\n", y);
		}
	}
	return 0;
}

int U2(void)
{
	float a;
	float b;
	float c;
	double x1;
	double x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%f", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%f", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%f", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("解集为 ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("(%lf, +∞).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-∞, %lf).\n", x1);
		}
		else if (c > 0)
		{
			printf("(-∞, +∞).\n");
		}
		else
		{
			printf("空集.\n");
		}
	}

	else
	{
		float delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta == 0)
			{
				x1 = -b / (2 * a);
				printf("(-∞, %lf)∪(%lf, +∞).\n", x1, x1);
			}

			else if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("(-∞, %lf)∪(%lf, +∞).\n", x2, x1);
			}

			else
			{
				printf("(-∞, +∞).\n");
			}
		}

		else
		{
			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("(%lf, %lf).\n", x2, x1);
			}

			else
			{
				printf("空集.");

			}
		}
	}
	return 0;
}

int U3(void)
{
	float a;
	float b;
	float c;
	double x1;
	double x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%f", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%f", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%f", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("解集为 ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("[%lf, +∞).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-∞, %lf]).\n", x1);
		}
		else if (c >= 0)
		{
			printf("(-∞, +∞).\n");
		}
		else
		{
			printf("空集.\n");
		}
	}

	else
	{
		float delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta <= 0)
			{
				printf("(-∞, +∞).\n");
			}
			else
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("(-∞, %lf]∪[%lf, +∞).\n", x2, x1);
			}
		}
		else
		{
			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("[%lf, %lf].\n", x2, x1);
			}
			else if (delta == 0)
			{
				x1 = -b / (2 * a);
				printf("{ %lf }.\n", x1);
			}
			else
			{
				printf("空集.\n");
			}
		}
	}
	return 0;
}

int U4(void)
{
	double x;
	double y;

	for (y = 1.3; y > -1; y -= 0.1)
	{
		for (x = 1.2; x > -1.2; x -= 0.05)
		{
			double P = x * x + y * y - 1;
			double Q = x * x * y * y * y;

			if (pow(P, 3) - Q < 0)
			{
				printf(".");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

int U5(void)
{
	int a;
	double m;
	double n;
	double p;
	double s;
	char ch;

	printf("1.已知(mx + ny),求xy的取值范围.\n");
	printf("2.已知xy,求(mx + ny)的取值范围.\n");
	scanf_s("%d", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");

	if (a == 1)
	{
		printf("m = ");
		scanf_s("%lf", &m);
		while ((ch = getchar()) != '\n')
			continue;
		printf("n = ");
		scanf_s("%lf", &n);
		while ((ch = getchar()) != '\n')
			continue;
		printf("mx + ny = ");
		scanf_s("%lf", &s);
		while ((ch = getchar()) != '\n')
			continue;
		printf("***********************************\n");

		p = (s*s) / (4 * m*n);
		printf("P <= %lf.\n", p);
	}

	else if (a == 2)
	{
		printf("m = ");
		scanf_s("%lf", &m);
		while ((ch = getchar()) != '\n')
			continue;
		printf("n = ");
		scanf_s("%lf", &n);
		while ((ch = getchar()) != '\n')
			continue;
		printf("xy = ");
		scanf_s("%lf", &p);
		while ((ch = getchar()) != '\n')
			continue;
		printf("***********************************\n");

		s = 2 * sqrt(m*n*p);
		printf("S >= %lf.\n", s);
	}
	else;

	return 0;
}