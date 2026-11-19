#include <stdio.h>

long long power(int a, int b, int p)
{
    long long result = 1;

    for(int i = 0; i < b; i++)
        result = (result * a) % p;

    return result;
}

int main()
{
    int p, g, a, b;
    long long x, y, key1, key2;

    printf("Enter prime number: ");
    scanf("%d", &p);

    printf("Enter primitive root: ");
    scanf("%d", &g);

    printf("Enter Alice private key: ");
    scanf("%d", &a);

    printf("Enter Bob private key: ");
    scanf("%d", &b);

    x = power(g, a, p);
    y = power(g, b, p);

    key1 = power(y, a, p);
    key2 = power(x, b, p);

    printf("Alice public key: %lld\n", x);
    printf("Bob public key: %lld\n", y);

    printf("Alice shared key: %lld\n", key1);
    printf("Bob shared key: %lld\n", key2);

    return 0;
}
