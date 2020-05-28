#include <stdio.h>
#include <cs50.h>

/** 
 * My own example from Paypal:
 *  371449635398431
 *   - - - - - - - 
 * 7*2 + 4*2 + 9*2 + 3*2 + 3*2 + 8*2 + 3*2 = 47
 * 3 + 1 + 4 + 6 + 5 + 9 + 4 + 1 = 33
 * 47+33 = 80
 * 
 * 80 % 10 = 0
 * so this card is valid
 * 
 */
 
int main(void) 
{
    //First asks for your credit card number
    long long credit_card_number = get_long_long("Enter your credit card number:  ");
    //Declaring the variables
    int digit1 = 0, digit2 = 0, total = 0, number_of_digits = 0, sum_of_evens = 0, sum_of_every_other_number = 0;
    while (credit_card_number)
    {
        // Making Digit 2 equal to digit 1 means that every time it loops the previous digit would be equal to digit2. This is not really useful until the last pass where the second digit is equal to the actual second digit to use later in the program.
        digit2 = digit1;
        // Using the modulus operator we find the remainder. This will be equal to the last digit
        digit1 = credit_card_number % 10;
        if (number_of_digits % 2 == 0)
        {
            //This if statement is for the last original digit. This will continue in 2's until the number ends
            sum_of_evens += digit1;
        }
        else
        {
            //This is equal to the second last digit. We multiply this
            int digit1_doubled = digit1 * 2;
            // We need to add only the digits not the whole numbers, so we separate them using the modulus and integer division operators.
            int digit1_first_digit = digit1_doubled / 10;
            int digit1_second_digit = digit1_doubled % 10;
            sum_of_every_other_number += digit1_second_digit + digit1_first_digit;
            
        }
        // Now you get rid of the last digits for the next pass
        credit_card_number /= 10;
        // This will count the number of digits. Increments every time
        ++number_of_digits;
    }
    // printf("%i", sum_of_evens + sum_of_every_other_number);
    // Firsts finds the checksum to be valid
    if ((sum_of_evens + sum_of_every_other_number) % 10 == 0)
    {
        //If the digits start with 34 or 37 and the digits are equal to 15 it is an American Express Card
        if (((digit1 == 3 && digit2 ==  4) || (digit1 == 3 && digit2 ==  7)) && number_of_digits == 15)
        {
            printf("AMEX\n");
        }
        //If digits start with a 4 and the number of digits are 13 or 16 it is a VISA card
        else if (digit1 == 4 && (number_of_digits == 13 || number_of_digits == 16))
        {
            printf("VISA\n");
        }
        // If the digits are either 51,52,53,54 or 55 and the number of digits are equal to 16 it is a mastercard.
        else if (((digit1 == 5 && digit2 ==  1) || (digit1 == 5 && digit2 ==  2) || (digit1 == 5 && digit2 ==  3) || (digit1 == 5
                  && digit2 ==  4) || (digit1 == 5 && digit2 ==  5)) && number_of_digits == 16)
        {
            printf("MASTERCARD\n");
            
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
