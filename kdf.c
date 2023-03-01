#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "crypto.c"

int main(int argc, char *argv[])
{
    long desired_len = 32;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
        {
            if (argc > i + 1)
            {
                desired_len = atol(argv[i + 1]);
            }
            else
            {
                puts("Specify key output length.");
                return 0;
            }
        }
        else if (strcmp(argv[i], "-h") == 0  || strcmp(argv[i], "--help") == 0) {
            puts("Send key input to stdin.\nUse -l option to specify output length.\nExample: echo -n 1234 | ./kdf -l 64 | base16\n");
            return 0;
        }
    }
    size_t cap = 4096;
    size_t len = 0;
    char *buffer = malloc(cap * sizeof(char));
    int c;
    FILE *file = freopen(NULL, "rb", stdin);
    while ((c = fgetc(file)) != EOF)
    {
        buffer[len] = c;
        if (++len == cap)
        {
            buffer = realloc(buffer, (cap *= 2) * sizeof(char));
        }
    }
    buffer = realloc(buffer, (len) * sizeof(char));
    fclose(file);
    char *key_new = derive_key(buffer, len, desired_len);
    write(1, key_new, desired_len);
    free(key_new);
    free(buffer);
    return 0;
}