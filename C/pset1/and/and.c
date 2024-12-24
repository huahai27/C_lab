#include <stdio.h>

int main(void)
{
	int a[20] = {0};
	int b[20] = {0};
	int c[20] = {0};
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt = 0;

	while (cnt1 < 21)
	{
		scanf("%d", &a[cnt1]);
		cnt1++;
		if (a[cnt1 - 1] == -1)
		{
			cnt1--;
			break;
		}
	}
	while (cnt2 < 21)
	{
		scanf("%d", &b[cnt2]);
		cnt2++;
		if (b[cnt2 - 1] == -1)
		{
			cnt2--;
			break;
		}
	}

	for (int i = 0; i < cnt1; i++)
	{
		for (int j = 0; j < cnt2; j++)
		{
			if (a[i] == b[j])
			{
				c[cnt] = a[i];
				cnt++;
				break;
			}
		}
	}

	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 0; j < cnt - 1 - i; j++)
		{
			if (c[j] > c[j + 1])
			{
				int tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", c[i]);
	}

	return 0;
}
