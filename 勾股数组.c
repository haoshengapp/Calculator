# include <stdio.h>
# include <windows.h>
int quit(void);

int triple(void)
{
	int a, b, c, x, y, z, cnt0, cnt1;
	do
	{
		printf("请输入数组下限:");
		scanf_s("%d", &cnt0);
		printf("请输入数组上限:");
		scanf_s("%d", &cnt1);

		x = cnt0 - 1;
		for (a = cnt0; a < cnt1 + 1; a++)
		{
			x++;
			y = cnt0 - 1;
			for (b = cnt0; b < cnt1 + 1; b++)
			{
				y++;
				z = cnt0 - 1;
				for (c = cnt0; c < cnt1 + 1; c++)
				{
					z++;
					if (x * x + y * y == z * z && x < y)
					{
						printf("x = %d, y = %d, z =%d.\n", x, y, z);
					}
					else;
				}
			}
		}
	} while (quit());

	return 0;
}