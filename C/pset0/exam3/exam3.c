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
		sum1 = 1;
		sum2 = 1;

		for (int j = 1; j <= i; j++)
		{
			sum1 *= x;
			sum2 *= j;
		}

		sum3 = sum1 / sum2;

		sum += sum3;
	}

	printf("%.6lf\n", sum + 1);

	return 0;
}
