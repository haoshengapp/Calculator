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
	(char*)"*��������[2,x]������*",
	(char*)"*�ж�x�Ƿ�Ϊ����*",
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


/*��������[2,x]������*/
int prt1(int y, int cnt)
{
	if (y == 1)
	{
		printf("2 ");//�����һ������
	}
	else if (cnt == 0)
	{
		printf("%d ", y);//�����2����
	}
	else;

	return 0;
}

int single(int y, int cnt)
{
	int n;//����
	int z = (int)(sqrt(y)) + 1;//��������

	for (n = 3; n < z; n += 2)//������[3,sqrt(y)]�ϵ�����n
	{
		if (y % n == 0)//y��������
		{
			cnt++;//����
		}
		else;
	}
	prt1(y, cnt);

	return 0;
}

int calc(void)
{
	int x, y;
	printf("����������: ");
	scanf_s("%d", &x);

	for (y = 1; y < x + 1; y += 2)//������[1,x)�ϵ�����y
	{
		single(y, 0);//��������
	}

	system("pause");
	return 0;
}

/*�ж�x�Ƿ�Ϊ����*/
int prt2(int cnt, int x)
{
	if (cnt == 0 && x > 1)//��������
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}

	return 0;
}

int judge(void)
{
	int x;
	printf("������x: ");
	scanf_s("%d", &x);
	int cnt = 0;
	int n;//����
	int z = (int)(sqrt(x)) + 1;//��������

	for (n = 2; n < z; n++)//������[2,sqrt(x)]������n
	{
		if (x % n == 0)//x��������
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
			case 0:	calc();break;
			case 1:	judge();break;
			case 2:	return 0;	//�˳�
			}
		}
	}
	return 0;
}