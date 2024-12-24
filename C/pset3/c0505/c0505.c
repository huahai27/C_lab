#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[51];
    char t[51];
    char ss[51] = {'\0'};
    char ss_max[51] = {'\0'};
    int len_max = 0;
    int len_cnt = 0;
    int len_s = 0, len_t = 0;

    scanf("%s", s);
    scanf("%s", t);

    len_s = strlen(s);
    len_t = strlen(t);

    for (int i = 0; i < len_s; i++)
    {
        for (int j = 0; j < len_t; j++)
        {
            if (s[i] == t[j])
            {
                len_cnt = 0;
                int tmp_i = i, tmp_j = j;
                while (s[tmp_i] == t[tmp_j] && tmp_i < len_s && tmp_j < len_t)
                {
                    ss[len_cnt] = s[tmp_i];
                    len_cnt++;
                    tmp_i++;
                    tmp_j++;
                }

                if (len_cnt > len_max)
                {
                    len_max = len_cnt;
                    
                    for (int k = 0; k < len_max; k++)
                    {
                        ss_max[k] = ss[k];
                    }
                }
                
            }
        }
    }

    if (len_max != 0)
    {
        printf("%s\n", ss_max);
    }
    else
    {
        printf("No Answer\n");
    }

    return 0;
}