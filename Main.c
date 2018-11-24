#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
#define TITLE "Calculator"
#define AUTHOR "作者:卡布奇诺"
#define DATE "日期:2018年11月24日"

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
	(char*)"*一元二次方程*",
	(char*)"*一元三次方程*",
	(char*)"*一元二次不等式(开区间)*",
	(char*)"*一元二次不等式(闭区间)*",
	(char*)"*基本不等式*",
	(char*)"*心形点阵*",
	(char*)"*进制转换*",
	(char*)"*质数*",
	(char*)"*勾股数组*",
	(char*)"*退出*\n\n"
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
	pos.X = 10;
	pos.Y = 0;	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut, pos);	//调用printf在控制台对应的位置上输出 
	printf("%s", TITLE);

	pos.X = 10;
	pos.Y = 1;
	SetConsoleCursorPosition(hOut, pos);
	printf("%s", AUTHOR);

	pos.X = 10;
	pos.Y = 2;
	SetConsoleCursorPosition(hOut, pos);
	printf("%s", DATE);

	for (i = 0; i < size; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色
		if (i == index)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);

			pos.X = 8;
			pos.Y = 5 + i;	//设置光标坐标
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
		//否则显示为白色 
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			pos.X = 10;
			pos.Y = 5 + i;	//设置光标坐标
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

int f1(void)//一元二次方程
{
	double a, b, c, x1, x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%lf", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");

	if (a == 0)
	{
		if (b != 0)
		{
			x1 = -c / b;
			printf("x = %lf.\n", x1);
		}
		else if (c != 0)
		{
			printf("无解.\n");
		}
		else
		{
			printf("任意复数.\n");
		}
	}

	else
	{
		double delta = b * b - 4 * a * c;

		if (delta > 0)
		{
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("x1 = %lf, x2 = %lf,\n", x1, x2);
		}

		else if (delta == 0)
		{
			x1 = -b / (2 * a);
			printf("x1 = x2 = %lf,\n", x1);
		}
		else
		{
			x1 = -b / (2 * a);
			x2 = sqrt(-delta) / (2 * a);
			printf("x = %lf ± %lf * i,\n", x1, x2);
		}

		double y = (4 * a * c - b * b) / (4 * a);

		if (a > 0)
		{
			printf("Min(y) = %lf.\n", y);
		}

		else
		{
			printf("Max(y) = %lf.\n", y);
		}
	}
	system("pause");
	return 0;
}

int f3(void)//一元二次不等式(开区间)
{
	double a, b, c, x1, x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%lf", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("解集为 ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("(%lf, +∞).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-∞, %lf).\n", x1);
		}
		else if (c > 0)
		{
			printf("(-∞, +∞).\n");
		}
		else
		{
			printf("空集.\n");
		}
	}

	else
	{
		double delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta == 0)
			{
				x1 = -b / (2 * a);
				printf("(-∞, %lf)∪(%lf, +∞).\n", x1, x1);
			}

			else if (delta > 0)
			{
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
				printf("(-∞, %lf)∪(%lf, +∞).\n", x1, x2);
			}

			else
			{
				printf("(-∞, +∞).\n");
			}
		}

		else
		{
			if (delta > 0)
			{
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
				printf("(%lf, %lf).\n", x1, x2);
			}

			else
			{
				printf("空集.");

			}
		}
	}
	system("pause");
	return 0;
}

int f4(void)//一元二次不等式(闭区间)
{
	double a, b, c, x1, x2;
	char ch;

	printf("请输入二次项系数:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入一次项系数:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("请输入常数项:\n");
	scanf_s("%lf", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("解集为 ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("[%lf, +∞).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-∞, %lf]).\n", x1);
		}
		else if (c >= 0)
		{
			printf("(-∞, +∞).\n");
		}
		else
		{
			printf("空集.\n");
		}
	}

	else
	{
		double delta = b * b - 4 * a * c;
		if (a > 0)
		{
			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("(-∞, %lf]∪[%lf, +∞).\n", x2, x1);
			}
			else
			{
				printf("(-∞, +∞).\n");
			}
		}
		else
		{
			if (delta > 0)
			{
				x1 = (-b + sqrt(delta)) / (2 * a);
				x2 = (-b - sqrt(delta)) / (2 * a);
				printf("[%lf, %lf].\n", x2, x1);
			}
			else if (delta == 0)
			{
				x1 = -b / (2 * a);
				printf("{ %lf }.\n", x1);
			}
			else
			{
				printf("空集.\n");
			}
		}
	}
	system("pause");
	return 0;
}

int f6(void)//心形点阵
{
	double x, y;

	for (y = 1.3; y > -1; y -= 0.1)
	{
		for (x = 1.2; x > -1.2; x -= 0.05)
		{
			double P = x * x + y * y - 1;
			double Q = x * x * y * y * y;

			if (pow(P, 3) - Q < 0)
			{
				printf(".");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

int main()
{
	int index = 0;
	// 获取当前的句柄-- - 设置为标准输出句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitleA(TITLE);
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
			case 0:f1(); break;						//一元二次方程
			case 1:system("一元三次方程"); break;	//一元三次方程
			case 2:f3(); break;						//一元二次不等式1
			case 3:f4(); break;						//一元二次不等式2
			case 4:system("基本不等式.exe"); break;	//基本不等式
			case 5:f6(); break;						//心形点阵
			case 6:system("进制转换.exe"); break;	//进制转换
			case 7:system("质数.exe"); break;		//质数
			case 8:system("勾股数组.exe"); break;	//勾股数组
			case 9:return 0;						//退出
			}
		}
	}
	return 0;
}