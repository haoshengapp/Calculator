#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
#define TITLE "Calculator"
#define AUTHOR "����:������ŵ"
#define DATE "����:2018��11��24��"

//����ö��Keyboard�ļ�ֵ����
enum
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESC = 27,
};

//����Ҫ��ʾ�Ĳ˵�
char *menu[] =
{
	(char*)"*һԪ���η���*",
	(char*)"*һԪ���η���*",
	(char*)"*һԪ���β���ʽ(������)*",
	(char*)"*һԪ���β���ʽ(������)*",
	(char*)"*��������ʽ*",
	(char*)"*���ε���*",
	(char*)"*����ת��*",
	(char*)"*����*",
	(char*)"*��������*",
	(char*)"*�˳�*\n\n"
};

//����ṹ��
CONSOLE_CURSOR_INFO cci;
//����Ĭ�ϵ�����λ��
COORD pos = { 0,0 };

//��ʾ�˵�
void showmenu(HANDLE hOut, char **menu, int size, int index)
{
	int i;
	system("cls");	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8);	//��ʼ������̨��ʾ��X,Y�������
	pos.X = 10;
	pos.Y = 0;	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut, pos);	//����printf�ڿ���̨��Ӧ��λ������� 
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
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ
		if (i == index)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8);

			pos.X = 8;
			pos.Y = 5 + i;	//���ù������
			SetConsoleCursorPosition(hOut, pos);

			printf("%s", menu[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			pos.X = 10;
			pos.Y = 5 + i;	//���ù������
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

int f1(void)//һԪ���η���
{
	double a, b, c, x1, x2;
	char ch;

	printf("�����������ϵ��:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("������һ����ϵ��:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("�����볣����:\n");
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
			printf("�޽�.\n");
		}
		else
		{
			printf("���⸴��.\n");
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
			printf("x = %lf �� %lf * i,\n", x1, x2);
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

int f3(void)//һԪ���β���ʽ(������)
{
	double a, b, c, x1, x2;
	char ch;

	printf("�����������ϵ��:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("������һ����ϵ��:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("�����볣����:\n");
	scanf_s("%lf", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("�⼯Ϊ ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("(%lf, +��).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-��, %lf).\n", x1);
		}
		else if (c > 0)
		{
			printf("(-��, +��).\n");
		}
		else
		{
			printf("�ռ�.\n");
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
				printf("(-��, %lf)��(%lf, +��).\n", x1, x1);
			}

			else if (delta > 0)
			{
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
				printf("(-��, %lf)��(%lf, +��).\n", x1, x2);
			}

			else
			{
				printf("(-��, +��).\n");
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
				printf("�ռ�.");

			}
		}
	}
	system("pause");
	return 0;
}

int f4(void)//һԪ���β���ʽ(������)
{
	double a, b, c, x1, x2;
	char ch;

	printf("�����������ϵ��:\n");
	scanf_s("%lf", &a);
	while ((ch = getchar()) != '\n')
		continue;
	printf("������һ����ϵ��:\n");
	scanf_s("%lf", &b);
	while ((ch = getchar()) != '\n')
		continue;
	printf("�����볣����:\n");
	scanf_s("%lf", &c);
	while ((ch = getchar()) != '\n')
		continue;
	printf("***********************************\n");
	printf("�⼯Ϊ ");

	if (a == 0)
	{
		if (b > 0)
		{
			x1 = -c / b;
			printf("[%lf, +��).\n", x1);
		}
		else if (b < 0)
		{
			x1 = -c / b;
			printf("(-��, %lf]).\n", x1);
		}
		else if (c >= 0)
		{
			printf("(-��, +��).\n");
		}
		else
		{
			printf("�ռ�.\n");
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
				printf("(-��, %lf]��[%lf, +��).\n", x2, x1);
			}
			else
			{
				printf("(-��, +��).\n");
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
				printf("�ռ�.\n");
			}
		}
	}
	system("pause");
	return 0;
}

int f6(void)//���ε���
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
	// ��ȡ��ǰ�ľ��-- - ����Ϊ��׼������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitleA(TITLE);
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
			case 0:f1(); break;						//һԪ���η���
			case 1:system("һԪ���η���"); break;	//һԪ���η���
			case 2:f3(); break;						//һԪ���β���ʽ1
			case 3:f4(); break;						//һԪ���β���ʽ2
			case 4:system("��������ʽ.exe"); break;	//��������ʽ
			case 5:f6(); break;						//���ε���
			case 6:system("����ת��.exe"); break;	//����ת��
			case 7:system("����.exe"); break;		//����
			case 8:system("��������.exe"); break;	//��������
			case 9:return 0;						//�˳�
			}
		}
	}
	return 0;
}