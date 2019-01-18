#ifndef _TOOLBOX_H
#define _TOOLBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void checkch(void)//处理非法字符
{
	char ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}

int quit(void)//退出
{
	printf("[q:退出]\n");
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
