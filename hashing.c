#include <stdio.h>

int main()
{
    char str[100];
    unsigned long hash = 5381;
    int i;

    printf("Enter a string: ");
    scanf("%99s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        hash = hash * 33 + str[i];
    }

    printf("Hash value: %lu\n", hash);

    return 0;
}
