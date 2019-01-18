#ifndef _EQUATION_H
#define _EQUATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "toolbox.h"

/*Τ�ﶨ��ⷽ�� x^2 - px + q = 0*/
int vieta(double p, double q, int no1, int no2)//p = x1 + x2; q = x1 * x2
{
	double delta = p * p - 4 * q;
	if (delta < 0)
	{
		double re = p / 2;
		double im = sqrt(-delta) / 2;
		printf("x%d = %lf + %lf i.\n", no1, re, im);
		printf("x%d = %lf - %lf i.\n", no2, re, im);
	}
	else
	{
		double x1 = (p + sqrt(delta)) / 2;
		double x2 = (p - sqrt(delta)) / 2;
		printf("x%d = %lf.\n", no1, x1);
		printf("x%d = %lf.\n", no2, x2);
	}
	return 0;
}

/*���һԪ���η��̵�һ��ʵ����*/
double equation3(double a, double b, double c, double d)
{
	double p, q, x, delta;

	/*ת��x^3 + b'x^2 + c'x + d' = 0*/
	b /= a;
	c /= a;
	d /= a;

	/*ת��x^3 + px + q = 0*/
	p = c - b * b / 3;
	q = d + b * (2 * b * b - 9 * c) / 27;

	/*�б�ʽ (p/3)^3 + (q/2)^2*/
	p = -p * p * p / 27;
	q /= -2;
	delta = -p + q * q;

	if (delta < 0)//��������ʵ��
	{
		double r = sqrt(p);
		double theta = acos(q / r) / 3;
		x = 2 * cbrt(r) * cos(theta) - b / 3;
	}
	else//��������ʽ
	{
		double part1 = cbrt(q + sqrt(delta));
		double part2 = cbrt(q - sqrt(delta));
		x = part1 + part2 - b / 3;
	}
	return x;
}

/*һԪһ�η���*/
double equation1(double a, double b)
{
	if (a != 0)
	{
		printf("x = %lf.\n", -b / a);
	}
	else if(b == 0)
	{
		printf("���и���.\n");
	}
	else
	{
		printf("�޽�.\n");
	}
	return 0;
}

/*һԪ���η���*/
int equation2(void)//һԪ���η���
{
	double a, b, c;
	do
	{
		printf("ax^2 + bx + c = 0\n");
		printf("������a:\n");
		scanf("%lf", &a);
		checkch();
		printf("������b:\n");
		scanf("%lf", &b);
		checkch();
		printf("������c:\n");
		scanf("%lf", &c);
		checkch();
		asterisks();

		if (a != 0)
		{
			vieta(-b / a, c / a, 1, 2);

			double x = -b / (2 * a);
			double y = c - b * b / (4 * a);
			if (a > 0)
			{
				printf("Min:(%lf, %lf).\n", x, y);
			}
			else
			{
				printf("Max:(%lf, %lf).\n", x, y);
			}
		}
		else
		{
			equation1(b, c);
		}
		asterisks();
	} while (quit());

	return 0;
}

/*һԪ���β���ʽ(������)*/
int open2(int k)//һԪ���β���ʽ(������)
{
	double a, b, c, x1, x2;

	printf("�����������ϵ��:\n");
	scanf("%lf", &a);
	checkch();
	printf("������һ����ϵ��:\n");
	scanf("%lf", &b);
	checkch();
	printf("�����볣����:\n");
	scanf("%lf", &c);
	checkch();
	asterisks();
	printf("�⼯Ϊ ");
	if (k)
	{
		a *= -1;
		b *= -1;
		c *= -1;
	}

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("(%lf, +��).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-��, %lf).\n", x1);
		}
		else if (c > 0)
		{
			printf("(-��, +��).\n");
		}
		else
		{
			printf("�ռ�.\n");
		}
	}

	else
	{
		double delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta == 0)
			{
				x1 = -b / (2 * a);
				printf("(-��, %lf)��(%lf, +��).\n", x1, x1);
			}

			else if (delta > 0)
			{
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
				printf("(-��, %lf)��(%lf, +��).\n", x1, x2);
			}

			else
			{
				printf("(-��, +��).\n");
			}
		}

		else
		{
			if (delta > 0)
			{
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
				printf("(%lf, %lf).\n", x1, x2);
			}

			else
			{
				printf("�ռ�.");

			}
		}
	}
	return 0;
}

/*һԪ���β���ʽ(������)*/
int closed2(int k)//һԪ���β���ʽ(������)
{
	double a, b, c, x1, x2;

	printf("�����������ϵ��:\n");
	scanf("%lf", &a);
	checkch();
	printf("������һ����ϵ��:\n");
	scanf("%lf", &b);
	checkch();
	printf("�����볣����:\n");
	scanf("%lf", &c);
	checkch();
	asterisks();
	printf("�⼯Ϊ ");

	if (k)
	{
		a *= -1;
		b *= -1;
		c *= -1;
	}

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("[%lf, +��).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-��, %lf]).\n", x1);
		}
		else if (c >= 0)
		{
			printf("(-��, +��).\n");
		}
		else
		{
			printf("�ռ�.\n");
		}
	}

	else
	{
		double delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("(-��, %lf]��[%lf, +��).\n", x2, x1);
			}
			else
			{
				printf("(-��, +��).\n");
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
				printf("�ռ�.\n");
			}
		}
	}
	return 0;
}

#endif
