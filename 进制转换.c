#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))

enum
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27,
};
char *menu[] =
{
	(char*)"*Dec[3,1023]*",
	(char*)"*Hex[3,3FF]*",
	(char*)"*Bin[11,1111111111]*",
	(char*)"*Oct[3,1777]*",
	(char*)"*����*\n\n"
};
CONSOLE_CURSOR_INFO cci;
COORD pos = { 0,0 };
void showmenu(HANDLE hOut, char **menu, int size, int index)
{
	int i;
	system("cls");	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);	//��ʼ������̨��ʾ��X,Y�������

	for (i = 0; i < size; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ
		if (i == index)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);

			pos.X = 8;
			pos.Y = i;	//���ù������
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			pos.X = 10;
			pos.Y = i;	//���ù������
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
	}
	//ˢ�±�׼��������� 
	fflush(stdout);
}

//��ȡ�û�����Ľӿ� 
int get_userinput(int *index, int size)
{
	int ch = _getch();

	switch (ch)
	{
	case UP:
		if (*index > 0)
			*index -= 1;
		break;//��������ƶ� 
	case DOWN:
		if (*index < size)
			*index += 1;
		break; //��
	case LEFT:	return ESC;//�� 
	case RIGHT:	return ENTER;//�� 
	case ENTER:	return ENTER;//�س� 
	case ESC:	return ESC;//ESC
	}
	return 0;
}

int in_bin(int x)
{
	int start = x;
	int y = 0;
	int bit = (int)(log10(x));
	int position = 1;
	int i, end;

	for (i = 0; i <= bit; i++)
	{
		end = x % 10;
		y += end * position;
		x = (x - end) / 10;
		position *= 2;
	}

	printf("Dec(x) = %d\n", y);
	printf("Hex(x) = %X\n", y);
	printf("Bin(x) = %d\n", start);
	printf("Oct(x) = %o\n", y);

	return 0;
}

int out_bin(int x)
{
	int start = x;
	int y = 0;
	int i, bit;

	do
	{
		bit = 0;
		for (i = 2; i <= x; i *= 2)
		{
			bit++;
		}
		y += (int)(pow(10, bit));
		x -= i / 2;
	} while (x > 0);

	printf("Dec(x) = %d\n", start);
	printf("Hex(x) = %X\n", start);
	printf("Bin(x) = %d\n", y);
	printf("Oct(x) = %o\n", start);

	return 0;
}

int dec(void)
{
	int x;

	printf("Dec(x) = ");
	scanf_s("%d", &x);
	printf("***********************************\n");

	if (x > 2 && x < 1024)
		out_bin(x);
	else;
	system("pause");
	return 0;
}

int hex(void)
{
	int x;

	printf("Hex(x) = ");
	scanf_s("%X", &x);
	printf("***********************************\n");

	if (x > 2 && x < 1024)
		out_bin(x);
	else;
	system("pause");
	return 0;
}

int bin(void)
{
	int x;

	printf("Bin(x) = ");
	scanf_s("%d", &x);
	printf("***********************************\n");

	if (x > 10 && x < 1111111112)
		in_bin(x);
	else;
	system("pause");
	return 0;
}

int oct(void)
{
	int x;

	printf("Oct(x) = ");
	scanf_s("%o", &x);
	printf("***********************************\n");

	if (x > 2 && x < 1024)
		out_bin(x);
	else;
	system("pause");
	return 0;
}

int main(void)
{
	int index = 0;
	// ��ȡ��ǰ�ľ��-- - ����Ϊ��׼������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &cci);		//��ȡ�����Ϣ
	cci.dwSize = 1;							//���ù���С
	cci.bVisible = 0;						//���ù�겻�ɼ� FALSE
	SetConsoleCursorInfo(hOut, &cci);		//����(Ӧ��)�����Ϣ

	while (1)
	{
		showmenu(hOut, menu, NR(menu), index);
		int ret = get_userinput(&index, NR(menu));
		if (ret == ESC)
			break;
		if (ret == ENTER)
		{
			switch (index)
			{
			case 0:	dec(); break;
			case 1:	hex(); break;
			case 2:	bin(); break;
			case 3:	oct(); break;
			case 4:	return 0;	//�˳�
			}
		}
	}
	return 0;
}
