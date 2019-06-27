#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
void calc(int n, int* a);
int z = 0;//结尾零的个数

int main()
{
	int n, i;
	puts("[请输入n]");
	scanf_s("%d", &n);
	if (n > 1 && n < 200000)
	{
		i = (int)((n + 0.5) * log10(n) - 0.4342945 * n + 1.3990899);//斯特林公式
		//int m = i;//用于输出txt文件
		printf("[%d的阶乘](%d位)\n加载中. . .\n", n, i);
		int* a = (int*)calloc(i, 4);
		if (a)
		{
			*a = 1;
			calc(n, a);
			if (z < 5)
			{
				while (i > 0)
				{
					i--;
					printf("%d", *(a + i));
				}
			}
			else
			{
				while (i > z)
				{
					i--;
					printf("%d", *(a + i));
				}
				printf("(%d个0)", z);
			}
			/*
				FILE* fp;
				fopen_s(&fp, "newtext.txt", "w");
				if (fp == NULL)
				{
					printf("Error!");
					exit(1);
				}
				while (m > 0)
				{
					m--;
					fprintf(fp, "%d", *(a + m));//输出txt文件
				}
				fclose(fp);
			*/
			free(a);
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
	puts("请按任意键结束. . .");
	_getch();
	return 0;
}

void calc(int n, int* a)
{
	int i, j, k, size;
	for (j = 2; j <= n; j++)
	{
		size = (int)((j + 0.5) * log10(j) - 0.4342945 * j + 1.3990899);
		for (i = z; i < size; i++)
		{
			*(a + i) *= j;
		}
		for (i = z; i < size; i++)
		{
			if (*(a + i) > 9)
			{
				*(a + (i + 1)) += *(a + i) / 10;
				*(a + i) %= 10;
			}
		}
		for (z = 0, k = 5; k <= j; k *= 5)
		{
			z += j / k;
		}
	}
}
