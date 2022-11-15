#include "crypto.c"
#include <stdio.h>
#include <unistd.h>

int main()
{
    char plaintext[] = "Hello world....................111111111111111111111111111111111111111";
    char key[] = "1Jedimaster";
    char *ciphertext;
    uint outlen = 0;
    printf("-3\n");
    cipher_encrypt(plaintext, sizeof(plaintext), ciphertext, &outlen, key, sizeof(key));
    for (int i = 0; i < outlen; i++)
    {
        putc(ciphertext[i], stdout);
    }
    return 0;
}