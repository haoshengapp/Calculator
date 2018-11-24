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
	(char*)"*返回*\n\n"
};
CONSOLE_CURSOR_INFO cci;
COORD pos = { 0,0 };
void showmenu(HANDLE hOut, char **menu, int size, int index)
{
	int i;
	system("cls");	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);	//初始化控制台显示的X,Y轴的坐标

	for (i = 0; i < size; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色
		if (i == index)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);

			pos.X = 8;
			pos.Y = i;	//设置光标坐标
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
		//否则显示为白色 
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			pos.X = 10;
			pos.Y = i;	//设置光标坐标
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
	}
	//刷新标准输出缓冲区 
	fflush(stdout);
}

//获取用户输入的接口 
int get_userinput(int *index, int size)
{
	int ch = _getch();

	switch (ch)
	{
	case UP:
		if (*index > 0)
			*index -= 1;
		break;//光标向上移动 
	case DOWN:
		if (*index < size)
			*index += 1;
		break; //下
	case LEFT:	return ESC;//左 
	case RIGHT:	return ENTER;//右 
	case ENTER:	return ENTER;//回车 
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
	// 获取当前的句柄-- - 设置为标准输出句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &cci);		//获取光标信息
	cci.dwSize = 1;							//设置光标大小
	cci.bVisible = 0;						//设置光标不可见 FALSE
	SetConsoleCursorInfo(hOut, &cci);		//设置(应用)光标信息

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
			case 4:	return 0;	//退出
			}
		}
	}
	return 0;
}
