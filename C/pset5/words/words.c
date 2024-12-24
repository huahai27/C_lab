#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char letter[25];
    struct node *next;
}node;

typedef struct {
    node* lists[26];
}dict;

void format(char* str);
void initdict(dict* Dict);
void insert(dict* Dict, char* word);
void splitwords(dict* Dict, char* word);
void free_list(node* head);
void free_dict(dict* Dict);

int main(void)
{
    FILE *fin, *fout;
    dict* Dict = (dict*) malloc(sizeof(dict));
    char buffer[42];
    // printf("Dictionary initialized\n");

    initdict(Dict);

    fin = fopen("in.txt", "r");
    // fin = fopen("D:\\code\\C\\pset5\\in.txt", "r");
    // fin = fopen("/mnt/d/code/C/pset5/in.txt", "r");
    if (!fin)
    {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    fout = fopen("words.txt", "w");
    // fout = fopen("D:\\code\\C\\pset5\\words.txt", "w");
    // fout = fopen("/mnt/d/code/C/pset5/words.txt", "w");
    if (!fout)
    {
        perror("Error opening output file");
        fclose(fin);
        return EXIT_FAILURE;
    }

    // Write word by word, but punctuation will be written, remember to clear
    while (fscanf(fin, "%20s", buffer) == 1)
    {
        // Convert all words to lowercase and remove punctuation. If there are numbers, remove them directly.
        format(buffer);

        // Detect hyphens and check if it is a word
        int flag = 1; // Check if there is a hyphen.
        for (int i = 0, len = strlen(buffer); i < len; i++)
        {
            // Check if the buffer is empty
            if (strlen(buffer) == 0)
            {
                continue;
            }
            // Hyphen detected
            if (buffer[i] == '-')
            {
                splitwords(Dict, buffer);
                flag = 0;
                break;
            }
        }

        // Insert word without hyphen
        if (flag == 1)
        {
            insert(Dict, buffer);
        }
    }

    // Traverse 26 letters
    for (int i = 0; i < 26; i++)
    {
        // Traverse the linked list of the letter
        for (node* ptr = Dict->lists[i]; ptr != NULL; ptr = ptr->next)
        {
            fprintf(fout, "%s\n", ptr->letter);
        }
    }

    fclose(fin);
    fclose(fout);

    free_dict(Dict);
    free(Dict);

    return EXIT_SUCCESS;
}

void initdict(dict* Dict)
{
    for (int i = 0; i < 26; i++)
    {
        Dict->lists[i] = NULL;
    }
}

void format(char* str)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        // Update the string to keep only letters and hyphens
        if (isalpha(str[i]) || str[i] == '-')
        {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

void insert(dict* Dict, char* word)
{
     // Insert the index of the linked list
    int index = word[0] - 'a';
    node *n = (node*) malloc(sizeof(node));

    if (n == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    strcpy(n->letter, word);
    if (strlen(word) == 0)
    {
        return;
    }
    // printf("Inserted word: %s\n", n->letter);
    n->next = NULL;

    // The linked list is empty
    if (Dict->lists[index] == NULL)
    {
        Dict->lists[index] = n;
        return;
    }

    // The word belongs to the beginning of the linked list
    else if(strcmp(n->letter, Dict->lists[index]->letter) < 0)
    {
        n->next = Dict->lists[index];
        Dict->lists[index] = n;
        return;
    }

    // The word is the same as the beginning of the linked list
    else if(strcmp(n->letter, Dict->lists[index]->letter) == 0)
    {
        // printf("----Duplicated word: %s\n", n->letter);
        free(n);
        return;
    }

    // It belongs to the middle of the linked list. 
    // It has been compared with the beginning, so start from the second one.
    for (node* ptr = Dict->lists[index]; ptr != NULL; ptr = ptr->next)
    {
        // If it points to the last
        if (ptr->next == NULL)
        {
            // Bigger than the last one
            if (strcmp(n->letter, ptr->letter) > 0)
            {
                ptr->next = n;
                return;
            }
            // Equal to the last one, no small case
            else
            {
                free(n);
                return;
            }
        }

        // Excluding all other situations, now we are in the middle
        if (strcmp(n->letter, ptr->next->letter) < 0)
        {
            n->next = ptr->next;
            ptr->next = n;
            return;
        }
    }
}

void splitwords(dict* Dict, char* word)
{
    char *token = strtok(word, "-");
    while (token != NULL)
    {
        insert(Dict, token);
        token = strtok(NULL, "-"); // Continue splitting the remaining words after the last split
    }
}

void free_list(node* head)
{
    node* current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void free_dict(dict* Dict)
{
    for (int i = 0; i < 26; i++) {
        free_list(Dict->lists[i]);
    }
}
