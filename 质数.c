#include <stdio.h>
#include <math.h>
int quit(void);
void checkch(void);

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

	for (n = 3; n < z; n += 2)//����[3,sqrt(y)]�ϵ�����
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

	return 0;
}

int prime(void)
{
	int index;

	do
	{
		printf("1.��������[2,x]������;\n2.�ж�x�Ƿ�Ϊ����.\n");
		scanf_s("%d", &index);
		checkch();
		switch (index)
		{
		case 1:	calc(); break;
		case 2:	judge(); break;
		}
	} while (quit());
	return 0;
}