#include <stdio.h>

int main(void)
{
    int m = 0, n = 0, x = 0;
    scanf("%d %d", &m, &n);
    int a = m, b = n;

    while (m % n != 0)
    {
        x = m % n;
        m = n;
        n = x;
    }

    printf("%d %d", a / x, b / x);

    return 0;
}