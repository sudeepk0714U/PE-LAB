#include <stdio.h>

long long power(int a, int b, int n)
{
    long long result = 1;

    for(int i = 0; i < b; i++)
        result = (result * a) % n;

    return result;
}

int main()
{
    int p, q, n, phi, e, d, msg;
    long long encrypted, decrypted;

    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter public key e: ");
    scanf("%d", &e);

    d = 1;

    while((d * e) % phi != 1)
        d++;

    printf("Enter message (number): ");
    scanf("%d", &msg);

    if(msg < 0 || msg >= n)
    {
        printf("Message must be between 0 and n-1");
        return 0;
    }

    encrypted = power(msg, e, n);
    decrypted = power(encrypted, d, n);

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    printf("Encrypted message: %lld\n", encrypted);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}
