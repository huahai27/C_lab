#include <stdio.h>
#include <math.h>

int main(void)
{
	double e = 0;
	double num = 1.0;
	double diff = 0;
	double diff_min = 2;
	int n = 1;
	double num_close = 0;
	scanf("%lf", &e);

	while (1)
	{
		double i = 2.0 * n;
		double a = i / (i - 1);
		double b = i / (i + 1);
		num *= a * b;
		diff = fabs(e - num * 2);
		if (diff < diff_min)
		{
			diff_min = diff;
			num_close = num * 2;
		}
		if (diff > diff_min )
		{
			printf("%.9lf %d", num_close, n - 1);
			break;
		}
		n++;
	}

	return 0;
}
