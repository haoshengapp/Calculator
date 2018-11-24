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
	(char*)"*求在区间[2,x]的质数*",
	(char*)"*判断x是否为质数*",
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

	for (n = 3; n < z; n += 2)//在区间[3,sqrt(y)]上的奇数n
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

	system("pause");
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
			case 0:	calc();break;
			case 1:	judge();break;
			case 2:	return 0;	//退出
			}
		}
	}
	return 0;
}