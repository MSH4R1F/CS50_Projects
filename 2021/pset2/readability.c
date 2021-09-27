#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
// Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
// If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".?
//index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
int main(void)
{
    // Input text from user
    string text = get_string("Text:  ");
    float letters, sentences, words;
    letters = sentences = words = 0;
    // loop through text and increment words letters and sentences
    for (int i = 0; i < strlen(text); i++)
    {
        char curr = text[i];
        if (isalpha(curr) != 0)
        {
            letters ++;
        }
        else if (isspace(curr) != 0)
        {
            words ++;
        }
        else if (curr == '.' || curr == '?' || curr == '!')
        {
            sentences++;
        }
    }
    if (words == 0)
    {
        words++;
        sentences++;
    }
    else
    {
        words++;
    }
    float L = letters / words * 100;
    float S = sentences / words * 100;
    // Use the formula to calculate the grade index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}
