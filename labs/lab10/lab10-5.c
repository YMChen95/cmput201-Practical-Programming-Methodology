#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN   20

char *word[99];
int num_words = 0;

int read_line();

int main(void)
{
    int smallest, i, j;
    char *temp;

    putchar('\n');
    for (i = 0; ; i++)
    {
        printf("Enter a word: ");
        if (read_line() == 0)
            break;
    }

    for (i = 0; i < num_words; i++)
    {
        smallest = i;
        for (j = i+1; j < num_words; j++)
            if (strcmp(word[j], word[smallest]) < 0)
                smallest = j;
        temp = word[i];
        word[i] = word[smallest];
        word[smallest] = temp;
    }

    printf("In sorted order: ");
    for (i = 0; i < num_words; i++)
    {
        printf("%s%s", word[i], i == num_words ? "" : " ");
    }
    printf("\n\n");

    return 0;
}

int read_line(char str[], int n)
{
    word[num_words] = malloc(MAX_LEN + 1);
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            word[num_words][i++] = ch;
        else if (ch == ' ')
            break;
    word[num_words][i] = '\0';
    num_words++;
    return i;
}
