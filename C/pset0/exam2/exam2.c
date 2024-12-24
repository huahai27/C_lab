#include <stdio.h>

int main(void)
{
	double x = 0;
	int n = 0;
	double sum1 = 1;
	double sum2 = 1;
	double sum3 = 0;
	double sum = 0;
	scanf("%lf %d", &x, &n);

	for (int i = 1; i <= n; i++)
	{
		int tmp = 2 * i - 1;
		sum1 = 1;
		sum2 = 1;

		for (int j = 1; j <= tmp; j++)
		{
			sum1 *= x;
			sum2 *= j;
		}

		sum3 = sum1 / sum2;

		if (i % 2 == 0)
		{
			sum3 = -sum3;
		}

		sum += sum3;
	}

	printf("%.8lf\n", sum);

	return 0;
}
