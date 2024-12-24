#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int m[n+1][n+1];
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &m[i][0]);
        m[0][i] = m[i][0];
    }

    for (int i = 1; i < n + 1; i++)
    {
        int sum = 0;
        for (int j = 1; j < n + 1; j++)
        {
            if (m[i][0] > m[0][j])
            {
                m[i][j] = 1;
            }

            else if (m[i][0] < m[0][j])
            {
                m[i][j] = -1;
            }

            else
            {
                m[i][j] = 0;
            }

            sum += m[i][j];
        }

        if (sum == 0)
        {
            printf("%d\n", m[i][0]);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}