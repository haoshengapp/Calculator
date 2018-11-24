#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))

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
	(char*)"*��֪(mx + ny),��xy��ȡֵ��Χ*",
	(char*)"*��֪xy,��(mx + ny)��ȡֵ��Χ*",
	(char*)"*����*\n\n"
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

int f5i(void)
{
	double m, n, p, s;
	char ch;
	printf("������\nm: ");
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
	printf("������\nm: ");
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
			case 0:f5i(); break;
			case 1:f5ii(); break;
			case 2:return 0;	//�˳�
			}
		}
	}
	return 0;
}