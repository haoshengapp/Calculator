#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double alpha[3][3] = { 0 };

int vieta(double p, double q)//p = x1 + x2; q = x1 * x2
{
	//韦达定理解方程 x^2 - px + q = 0
	double delta = p * p - 4 * q;

	if (delta < 0)
	{
		alpha[2][1] = p / 2;
		alpha[2][2] = sqrt(-delta) / 2;
		printf("x2 = %lf + %lf i.\n", alpha[2][1], alpha[2][2]);
		printf("x3 = %lf - %lf i.\n", alpha[2][1], alpha[2][2]);
	}
	else
	{
		alpha[2][1] = (p + sqrt(delta)) / 2;
		alpha[2][2] = (p - sqrt(delta)) / 2;
		printf("x2 = %lf.\n", alpha[2][1]);
		printf("x3 = %lf.\n", alpha[2][2]);
	}
	return 0;
}

int main(void)
{
	double p, q, r, delta, theta;
	printf("解方程:ax^3 + bx^2 + cx + d = 0\n");
	printf("请输入三次项系数:\n");
	scanf("%lf", &alpha[0][0]);
	printf("请输入二次项系数:\n");
	scanf("%lf", &alpha[0][1]);
	printf("请输入一次项系数:\n");
	scanf("%lf", &alpha[0][2]);
	printf("请输入常数项:\n");
	scanf("%lf", &alpha[1][0]);

	if (alpha[0][0] != 0)//判断一元三次方程
	{
		/*转化x^3 + b'x^2 + c'x + d' = 0*/
		alpha[0][1] /= alpha[0][0];
		alpha[0][2] /= alpha[0][0];
		alpha[1][0] /= alpha[0][0];

		/*转化x^3 + px + q = 0*/
		p = alpha[0][2] - alpha[0][1] * alpha[0][1] / 3;
		q = alpha[1][0] + alpha[0][1] * (2 * alpha[0][1] * alpha[0][1] - 9 * alpha[0][2]) / 27;

		/*判别式 (p/3)^3 + (q/2)^2*/
		p /= 3;
		q /= 2;
		delta = p * p * p + q * q;

		if (delta < 0)//三个不等实根
		{
			r = sqrt(-p * p * p);
			theta = acos(-q / r) / 3;
			alpha[2][0] = 2 * cbrt(r) * cos(theta) - alpha[0][1] / 3;
		}
		else
		{
			alpha[1][1] = cbrt(-q + sqrt(delta));
			alpha[1][2] = cbrt(-q - sqrt(delta));
			alpha[2][0] = alpha[1][1] + alpha[1][2] - alpha[0][1] / 3;//卡尔丹公式
		}
		printf("x1 = %lf.\n", alpha[2][0]);
		//(x-x1)*(x-x2)*(x-x3) = x^3 - (x1+x2+x3)x^2 + (x1*x2 + x1*x3 + x2*x3)x - x1*x2*x3
		vieta(-alpha[0][1] - alpha[2][0], alpha[0][2] + alpha[2][0] * (alpha[2][0] + alpha[0][1]));
	}
	else
		printf("非一元三次方程.\n");

	system("pause");
	return 0;
}
