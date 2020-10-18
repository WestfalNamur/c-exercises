#include <stdio.h>
#include <cs50.h>


// Print a given char n times
void print_dot(int n, char *c) {

    // loop n times
    for (int i = 0; i < n; i++) {

        // print char
        printf("%s", c);

    }

}


// Print pyramid;
void print_pyramid(int pyramid_height) {

    // loop over rows
    for (int row = 1; row <= pyramid_height; row++) {

        // calculate number of spaces and print them;
        int n_spaces = pyramid_height - row;
        print_dot(n_spaces, " ");

        // calculate number of # and print left side of pyramid;
        int n_hashes = row;
        print_dot(n_hashes, "#");

        // print gap;
        print_dot(2, " ");

        // print right side of the pyramid;
        print_dot(n_hashes, "#");

        // move to next row;
        printf("\n");

    }

}


// ask for input and evaluate if it within defined range;
bool is_in_range(int n) {

    // validate if within range
    if (n > 0 && n < 9) {

        return true;

    } else {

        return false;

    }

}


// main function
int main(void)
{

    // used variables;
    bool in_range = false;
    int input;

    // ask repetitively for user input until it fits within range;
    do {

        // get user input; // Handles non integer inputs for
        input = get_int("Provide a pyramid height: ");
        // validate if input is in range, if yes, set in_range to true
        in_range = is_in_range(input);

    } while (!in_range);

    // if user input is in range, instruction flow moves to here and prints the pyramid
    print_pyramid(input);

};

