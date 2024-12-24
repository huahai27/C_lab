#include <stdio.h>
#include <string.h>

int main(void)
{
    char sen[100] = {'\0'};
    scanf("%s", sen);

    int len = strlen(sen);
    int flag = 0;

    for (int i = 0; i < len / 2 + 1; i++)
    {
        if (sen[i] != sen[len - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}