#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], rail[10][100];
    int key, i, j, row = 0, dir = 1;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter number of rails: ");
    scanf("%d", &key);

    if(key < 2 || key > 10)
    {
        printf("Invalid key");
        return 0;
    }

    int len = strlen(text);

    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = '\0';

    for(i = 0; i < len; i++)
    {
        rail[row][i] = text[i];

        if(row == 0)
            dir = 1;
        else if(row == key - 1)
            dir = -1;

        row += dir;
    }

    printf("Encrypted text: ");

    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            if(rail[i][j] != '\0')
                printf("%c", rail[i][j]);

    return 0;
}
