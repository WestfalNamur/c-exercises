#include <stdio.h>
#include <string.h>

/* Substitution
 *
 * Encrypts a messega by mapping every letter via a cipher to a new message and
 * vice versa (plaintext <-> ciphertext). Only substituting alphabet chars;
 * Chars are just numers in ASCII;
 *
 * Specification:
 * - cipher must contain all 26 letters of the aplhabet;
 * - cipher length = 26;
 * - programm accetps a single command-line-arg => the cipher, If missing retrun
 *   an error and main should return 1;
 * - if coher is invalid do the same;
 * - Your program must output plaintext: (without a newline) and then prompt the
 *   user for a string of plaintext (using get_string);
 * - Your program must output ciphertext: (without a newline) followed by the
 *   plaintext’s corresponding ciphertext, with each alphabetical character in
 *   the plaintext substituted for the corresponding character in the ciphertext;
 *   non-alphabetical characters should be outputted unchanged.
 * - Your program must preserve case: capitalized letters must remain
 *   capitalized letters; lowercase letters must remain lowercase letters.
 * - After outputting ciphertext, you should print a newline. Your program should
 *   then exit by returning 0 from main.
 * 
 * Structure
 *  - Command line args: (key and phrase);
 *  - 
 *
 * TODO:
 * - Take cipher as command-line-arg;
 * - Check cipher;
 * - Use cipher to translate text;
 * - mut local var not global;
 */

// GLOBALS;
char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int ascii_rng[4] = {65, 90, 97, 122};

// Init funcions;
void prnt_str(char str[], int len_str);
void mut_msg_upper(char msg[], char msg_upper[], int msg_upper_bool[], int len_msg);

int main(void)
{
    // take in command line args
    char KEY[] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    char msg[] = "AbC_XyZ!";

    // est. arrays to be mutated;
    int msg_len = strlen(msg);
    char msg_upper[msg_len];
    int msg_upper_bool[msg_len];

    // convert MSG to MSGUPPER
    mut_msg_upper(msg, msg_upper, msg_upper_bool, msg_len);
    prnt_str(msg, msg_len);
    prnt_str(msg_upper, msg_len);

    // ENCIPHER

    // DECIPHER
};

void prnt_str(char str[], int len_str)
{
    for (int i = 0; i < len_str; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void mut_msg_upper(char msg[], char msg_upper[], int msg_upper_bool[], int len_msg)
{
    // converts char[] to be msg just in upper cases;
    for (int i = 0; i < len_msg; i++)
    {
        int c = (int)msg[i];
        if (ascii_rng[2] < c && c > ascii_rng[2])
        {
            // printf("In: %i=%c Out: %i=%c \n", c, c, c - 32, c - 32);
            msg_upper[i] = c - 32;
            msg_upper_bool[i] = 0;
        }
        else
        {
            msg_upper[i] = c;
            msg_upper_bool[i] = 1;
        }
    }
}

// // string = array of chars;
// char KEY[] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
// char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// char MSG[] = "ABC_XYZ"; // should become "YTN_GJO";
// int ascii_rng[4] = {65, 90, 97, 122};
//
// void mut_encipher_msg()
// {
//     // encipher global MSG: char[]; i.e. ABC => YTN
//     // loop over chars in msg;
//     //  - if (char in ascii-char range for upper)
//     //    - Get its pos in normal ASCII  // A=65, B=66, ...;
//     //    - Calculate corresponding cipher pos
//     //    - mutate char in char[];
//     for (int i = 0, n = strlen(MSG); i < n; i++)
//     {
//         int pos_ascii = (int)MSG[i];
//         if (ascii_rng[0] <= pos_ascii && pos_ascii <= ascii_rng[1])
//         {
//             int pos_chipr = pos_ascii - 65;
//             MSG[i] = KEY[pos_chipr];
//         }
//     }
// }
//
// int find_char_pos(char x, char str[])
// // Check if char is in char[]  // returns 0 || pos of char in KEY;
// {
//     for (int i = 0, n = strlen(str); i < n; i++)
//     {
//         if (x == str[i])
//         {
//             return i + 1; // To avoid 0 = false and 1st char;
//         }
//     }
//     return 0;
// }
//
// void mut_decipher_msg()
// {
//     // decipher global MSG: char[];
//     // loop over chars in MSG
//     //  - get pos of char in KEY
//     //  - add 65 to the pos of char in KEY
//     //  - print it as ASCII
//     for (int i = 0, n = strlen(MSG); i < n; i++)
//     {
//         char c = MSG[i];
//         int char_pos_in_key = find_char_pos(c, KEY);
//         if (char_pos_in_key)
//         {
//             char_pos_in_key = char_pos_in_key - 1; // To avoid 0 = false and 1st char;
//             int char_pos_ascii = char_pos_in_key + 65;
//             MSG[i] = char_pos_ascii;
//         }
//     }
// }
//

//
// int main(void)
// {
//     // encipher msg => mutate char[];
//     printf("Input: ");
//     prnt_msg();
//     printf("Enciphered: ");
//     mut_encipher_msg();
//     prnt_msg();
//     printf("Deciphered: ");
//     mut_decipher_msg();
//     prnt_msg();
// };