#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:  ");
    }
    while (height < 1 || height > 8);
    // First for loop iterates over how much lines there are
    for (int i = 0; i < height; i++)
    {
        // Iterates for the left hand side of the pyramid, the blanks spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Adds the hashes for the left hand side of the pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        // Adds the hashes for the right hand side of the pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}
