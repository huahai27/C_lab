#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int i);

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    
    int tmp = num;

    for (int i = 2; i < num; i++)
    {
        if (isPrime(i))
        {
            int cnt = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                cnt++;
            }
            if (cnt == 1)
            {
                printf("%d ", i);
            }
        }
        else
        {
            continue;
        }
    }

    return 0;
}

bool isPrime(int i)
{
    int tmp = (int)sqrt(i) + 1;
    for (int j = 2; j < tmp; j++)
    {
        if (i % j == 0)
        {
            return false;
        }
    }
    return true;
}