# include <stdio.h>

int main(void)
{
    int cnt1 = 0;
    scanf("%d", &cnt1);

    int tmp[102] = {0};
    for (int i = 0; i < cnt1; i++)
    {
        scanf("%d", &tmp[i]);
    }

    int a[51] = {0};

    for (int i = 0; i < cnt1 - 1; i += 2)
    {
        a[tmp[i + 1]] += tmp[i];
    }

    for (int i = 0; i < 102; i++)
    {
        tmp[i] = 0;
    }

    int cnt2 = 0;
    scanf("%d", &cnt2);

    for (int i = 0; i < cnt2; i++)
    {
        scanf("%d", &tmp[i]);
    }

    for (int i = 0; i < cnt2 - 1; i += 2)
    {
        a[tmp[i + 1]] += tmp[i];
    }

    for (int i = 50; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            printf("%d %d ", a[i], i);
        }
    }

    printf("\n");

    return 0;
}