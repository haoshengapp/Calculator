#include <stdio.h>
#include <math.h>
int quit(void);
void checkch(void);

/*求在区间[2,x]的质数*/
int prt1(int y, int cnt)
{
	if (y == 1)
	{
		printf("2 ");//输出第一个质数
	}
	else if (cnt == 0)
	{
		printf("%d ", y);//输出非2质数
	}
	else;

	return 0;
}

int single(int y, int cnt)
{
	int n;//因数
	int z = (int)(sqrt(y)) + 1;//因数上限

	for (n = 3; n < z; n += 2)//区间[3,sqrt(y)]上的奇数
	{
		if (y % n == 0)//y不是质数
		{
			cnt++;//计数
		}
		else;
	}
	prt1(y, cnt);

	return 0;
}

int calc(void)
{
	int x, y;
	printf("请输入上限: ");
	scanf_s("%d", &x);

	for (y = 1; y < x + 1; y += 2)//在区间[1,x)上的奇数y
	{
		single(y, 0);//单个质数
	}

	return 0;
}

/*判断x是否为质数*/
int prt2(int cnt, int x)
{
	if (cnt == 0 && x > 1)//质数定义
	{
		printf("是质数\n");
	}
	else
	{
		printf("不是质数\n");
	}

	return 0;
}

int judge(void)
{
	int x;
	printf("请输入x: ");
	scanf_s("%d", &x);
	int cnt = 0;
	int n;//因数
	int z = (int)(sqrt(x)) + 1;//因数上限

	for (n = 2; n < z; n++)//在区间[2,sqrt(x)]的整数n
	{
		if (x % n == 0)//x不是质数
		{
			cnt++;
		}
		else;
	}

	prt2(cnt, x);

	return 0;
}

int prime(void)
{
	int index;

	do
	{
		printf("1.求在区间[2,x]的质数;\n2.判断x是否为质数.\n");
		scanf_s("%d", &index);
		checkch();
		switch (index)
		{
		case 1:	calc(); break;
		case 2:	judge(); break;
		}
	} while (quit());
	return 0;
}