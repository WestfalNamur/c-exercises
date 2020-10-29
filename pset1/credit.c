#include <stdio.h>
#include <cs50.h>

int find_length(long long n)
{
    // loop over digits until non is leftover. For each loop len++
    // retrun
    int len = 0;
    for (len = 0; n != 0; n /= 10, len++)
        ;
    return len;
}

bool checksum(long long cs)
{
    // create sum
    // Loop over checksum "cs"
    //   If index is odd, add last diget to sum
    //   else add sum += digit_x2 / 10 + digit_x2 % 10
    // Return modulo sum == 0
    int sum = 0;
    for (int i = 0; cs != 0; i++, cs /= 10)
    {
        if (i % 2 == 0)
        {
            sum += cs % 10;
        }
        else
        {
            int digit_x2 = 2 * (cs % 10);
            sum += digit_x2 / 10 + digit_x2 % 10;
        }
    }
    return (sum % 10) == 0;
}

bool check_validity(long long credit_card_number)
{
    // get length of card number
    // if length is 13, 15 or 16 and checksum is valid, return true
    int len = find_length(credit_card_number);
    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_number);
}

void print_credit_card_brand(long long cs)
{
    // Print card type depending on starting number
    if ((cs >= 34e13 && cs < 35e13) || (cs >= 37e13 && cs < 38e13))
    {
        printf("AMEX\n");
    }
    else if (cs >= 51e14 && cs < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((cs >= 4e12 && cs < 5e12) || (cs >= 4e15 && cs < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    // create spaceholder for creditcard number
    // loop until we get one
    // check if valid
    //   if print brand
    //   else print INVALID
    long long credit_card_number;
    do
    {
        credit_card_number = get_long_long("Number: ");
    }
    while (credit_card_number < 0);

    if (check_validity(credit_card_number))
    {
        print_credit_card_brand(credit_card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}