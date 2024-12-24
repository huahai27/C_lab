#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b);
void initialize(char* a);
void reverse(char* a, int len_a);

int main(void)
{
    char a[82] = {'0'}, b[82] = {'0'}, r[82] = {'0'};
    initialize(a);
    initialize(b);

    scanf("%s", a);
    getchar();
    scanf("%s", b);

    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_r = max(len_a, len_b);
    a[len_a] = '0';
    b[len_b] = '0';

    reverse(a, len_a);
    reverse(b, len_b);    

    int tens = 0;
    for (int i = 0; i < len_r + 1; i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + tens;
        r[i] = sum % 10 + '0';
        tens = sum / 10;
    }

    if (r[len_r] != '0')
    {
        len_r++;
    }
    else
    {
        while(r[len_r - 1] == '0')
        {
            len_r--;
        }
    }

    for (int i = len_r - 1; i >= 0; i--)
    {
        printf("%c", r[i]);
    }

    return 0;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void initialize(char* a)
{
    for (int i = 0; i < 82; i++)
    {
        a[i] = '0';
    }
}

void reverse(char* a, int len_a)
{
    char tmp = '0';
    for (int i = 0, len = len_a / 2; i < len; i++)
    {
        tmp = a[i];
        a[i] = a[len_a - 1 - i];
        a[len_a - 1 - i] = tmp;
                             
    }
}