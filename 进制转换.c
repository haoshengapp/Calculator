#include <stdio.h>
#include <math.h>
#include <windows.h>
const long long int max = 9223372036854775807;//2^63 - 1

int dec_input(void)
{
	int i, iota;
	long long int x;
	int a[16] = { 0 };
	printf("[DEC]\n");
	scanf("%lld", &x);

	printf("[HEX]\n0x%16.16llX\n", x);
	printf("[OCT]\n0%llo\n", x);
	printf("[BIN]\n");
	for (i = 0; x > 0; i++)
	{
		iota = x % 16;
		switch (iota)
		{
		case(1):a[i] = 1; break;
		case(2):a[i] = 10; break;
		case(3):a[i] = 11; break;
		case(4):a[i] = 100; break;
		case(5):a[i] = 101; break;
		case(6):a[i] = 110; break;
		case(7):a[i] = 111; break;
		case(8):a[i] = 1000; break;
		case(9):a[i] = 1001; break;
		case(10):a[i] = 1010; break;
		case(11):a[i] = 1011; break;
		case(12):a[i] = 1100; break;
		case(13):a[i] = 1101; break;
		case(14):a[i] = 1110; break;
		case(15):a[i] = 1111; break;
		default:break;
		}
		x /= 16;
	}
	for (i = 15; i > -1; i--)
	{
		if (i % 4 == 0)
		{
			printf("%4.4d\n", a[i]);//16位一换行
		}
		else
		{
			printf("%4.4d ", a[i]);//4位一空格
		}
	}

	return 0;
}

int hex_input(void)
{
	int i, iota;
	long long int x;
	int a[16] = { 0 };
	printf("[HEX]\n0x");
	scanf("%llx", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[OCT]\n0%llo\n", x);
	printf("[BIN]\n");
	for (i = 0; x > 0; i++)
	{
		iota = x % 16;
		switch (iota)
		{
		case(1):a[i] = 1; break;
		case(2):a[i] = 10; break;
		case(3):a[i] = 11; break;
		case(4):a[i] = 100; break;
		case(5):a[i] = 101; break;
		case(6):a[i] = 110; break;
		case(7):a[i] = 111; break;
		case(8):a[i] = 1000; break;
		case(9):a[i] = 1001; break;
		case(10):a[i] = 1010; break;
		case(11):a[i] = 1011; break;
		case(12):a[i] = 1100; break;
		case(13):a[i] = 1101; break;
		case(14):a[i] = 1110; break;
		case(15):a[i] = 1111; break;
		default:break;
		}
		x /= 16;
	}
	for (i = 15; i > -1; i--)
	{
		if (i % 4 == 0)
		{
			printf("%4.4d\n", a[i]);//16位一换行
		}
		else
		{
			printf("%4.4d ", a[i]);//4位一空格
		}
	}

	return 0;
}

int bin_input(void)
{
	int i, j, iota;
	long long int x;
	int a[8] = { 0 };
	printf("[BIN]\n");
	for (i = 0; i < 8; i++)
	{
		printf("[%d,%d]:", 57 - 8 * i, 64 - 8 * i);
		scanf("%d", &a[i]);
		x = 0;
		for (j = 0; j < 8; j++)
		{
			iota = (a[i] < pow(10, 7 - j)) ? 0 : 1;
			x *= 2;
			if(iota == 1)
			{
				a[i] -= (int)pow(10, 7 - j);
				x++;
			}
		}
		a[i] = (int)x;
	}

	x = 0;
	for (i = 0; i < 8; i++)
	{
		x *= 256;
		x += a[i];
	}

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n0x%16.16llX\n", x);
	printf("[OCT]\n0%llo\n", x);

	return 0;
}

int oct_input(void)
{
	int i, iota;
	long long int x;
	int a[16] = { 0 };
	printf("[OCT]\n");
	scanf("%llo", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n0x%16.16llX\n", x);
	printf("[BIN]\n");
	for (i = 0; x > 0; i++)
	{
		iota = x % 16;
		switch (iota)
		{
		case(1):a[i] = 1; break;
		case(2):a[i] = 10; break;
		case(3):a[i] = 11; break;
		case(4):a[i] = 100; break;
		case(5):a[i] = 101; break;
		case(6):a[i] = 110; break;
		case(7):a[i] = 111; break;
		case(8):a[i] = 1000; break;
		case(9):a[i] = 1001; break;
		case(10):a[i] = 1010; break;
		case(11):a[i] = 1011; break;
		case(12):a[i] = 1100; break;
		case(13):a[i] = 1101; break;
		case(14):a[i] = 1110; break;
		case(15):a[i] = 1111; break;
		default:break;
		}
		x /= 16;
	}
	for (i = 15; i > -1; i--)
	{
		if (i % 4 == 0)
		{
			printf("%4.4d\n", a[i]);//16位一换行
		}
		else
		{
			printf("%4.4d ", a[i]);//4位一空格
		}
	}

	return 0;
}

int main()
{
	int index;
	printf("请选择进制:\n1.DEC; 2.HEX; 3.BIN; 4.OCT.\n");
	scanf("%d", &index);

	switch (index)
	{
	case(1):dec_input(); break;
	case(2):hex_input(); break;
	case(3):bin_input(); break;
	case(4):oct_input(); break;
	case(5):printf("取值范围[0,%lld]\n", max); break;
	default:printf("输入错误,请重新输入.\n"); break;
	}

	system("pause");
	return 0;
}
