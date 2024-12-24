#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void format(char* line, int idx_colon, FILE* fout);
void clean_sp(char* str);

int main(void)
{
    int idx_colon;
    FILE *fin, *fout;

    scanf("%d", &idx_colon);

    fin = fopen("listin.txt", "r");
    fout = fopen("listout.txt", "w");

    char line[101];

    while (fgets(line, sizeof(line), fin))
    {
        line[strcspn(line, "\n")] = '\0';
        format(line, idx_colon, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

void format(char* line, int idx_colon, FILE* fout)
{
    char left[101] = {'0'};
    char right[101] = {'0'};
    char* ptr_colon = strchr(line, ':');

    strncpy(left, line, ptr_colon - line);
    left[ptr_colon - line] = '\0';
    strcpy(right, ptr_colon + 1);

    clean_sp(left);
    clean_sp(right);

    int len_l = strlen(left);
    int num_sp = idx_colon - len_l - 1; // Leave a colon and a space

    fprintf(fout, "%s%*s: %s\n", left, num_sp, "", right);
}

void clean_sp(char* str)
{
    char tmp[101];
    // i records the read position, j records the write position
    int i = 0, j = 0;

    // Skip leading spaces
    while (isspace(str[i]))
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (!isspace(str[i]))
        {
            tmp[j++] = str[i++];
        }
        else // If there are spaces or even multiple spaces
        {
            tmp[j++] = ' ';
            // Skip any remaining extra spaces
            while (isspace(str[i]))
            {
                i++;
            }
        }
    }

    tmp[j] = '\0';

    strcpy(str, tmp);
}