#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int m[n+1][n+1];
    int abs_min = 20000;
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &m[i][0]);
        m[0][i] = m[i][0];
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            m[i][j] = abs(m[i][0] - m[0][j]);
            if (m[i][j] < abs_min)
            {
                abs_min = m[i][j];
            }
        }
    }

    printf("%d", abs_min);

    return 0;
}