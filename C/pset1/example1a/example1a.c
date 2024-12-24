#include <stdio.h>
#include <math.h>

int main(void)
{
	int m = 0;
	int n = 0;
	int sum = 0;
	int flag = 0;
	scanf("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		int tmp = i;
		sum = 0;

		while (tmp > 0)
		{
			int num = tmp % 10;
			sum += pow(num, 3);
			tmp /= 10;
		}

		if (sum > 100 && sum == i)
		{
			printf("%d ", i);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("No Answer\n");
	}

	return 0;
}
