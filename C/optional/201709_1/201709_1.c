#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int tens = n / 10;
    int fifs = 0;
    int thirs = 0;

    if (tens / 5 > 0)
    {
        fifs = tens / 5;
        tens %= 5;
    }

    if (tens / 3 > 0)
    {
        thirs = tens / 3;
        tens %= 3;
    }

    printf("%d", fifs * 7 + thirs * 4 + tens);

    return 0;
}