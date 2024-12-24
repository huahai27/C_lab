#include <stdio.h>

int main(void)
{
    int layers = 0;
    int tri[13][13] = {{1},};
    scanf("%d", &layers);
    layers++;

    for (int i = 1; i < layers; i++)
    {
        tri[i][0] = 1;
        tri[0][i] = 1;
    }

    for (int i = 1; i < layers; i++)
    {
        for (int j = 1; j < layers; j++)
        {
            tri[i][j] = tri[i-1][j] + tri[i][j-1];
        }
    }

    for (int i = 0; i < layers; i++)
    {
        int cnt_sp = (layers - 1) * 2 - i * 2;
        for (int j = 0; j < cnt_sp; j++)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("%4d", tri[i - k][k]);
        }

        printf("\n");
    }

    return 0;
}