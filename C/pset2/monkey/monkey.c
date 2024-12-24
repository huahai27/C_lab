#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n = 0; // n monkeys
	int q = 0; // start from q
	int m = 0; // count from 1 to m
	int cnt_out = 0; // Number of outs
	int cnt = 0; // Report counter
	int num_mnky = 0; // monkey counter

	scanf("%d %d %d", &n, &m, &q);
	num_mnky = q;
	bool out[n+1]; // Each monkey’s out status
	for (int i = 1; i < n+1; i++)
	{
		out[i] = false;
	}

	while (cnt_out != n - 1)
	{
		// If the count exceeds the n, restart from 1
		if (num_mnky > n)
		{
			num_mnky = 1;
		}

		// If it is the turn of a monkey that is already out, 
		// skip it and the count remains the same.
		if (out[num_mnky] == true)
		{
			num_mnky++;
			continue;
		}

		cnt++;
		// If the number reaches m, set its out status to true, 
		// reset the number to 0, and 
		// increase the monkey counter and out counter by 1
		if (cnt == m)
		{
			out[num_mnky] = true;
			cnt = 0;
			cnt_out++;
		}

		num_mnky++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (out[i] == false)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}