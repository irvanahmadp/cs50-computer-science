#include <cs50.h>
#include <stdio.h>

int get_height(void);
void create_pyramids(int height);

int main(void)
{
    int height = get_height();

    create_pyramids(height);
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void create_pyramids(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = height; j > 0; j--)
        {
            if (j <= i + 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");

            }
        }
        printf("\n");
    }
}