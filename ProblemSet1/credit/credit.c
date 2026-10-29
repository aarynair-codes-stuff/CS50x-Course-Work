#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_card_num(void)
{
    // Takes credit card number as input from user
    long card_num;
    do
    {
        card_num = get_long("Number: ");
    }
    while (card_num <= 0); // Re-prompts if 0 or negative
    return card_num;
}

int get_length(long card_num)
{
    // Calculates the length of the credit card num using log basse 10
    int length = floor(log10(card_num)) + 1;
    return length;
}

int get_checksum(long card_num, int length)
{
    // Converts card num from long to string
    char str_card_num[64];
    int sum_from_second = 0;
    int sum_from_end = 0;
    int checksum = 0;

    // Convert card number to string
    sprintf(str_card_num, "%ld", card_num);

    for (int i = length - 2; i >= 0; i -= 2)
    {
        char digit_char = str_card_num[i];

        // Subtracting '0' gets the true numerical value
        int actual_num = digit_char - '0';

        int doubled_num = 2 * actual_num;

        if (doubled_num > 9)
        {
            doubled_num -= 9;
        }

        sum_from_second = sum_from_second + doubled_num;
    }

    for (int i = length - 1; i >= 0; i -= 2)
    {
        char digit_char = str_card_num[i];

        // Subtracting '0' gets the true numerical value
        int actual_num = digit_char - '0';

        sum_from_end = sum_from_end + actual_num;
    }

    // Returns checksum from Luhn’s Algorithm
    checksum = sum_from_second + sum_from_end;
    return checksum;
}

int get_first_digits(long card_num, int length)
{
    // Retrieves the first digits for identification
    int initial_digits = card_num / pow(10, (length - 2));
    if (initial_digits / 10 == 4)
    {
        return (initial_digits / 10);
    }
    else
    {
        return initial_digits;
    }
}

void get_valid(int length, int checksum, int first_digits)
{
    // Checks if valid length
    if (length > 16 || (length < 15 && length != 13))
    {
        printf("INVALID\n");
    }
    else
    {
        // Checks if valid checksum
        if (checksum % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            // Checks if valid combination of length and first digits
            if (first_digits == 4 && (length == 13 || length == 16))
            {
                printf("VISA\n");
            }
            else if (length == 15 && (first_digits == 34 || first_digits == 37))
            {
                printf("AMEX\n");
            }
            else if (length == 16 &&
                     (first_digits == 51 || first_digits == 52 || first_digits == 53 ||
                      first_digits == 54 || first_digits == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}

int main(void)
{
    // Declares all variables by calling respective functions
    long card_num = get_card_num();
    int length = get_length(card_num);
    int checksum = get_checksum(card_num, length);
    int first_digits = get_first_digits(card_num, length);

    // Checks if variables are valid
    get_valid(length, checksum, first_digits);
}
