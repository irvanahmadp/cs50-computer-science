#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int start_size);
int calculate_years(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_start_size();

    // TODO: Prompt for end size
    int end = get_end_size(start);

    // TODO: Calculate number of years until we reach threshold
    int years = calculate_years(start, end);

    // TODO: Print number of years
    printf("Years: %i", years);
}

int get_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

int get_end_size(int start)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < start);
    return n;
}

int calculate_years(int start, int end)
{
    int population = start;
    int years = 0;
    while (population < end)
    {
        population += (population / 3) - (population / 4);
        years++;
    }
    return years;
}