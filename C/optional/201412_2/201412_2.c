#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int cnt = n * n;
    int m[n][n];
    int a[cnt];
    int idx = 0;
    int k = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j <= i; j++)
            {
                a[idx] = m[i-j][j];
                a[cnt-1-idx] = m[j+k][i-j+k];
                idx++;
            }
        }
        else
        {
            for(int j = 0; j <= i; j++)
            {
                a[idx] = m[j][i-j];
                a[cnt-1-idx] = m[i-j+k][j+k];
                idx++;
            }
        }
        k--;
    }

    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}