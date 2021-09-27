#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// write a program called substitution that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.
// A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    for (int i = 0; i < strlen(key); i++)
    {
        //The isalpha function checks that the character is an alphabet or not
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain the alphabet");
            return 1;
        }
    }

    // checks if there are any repeated characters
    int k, j;
    //This for loop checks that there are no repeating characters in the key.
    for (k = 0; k < strlen(key) - 1; k++)
    {
        for (j = k + 1; j < strlen(key); j++)
        {
            if (key[k] == key[j])
            {
                // If two characters are the same it is bound to be incorrect
                printf("Repeating characters");
                return 1;
            }
        }
    }
    string text = get_string("plaintext:");
    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if (isupper(letter) > 0)
        {
            text[i] = toupper(key[letter - 65]);
        }
        else if (islower(letter) > 0)
        {
            text[i] = tolower(key[toupper(letter) - 65]);
        }
    }
    printf("ciphertext: %s\n", text);
}
