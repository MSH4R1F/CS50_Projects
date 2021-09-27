#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start Size:  ");
    }
    while (start < 9) ;
    int end;
    do
    {
        end = get_int("End Size:  ");
    }
    while (end < start);
    int steps = 0;
    while (start < end)
    {
        start = start - (start / 4) + (start / 3);
        steps++;
    }
    
    // TODO: Prompt for end size
    // TODO: Calculate number of years until we reach threshold
    // TODO: Print number of years
    printf("Years: %d", steps);
}
