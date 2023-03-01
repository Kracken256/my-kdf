#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// This is the magic
char *derive_key(char *key_seed, long key_len, long desired_len)
{
    char *buffer = calloc(desired_len, sizeof(char));
    if (buffer == NULL)
    {
        puts("Malloc Error.\n");
        return NULL;
    }
    if (key_len < 5)
    {
        return NULL;
    }
    // Define initial state
    uint64_t state = key_seed[0] * desired_len * key_len;
    // Absord key into initial state.
    for (long i = 0; i < key_len; i++)
    {
        state *= key_seed[i];
    }
    // Expand state into n bytes.
    for (long i = 0; i < desired_len; i++)
    {
        state ^= key_seed[i % key_len] * key_seed[(uint64_t)(i ^ state) % key_len] ^ desired_len * i;
        buffer[i] = (char)(state % 256);
    }
    return buffer;
}

// One time pad
char *cipher_encrypt(char *plaintext, int len, int *out_len, char *key, int key_len)
{
    if (key_len == 0)
    {
        return NULL;
    }
    char *ciphertext = malloc(len * sizeof(char));
    char *key_buf = derive_key(key, key_len, len);
    if (key_buf == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key_buf[i];
    }
    *out_len = len;
    free(key_buf);
    return ciphertext;
}

// Encryption and decryption are the same. XOR.
char *cipher_decrypt(char *ciphertext, int len, int *out_len, char *key, int key_len)
{
    return cipher_encrypt(ciphertext, len, out_len, key, key_len);
}