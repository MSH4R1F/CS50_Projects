#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //First getting input of the height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    // The conditions
    while (height < 1 || height > 8);
    //Rows 
    for (int width = 1; width <= height; width++)
    {
        // Blanks
        for (int blanks = height - width; blanks > 0; blanks --)
        {
            printf(" ");
        }
        // Hashes
        for (int hashes = 1; hashes <= width; hashes ++)
        {
            printf("#");
        }
        printf("  ");
        for (int hashes1 = 1; hashes1 <= width; hashes1 ++)
        {
            printf("#");
        }
        printf("\n");
    }
}
