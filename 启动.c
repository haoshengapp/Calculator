#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
#define TITLE "Calculator"
#define AUTHOR "����:������ŵ"
#define DATE "����:2019��1��19��"

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
	(char*)"*���κ���*",
	(char*)"*һԪ���η���*",
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

int heart(void)//���ε���
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
	_getch();
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
			case 0:system("���κ���.exe"); break;		//���κ���
			case 1:system("һԪ���η���.exe"); break;	//һԪ���η���
			case 2:system("��������ʽ.exe"); break;		//��������ʽ
			case 3:heart(); break;						//���ε���
			case 4:system("����ת��.exe"); break;		//����ת��
			case 5:system("����.exe"); break;			//����
			case 6:system("��������.exe"); break;		//��������
			case 7:return 0;							//�˳�
			}
		}
	}
	return 0;
}