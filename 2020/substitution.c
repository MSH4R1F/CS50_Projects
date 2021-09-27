#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //First declare the plaintext, ciphertext and the keys as variables
    string text, plain_text, cipher_text;
    if (argc < 2)
        //Argc is the amount of arguments the command line has. It should be 2
        //Only one argument means there is no key
    {
        printf("Usage: ./substitution key\n");
        return 1;
        
    }
    //Additional arguments mean there is more arguments
    else if (argc > 2) 
    {
        printf("More than one argument.\n");
        return 1;
    }
    else if (argc == 2)
    {
        text = argv[1];
        if (strlen(text) != 26)
        {
            //This checks if the text is not 26 characters. Incidentally the same number of characters as the alphabet does
            printf("Key must contain 26 characters.");
            return 1;
        }
        else
        {
            for (int i = 0; i < strlen(text); i++)
            {
                //The isalpha function checks that the character is an alphabet or not
                if (isalpha(text[i]) == 0)
                {
                    printf("Key must only contain the alphabet");
                    return 1;
                }
            }
            int i, j;
            //This for loop checks that there are no repeating characters in the key.
            for (i = 0; i < strlen(text); i++)
            {
                for (j = i + 1; j < strlen(text); j++)
                {
                    if (text[i] == text[j])
                    {
                        // If two characters are the same it is bound to be incorrect
                        printf("Repeating characters");
                        return 1;
                    }
                }
            }
            
        }
    
    }
    // Length will store the length of the key
    // Plain text will store the plain_text
    plain_text = get_string("plaintext: ");
    //This will store length of plain text
    int length = strlen(plain_text);

    int plain_text_length = strlen(plain_text);
    char ciphertext[length];
    //Initalize the cipher text variable
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = argv[1];
    //argv[1] is equal to the key
    int i = 0;
   
    for (i = 0; i < plain_text_length; i++)
    {
        if (plain_text[i] == '\0')
        {
            break;
        }
        if (isupper(plain_text[i]) > 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == tolower(plain_text[i]))
                {
                    
                    ciphertext[i] = toupper(key[j]);
                    break;
                }
            }
        }
        else if (islower(plain_text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == plain_text[i])
                {
                    ciphertext[i] = tolower(key[j]);
                    break;
                }
            }
        }
        else
        {
            ciphertext[i] = plain_text[i];
        }
    
    }
    ciphertext[i] = '\0';
    
       
    printf("ciphertext: %s\n", ciphertext);
    return 0;
    
    
    
}
