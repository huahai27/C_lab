#include <stdio.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	printf("%d,", num);
	int digit[100] = {0};
	int dig = 0;

	int tmp = num;
	int sum = 0;
	int sum1 = 1;

	while (tmp > 0)
	{
		int i = tmp % 10;
		digit[dig] = i;
		dig++;
		sum1 = 1;
		for (int j = 1; j <= i; j++)
		{
			sum1 *= j;
		}
		sum += sum1;
		tmp /= 10;
	}
	for (int i = dig - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			printf("%d!+", digit[i]);
		}
		else
		{
			printf("%d!", digit[i]);
		}
	}

	printf("=%d\n", sum);

	if (num == sum)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}
