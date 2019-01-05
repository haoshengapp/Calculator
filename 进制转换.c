#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
const long long max = 9223372036854775807;//2^63 - 1
long long x;

int bin_input(void)
{
	unsigned int i;
	char str[65];
	int a[64] = { 0 };

	printf("[BIN]\n");
	scanf_s("%s", str, 65);
	if (strlen(str) == 64 && str[0] == 1)
	{
		for (i = 0; i < 64; i++)
		{
			a[i] = (int)(str[i] - '0');
			if (a[i] != 0 && a[i] != 1)
			{
				printf("语法错误\n");
				return 0;
			}
		}
		for (i = 0; i < 64; i++)
		{
			a[i] = 1 - a[i];
			x = 2 * x + a[i];
		}
		x = x - 1 - max;
	}
	else 
	{
		for (i = 0; i < strlen(str); i++)
		{
			a[i] = (int)(str[i] - '0');
			if (a[i] != 0 && a[i] != 1)
			{
				printf("语法错误\n");
				return 0;
			}
			else
				x = 2 * x + a[i];
		}
	}

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n0x%16.16llX\n", x);
	printf("[OCT]\n0%llo\n", x);

	return 0;
}

int bin_output(void)
{
	int i, j, iota;
	int a[4][4] = { 0 };

	if (x != 0)
	{
		if (x < 0)
		{
			x = x + max + 1;
			a[3][3] += 1000;
		}

		for (i = 0; x > 0; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iota = x % 16;
				switch (iota)
				{
				case(1):a[i][j] += 1; break;
				case(2):a[i][j] += 10; break;
				case(3):a[i][j] += 11; break;
				case(4):a[i][j] += 100; break;
				case(5):a[i][j] += 101; break;
				case(6):a[i][j] += 110; break;
				case(7):a[i][j] += 111; break;
				case(8):a[i][j] = 1000; break;
				case(9):a[i][j] = 1001; break;
				case(10):a[i][j] = 1010; break;
				case(11):a[i][j] = 1011; break;
				case(12):a[i][j] = 1100; break;
				case(13):a[i][j] = 1101; break;
				case(14):a[i][j] = 1110; break;
				case(15):a[i][j] = 1111; break;
				default:break;
				}
				x /= 16;
			}
		}
	}

	for (i = 3; i > -1; i--)
	{
		for (j = 3; j > -1; j--)
			printf("%4.4d ", a[i][j]);//空格
		printf("\n");
	}

	return 0;
}

int dec_input(void)
{
	printf("[DEC]\n");
	scanf_s("%lld", &x);
	printf("[HEX]\n0x%16.16llX\n", x);
	printf("[OCT]\n0%llo\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int hex_input(void)
{
	printf("[HEX]\n0x");
	scanf_s("%llx", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[OCT]\n0%llo\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int oct_input(void)
{
	printf("[OCT]\n");
	scanf_s("%llo", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n0x%16.16llX\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int main(void)
{
	int index;

	printf("请选择进制:\n1.DEC; 2.HEX; 3.BIN; 4.OCT; 5.取值范围.\n");
	scanf_s("%d", &index);

	switch (index)
	{
	case(1):dec_input(); break;
	case(2):hex_input(); break;
	case(3):bin_input(); break;
	case(4):oct_input(); break;
	case(5):printf("取值范围[0,%lld].\n", max); break;
	default:printf("输入错误.\n"); break;
	}

	system("pause");
	return 0;
}
