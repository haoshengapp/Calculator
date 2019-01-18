#ifndef _EQUATION_H
#define _EQUATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/*韦达定理解方程 x^2 - px + q = 0*/
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

double equation3(double a, double b, double c, double d)
{
	double p, q, x, delta;

	/*转化x^3 + b'x^2 + c'x + d' = 0*/
	b /= a;
	c /= a;
	d /= a;

	/*转化x^3 + px + q = 0*/
	p = c - b * b / 3;
	q = d + b * (2 * b * b - 9 * c) / 27;

	/*判别式 (p/3)^3 + (q/2)^2*/
	p = -p * p * p / 27;
	q /= -2;
	delta = -p + q * q;

	if (delta < 0)//三个不等实根
	{
		double r = sqrt(p);
		double theta = acos(q / r) / 3;
		x = 2 * cbrt(r) * cos(theta) - b / 3;
	}
	else//卡尔丹公式
	{
		double part1 = cbrt(q + sqrt(delta));
		double part2 = cbrt(q - sqrt(delta));
		x = part1 + part2 - b / 3;
	}
	return x;
}

#endif
