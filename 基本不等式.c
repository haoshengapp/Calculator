#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))

//定义枚举Keyboard的键值数据
enum
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27,
};

//定义要显示的菜单
char *menu[] =
{
	(char*)"*已知(mx + ny),求xy的取值范围*",
	(char*)"*已知xy,求(mx + ny)的取值范围*",
	(char*)"*返回*\n\n"
};

//定义结构体
CONSOLE_CURSOR_INFO cci;
//定义默认的坐标位置
COORD pos = { 0,0 };
//显示菜单
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

int f5i(void)
{
	double m, n, p, s;
	char ch;
	printf("请输入\nm: ");
	scanf_s("%lf", &m);
	while ((ch = getchar()) != '\n')
		continue;
	printf("n: ");
	scanf_s("%lf", &n);
	while ((ch = getchar()) != '\n')
		continue;
	printf("(mx + ny): ");
	scanf_s("%lf", &s);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");

	p = (s*s) / (4 * m*n);
	printf("P <= %lf.\n", p);
	system("pause");
	return 0;
}

int f5ii(void)
{
	double m, n, p, s;
	char ch;
	printf("请输入\nm: ");
	scanf_s("%lf", &m);
	while ((ch = getchar()) != '\n')
		continue;
	printf("n: ");
	scanf_s("%lf", &n);
	while ((ch = getchar()) != '\n')
		continue;
	printf("xy: ");
	scanf_s("%lf", &p);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");

	s = 2 * sqrt(m*n*p);
	printf("S >= %lf.\n", s);
	system("pause");
	return 0;
}

int main()
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
			case 0:f5i(); break;
			case 1:f5ii(); break;
			case 2:return 0;	//退出
			}
		}
	}
	return 0;
}