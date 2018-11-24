#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double x[3];
double root[3];

int sum_product(double a, double b)//a = x1 + x2; b = x1 * x2
{
	//��Τ�ﶨ��ⷽ�� x^2 - ax + b = 0
	double delta = a * a - 4 * b;

	if (delta < 0)
	{
		x[1] = a / 2;
		x[2] = sqrt(-delta) / 2;
		printf("x2 = %lf + %lf i.\n", x[1], x[2]);
		printf("x3 = %lf - %lf i.\n", x[1], x[2]);
	}
	else
	{
		x[1] = (a + sqrt(delta)) / 2;
		x[2] = (a - sqrt(delta)) / 2;
		printf("x2 = %lf.\n", x[1]);
		printf("x3 = %lf.\n", x[2]);
	}
	return 0;
}

int cube_root(double m, int n)
{
	if (m > 0)
		root[n] = pow(m, 1.0 / 3);
	else if (m == 0)
		root[n] = 0;
	else
		root[n] = -pow(-m, 1.0 / 3);

	return 0;
}

int main(void)
{
	double coef[4];
	double p, q, r, delta, theta;
	printf("�ⷽ��:ax^3 + bx^2 + cx + d = 0\n");
	printf("������������ϵ��:\n");
	scanf_s("%lf", &coef[0]);
	printf("�����������ϵ��:\n");
	scanf_s("%lf", &coef[1]);
	printf("������һ����ϵ��:\n");
	scanf_s("%lf", &coef[2]);
	printf("�����볣����:\n");
	scanf_s("%lf", &coef[3]);


	if (coef[0] != 0)//�ж��Ƿ�ΪһԪ���η���
	{
		//���̻�Ϊ x^3 + ax^2 + bx + c = 0
		coef[1] /= coef[0];
		coef[2] /= coef[0];
		coef[3] /= coef[0];

		p = coef[2] - coef[1] * coef[1] / 3;//���̻�Ϊ x^3 +px + q = 0
		q = coef[3] + coef[1] * (2 * coef[1] * coef[1] - 9 * coef[2]) / 27;

		p /= 3;//��ʱ,p ���� p(ԭ)/3
		q /= 2;//��ʱ,q ���� q(ԭ)/2
		delta = q * q + p * p * p;//�б�ʽ (p/3)^3 + (q/2)^2, 

		if (delta < 0)
		{
			r = sqrt(-p * p * p);
			theta = acos(-q / r) / 3;
			cube_root(r, 0);
			x[0] = 2 * root[0] * cos(theta) - coef[1] / 3;
		}
		else
		{
			root[0] = sqrt(delta);
			cube_root(-q + root[0], 1);
			cube_root(-q - root[0], 2);
			x[0] = root[1] + root[2] - coef[1] / 3;//��������ʽ
		}
		printf("x1 = %lf.\n", x[0]);
		sum_product(-coef[1] - x[0], coef[2] + x[0] * (x[0] + coef[1]));
	}
	else
		printf("��һԪ���η���.\n");

	system("pause");
	return 0;
}