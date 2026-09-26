#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        int spaces = n - i - 1;    // number of spaces
        int bricks = i + 1;        // number of bricks
        print_row(spaces, bricks); // 🧱 Call the function to print the row
        printf("\n");
    }
}

void print_row(int spaces, int bricks)
{
    // Print spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Print bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}
