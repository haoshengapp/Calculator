#ifndef _TOOLBOX_H
#define _TOOLBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void checkch(void)//����Ƿ��ַ�
{
	char ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}

int quit(void)//�˳�
{
	printf("[q:�˳�]\n");
	char ch = _getch();

	if (ch != 'q')
	{
		system("cls");
		return 1;
	}
	else
	{
		return 0;
	}
}

void asterisks(void)
{
	puts("*******************************");
}

#endif
