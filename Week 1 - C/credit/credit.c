#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool luhn_algorithm(long number);
string get_card_type(long number);

int main(void)
{
    long number = get_long("Number: ");

    if (luhn_algorithm(number))
    {
        printf("%s\n", get_card_type(number));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_algorithm(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10) == 0;
}

string get_card_type(long number)
{
    int length = 0;
    long start = number;

    while (start > 0)
    {
        start /= 10;
        length++;
    }

    long first_two_digits = number;
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }

    if ((first_two_digits == 34 || first_two_digits == 37) && (length == 15))
    {
        return "AMEX";
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && length == 16)
    {
        return "MASTERCARD";
    }
    else if ((first_two_digits / 10 == 4) && (length == 13 || length == 16))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
