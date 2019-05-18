#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int size;//位数
int gamma(int n, int* a);//计算
void sci(int n);//分配空间

int main()
{
	int* a;
	int n, i;
	puts("[请输入n]");
	scanf_s("%d", &n);
	if (n > 18)
	{
		sci(n);
		a = (int*)calloc(size, 4);
		*a = 1;

		printf("[%d的阶乘](%d位)\n加载中...\n", n, size);
		gamma(n, a);
		i = size - 1;
		while (*(a + i) == 0)
		{
			i--;
		}
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
		case 2:puts("2!=2"); break;
		case 3:puts("3!=6"); break;
		case 4:puts("4!=24"); break;
		case 5:puts("5!=120"); break;
		case 6:puts("6!=720"); break;
		case 7:puts("7!=5040"); break;
		case 8:puts("8!=4,0320"); break;
		case 9:puts("9!=36,2880"); break;
		case 10:puts("10!=362,8800"); break;
		case 11:puts("11!=3991,6800"); break;
		case 12:puts("12!=4,7900,1600"); break;
		case 13:puts("13!=62,2702,0800"); break;
		case 14:puts("14!=871,7829,1200"); break;
		case 15:puts("15!=1,3076,7436,8000"); break;
		case 16:puts("16!=20,9227,8988,8000"); break;
		case 17:puts("17!=355,6874,2809,6000"); break;
		case 18:puts("18!=6402,3737,0572,8000"); break;
		default:puts("o(≧口≦)o");break;
		}			
	}
	puts("请按任意键结束");
	_getch();
	return 0;
}

int gamma(int n, int* a)
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			*(a + j) *= n;
		}
		for (k = 0; k < size; k++)
		{
			if (*(a + k) > 9)
			{
				*(a + (k + 1)) += *(a + k) / 10;
				*(a + k) %= 10;
			}
		}
		if (n > 1)
			n--;
		else
			return 1;
	}
	return 0;
}

void sci(int n)
{
	double a = 0;
	while (n > 1)
	{
		a += log(n);
		n--;
	}
	size = (int)(a * 0.434294481903251827651 + 1);

}
