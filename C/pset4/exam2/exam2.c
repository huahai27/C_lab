#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void to_lower(char* str);

int main(void)
{
    char target[21] = {0};
    char replace[21] = {0};
    char sen[201] = {0};
    int index[201] = {0}, idx = 0;

    scanf("%s", target);
    scanf("%s", replace);
    getchar();
    fgets(sen, 201, stdin);

    char tar_lower[21], sen_lower[201];
    strcpy(tar_lower, target);
    strcpy(sen_lower, sen);

    int len_tar = strlen(target);
    int len_re = strlen(replace);
    int len_sen = strlen(sen);

    to_lower(tar_lower);
    to_lower(sen_lower);

    for (int i = 0; i <= len_sen - len_tar; i++) 
    {
        if (strncmp(sen_lower + i, tar_lower, len_tar) == 0) 
        {
            index[idx] = i;
            idx++;
        }
    }

    int len_op = len_sen - len_tar * idx + len_re * idx;

    char* output = malloc(len_op + 1);

    int idx_op = 0;
    int idx_sen = 0;
    int cnt_re = 0;

    while (idx_sen < len_sen)
    {
        if (cnt_re < idx && idx_sen == index[cnt_re])
        {
            strcpy(output + idx_op, replace);
            idx_op += len_re;
            idx_sen += len_tar;
            cnt_re++;
        }
        else
        {
            output[idx_op++] = sen[idx_sen++];
        }
    }

    output[idx_op] = '\0';
    printf("%s\n", output);

    free(output);

    return 0;
}

void to_lower(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}