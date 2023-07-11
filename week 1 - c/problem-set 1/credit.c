#include <cs50.h>
#include <stdio.h>

string check_credit_card(long long number);
bool is_first_number(long long number, int min, int max);

int main(void)
{
    long long number = get_long("Number: ");

    string creditCardName = check_credit_card(number);
    printf("%s\n", creditCardName);
}

string check_credit_card(long long number)
{
    int sum = 0;
    int length = 0;
    int start;
    int start2;

    while (number > 0)
    {
        int mod1 = number % 10;
        number = number / 10;
        sum += mod1;
        length++;

        if (is_first_number(number, 0, 10))
        {
            start = number;
        }
        if (is_first_number(number, 10, 100))
        {
            start2 = number;
        }

        if (number > 0)
        {
            int mod2 = number % 10 * 2;
            number /= 10;
            length++;

            if (mod2 > 9)
            {
                sum += (mod2 % 10) + (mod2 / 10 % 10);
            }
            else
            {
                sum += mod2;
            }

            if (is_first_number(number, 0, 10))
            {
                start = number;
            }
            if (is_first_number(number, 10, 100))
            {
                start2 = number;
            }
        }
    }

    if (sum % 10 != 0)
    {
        return "INVALID";
    }

    if (length == 15 && (start2 == 34 || start2 == 37))
    {
        return "AMEX";
    }
    else if ((length == 13 || length == 16) && start == 4)
    {
        return "VISA";
    }
    else if (length == 16 && (start == 5 && start2 >= 51 && start2 <= 55))
    {
        return "MASTERCARD";
    }
    else
    {
        return "INVALID";
    }
}

bool is_first_number(long long number, int min, int max)
{
    if (min < number && number < max)
    {
        return true;
    }
    return false;
}