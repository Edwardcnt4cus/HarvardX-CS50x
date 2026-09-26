#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false;
        }

        seen[index] = true;
    }
    return true;
}

char substitute(char c, string key)
{
    if (isalpha(c))
    {
        bool is_upper = isupper(c);
        int index = toupper(c) - 'A';
        char substituted = key[index];
        return is_upper ? toupper(substituted) : tolower(substituted);
    }
    return c;
}
