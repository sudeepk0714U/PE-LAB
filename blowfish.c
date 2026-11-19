#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main()
{
    BF_KEY key;
    unsigned char password[100];
    unsigned char text[8] = "HELLO";
    unsigned char encrypted[8], decrypted[8];

    printf("Enter key: ");
    scanf("%99s", password);

    BF_set_key(&key, strlen((char *)password), password);

    BF_ecb_encrypt(text, encrypted, &key, BF_ENCRYPT);
    BF_ecb_encrypt(encrypted, decrypted, &key, BF_DECRYPT);

    printf("Encrypted text: ");
    for(int i = 0; i < 8; i++)
        printf("%02X", encrypted[i]);

    printf("\nDecrypted text: ");
    for(int i = 0; i < 8; i++)
        printf("%c", decrypted[i]);

    return 0;
}
