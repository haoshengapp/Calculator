#include <stdio.h>
#include <string.h>
#include <limits.h>
int quit(void);
long long x = 0;

int bin_input(void)
{
	unsigned int i;
	char str[65];
	int a[64] = { 0 };

	printf("[BIN]\n");
	scanf_s("%s", str, 65);

	for (i = 0; i < strlen(str); i++)
	{
		a[i] = (int)(str[i] - '0');//charתint
		if (a[i] == 0 || a[i] == 1)//����﷨����
		{
			x = 2 * x + a[i];//תʮ����
		}
		else
		{
			printf("�﷨����.\n");
			return 0;
		}
	}

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n%#16.16llX\n", x);
	printf("[OCT]\n%#llo\n", x);

	return 0;
}

int bin_output(void)
{
	int i, j, iota;
	int a[4][4] = { 0 };

	if (x != 0)
	{
		if (x < 0)//������
		{
			x = x + _I64_MAX + 1;//x + 2^63
			a[3][3] = 1000;//���λ��1
		}

		for (i = 0; x > 0; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iota = x % 16;
				switch (iota)
				{
				case(1):a[i][j]++; break;
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
		for (j = 3; j > -1; j--)//a[i][j]
			printf("%4.4d ", a[i][j]);//�ո�
		printf("\n");
	}

	return 0;
}

int dec_input(void)
{
	printf("[DEC]\n");
	scanf_s("%lld", &x);

	printf("[HEX]\n%#16.16llX\n", x);
	printf("[OCT]\n%#llo\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int hex_input(void)
{
	printf("[HEX]\n0x");
	scanf_s("%llx", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[OCT]\n%#llo\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int oct_input(void)
{
	printf("[OCT]\n");
	scanf_s("%llo", &x);

	printf("[DEC]\n%lld\n", x);
	printf("[HEX]\n%#16.16llX\n", x);

	printf("[BIN]\n");
	bin_output();

	return 0;
}

int numeration(void)
{
	int index;
	do
	{
		printf("��ѡ�����:\n1.DEC; 2.HEX; 3.BIN; 4.OCT.\n");
		scanf_s("%d", &index);

		switch (index)
		{
		case(1):dec_input(); break;
		case(2):hex_input(); break;
		case(3):bin_input(); break;
		case(4):oct_input(); break;
		default:printf("�������.\n"); break;
		}
	} while (quit());

	return 0;
}
