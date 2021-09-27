#include <stdio.h>
// Gets the library standard input output header
#include <cs50.h>
// Gets the cs50 header
#include <string.h>
// Gets the string manipulation header
#include <ctype.h>
// Gets the ctype header used for length of string
#include <math.h>
// Gets the math header used for rounding
int count_words(string input_text);
//This function will count the words
int count_sentences(string input_text);
// This will count the sentences

int grade_checker(int index); 
//This will check the grades 1 to 16
int main(void)
{   
    int letters = 0;
    // Grab input from user
    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) > 0)
            // Checks if the text[i] is in the alphabet or not
        {
            letters ++;
            // If the result is more than 0 it means it is in the alphabet so letters increment
        }
    }
    //printf("%d letter(s)\n", letters );
    //printf("%d word(s)\n", count_words(text));
    float words = count_words(text);
    //printf("%i sentence(s)\n", count_sentences(text));
    float sentences = count_sentences(text);
    float average_letters = ((100 / words) * letters) * 0.0588;
    float average_sentences = ((100 / words) * sentences) * 0.296;
    int index = round(average_letters - average_sentences - 15.8);
    grade_checker(index);
}


int count_words(string input_text)
{
    float words = 1;
    for (int i = 0; i < strlen(input_text); i++)
    {
        if (isspace(input_text[i]) > 0)
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string input_text)
{
    float sentences = 0;
    for (int i = 0; i < strlen(input_text); i++)
    {
        if ((input_text[i] == '.') || (input_text[i] == '?') || (input_text[i] == '!'))
        {
            sentences ++;
        }
    }
    return sentences;
}

int grade_checker(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index == 1)
    {
        printf("Grade 1\n");
    }
    else if (index == 2)
    {
        printf("Grade 2\n");
    }
    else if (index == 3)
    {
        printf("Grade 3\n");
    }
    else if (index == 4)
    {
        printf("Grade 4\n");
    }
    else if (index == 5)
    {
        printf("Grade 5\n");
    }
    else if (index == 6)
    {
        printf("Grade 6\n");
    }
    else if (index == 7)
    {
        printf("Grade 7\n");
    }
    else if (index == 8)
    {
        printf("Grade 8\n");
    }
    else if (index == 9)
    {
        printf("Grade 9\n");
    }
    else if (index == 10)
    {
        printf("Grade 10\n");
    }
    else if (index == 11)
    {
        printf("Grade 11\n");
    }
    else if (index == 12)
    {
        printf("Grade 12\n");
    }
    else if (index == 13)
    {
        printf("Grade 13\n");
    }
    else if (index == 14)
    {
        printf("Grade 14\n");
    }
    else if (index == 15)
    {
        printf("Grade 15\n");
    }
    else if (index == 16)
    {
        printf("Grade 16\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    return 0;
}
