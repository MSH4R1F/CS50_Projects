#include <stdio.h>
#include <cs50.h>
// Luhn’s Algorithm
// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
// Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
// function to add every digit together
long add_digits(total, add_to)
{
    while (add_to >= 1)
    {
        total = total + (add_to % 10);
        add_to /= 10;
    }
    return total;
}
// function to return the first two digits of a number
long first_two_digits(long num)
{
    while (num >= 100)
    {
        num = num / 10;
    }
    return num;
}
int main(void)
{
    // Have to be of long type as int is too short
    long number, num1, num2;
    int sum1, sum2;
    number = get_long("Number: ");
    // First check if the number is above 13 digits and below 17 digits
    if (!(number >= 1000000000000 && number < 9999999999999999))
    {
        printf("INVALID\n");
        return 0;
    }
    num1 = number;
    num2 = number * 10;
    sum1 = sum2 = 0;
    // first while loops deletes the last number and mods the last resulting digit to get every other digirt
    while (num1 >= 1)
    {
        num1 = num1 / 10;
        sum1 = add_digits(sum1, num1 % 10 * 2);
        num1 = num1 / 10;
        num2 = num2 / 10;
        sum2 = add_digits(sum2, num2 % 10);
        num2 = num2 / 10;
    }
    
    
    if ((sum1 + sum2) % 10 == 0)
    {
        // Assigns digit the first two numbers of the number
        int digit = first_two_digits(number);
        // These check if the numbers start with the digits that correspond to the bank type
        if (digit / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (digit > 50 && digit < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (digit == 37 || digit == 34)
        {
            printf("AMEX\n");
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
    // It returns invalid if its an invalid credit card number
}
