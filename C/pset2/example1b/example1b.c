#include <stdio.h>

int main(void)
{
    int n = 0;
    int m = 0;
    int a[11][11] = {0};

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int max = a[i][j];
            int flag = 0;

            for (int p = 1; p <= m; p++)
            {
                if (a[i][p] > max)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                for (int q = 1; q <= n; q++)
                {
                    if (a[q][j] > max)
                    {
                        flag = 1;
                        break;
                    }   
                }
            }
           
            if (flag == 0)
            {
                printf("%d %d %d\n", a[i][j], i, j);

            }

        }
    }

    return 0;
}
