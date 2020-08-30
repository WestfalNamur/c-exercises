#include <stdio.h>
#include <cs50.h>


// Credit cards have numbers; Different starting digets for different operators;
// They have a checksum to validate them;
// AMEX start with 34 or 37; MASTERCARD with 51, 52, 53, 54; VISA with 4;


int sum_up_luhn(long long n){
    // calcualte the sum of a number following Luhn's alg.
    int sum = 0;  // Sum of digits following Luhn's alg.
    bool is_every_other = false;  // Idendify if digit is every other;
    // loop backwards over digits in number
    while(n) {
        // get current digit
        int digit = n % 10;
        // branch depending if it is every other diggit.
        if (is_every_other) {
            // double the diggit
            int digit_2x = digit * 2;
            // Add the sum of double digits to total digit sum
            while(digit_2x) {
                sum += digit_2x % 10;
                digit_2x /= 10;
            };
        } else {
            // add digit to sum of digits
            sum += digit;
        };
        // move on to next digit by droping current one & toggle is_every_other;
        n /= 10;
        is_every_other = !is_every_other;
    };
    return sum;
}


int length_of_number(long long n) {
    int sum = 0;
    while(n) {
        sum++;
        n /= 10;
    };
    return sum;
}


int get_first_digits_of_number(long long number, int n_digits, int lenght) {
    // copy number
    long number_copy = number;
    // loop over number and remove digits up to the n-first digits
    for (int i = 0; i < lenght - n_digits; i++) {
        number_copy /= 10;
    };
    int first_digits = number_copy; // whats left
    return first_digits;
};


void validate_card_number(long long card_number) {
    // sum digits after Luhn's alg
    int sum_digits = sum_up_luhn(card_number);

    // validate
    bool is_valid = sum_digits % 10 == 0;

    // get number of digits;
    int len = length_of_number(card_number);

    // find provider if card_number is valid
    if (is_valid) {

        // valiadte number by lenght and starting digits
        // get first digit
        int first_digit = get_first_digits_of_number(card_number, 1, len);
        printf("%d\n", first_digit);

    } else {
        printf("INVALID\n");
    };
}

int main(void) {

    // get credit card number
    // 4003600000000014
    // long card_number = get_long("Credit card number is: ");
    long card_number = 4003600000000014;

    // validate card number
    validate_card_number(card_number);
};

// TODO: check if MASTERCARD or VISA is valid; // it seems not?!
// run style check
// run check
