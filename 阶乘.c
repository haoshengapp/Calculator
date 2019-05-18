#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int size;//位数
int calc(int n, int* a);//计算

int main()
{
	int* a;
	int n, i;
	puts("[请输入n]");
	scanf_s("%d", &n);
	if (n > 1 && n < 1000000)
	{
		size = (int)((n + 0.5) * log10(n) - 0.434294481903251827651 * n + 1.3990899341790575247825);//斯特林公式
		a = (int*)calloc(size, 4);
		*a = 1;

		printf("[%d的阶乘](%d位)\n加载中...\n", n, size);
		calc(n, a);
		i = size - 1;
		while (i != -1)
		{
			printf("%d", *(a + i));
			i--;
		}
		puts("");
	}
	else
	{	
		switch (n)
		{
		case 0:puts("0!=1"); break;
		case 1:puts("1!=1"); break;
		default:puts("o(≧口≦)o"); break;
		}
	}
	puts("请按任意键结束");
	_getch();
	return 0;
}

int calc(int n, int* a)
{
	int i, j;
	while (n > 1)
	{
		for (i = 0; i < size; i++)
		{
			if (*(a + i) != 0)
				* (a + i) *= n;
		}
		for (j = 0; j < size; j++)
		{
			if (*(a + j) > 9)
			{
				*(a + (j + 1)) += *(a + j) / 10;
				*(a + j) %= 10;
			}
		}
		n--;
	}
	return 0;
}
