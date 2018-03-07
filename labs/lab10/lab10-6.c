#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN   20

char *words[99];
int num_words = 0;
int read_line();
int cmpfunc(const void *a, const void *b);

int main(void)
{
    int i;

    putchar('\n');
    for (i = 0; ; i++)
    {
        printf("Enter a word: ");
        if (read_line() == 0)
            break;
    }

    qsort(words, num_words, sizeof(char *), cmpfunc);

    printf("In sorted order: ");
    for (i = 0; i < num_words; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}

int read_line(char str[], int n)
{
    words[num_words] = malloc(MAX_LEN + 1);
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            words[num_words][i++] = ch;
        else if (ch == ' ')
            break;
    words[num_words][i] = '\0';
    num_words++;
    return i;
}

int cmpfunc(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
