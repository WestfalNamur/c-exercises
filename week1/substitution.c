#include <stdio.h>
#include <string.h>
#include <cs50.h>

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
 */

// GLOBALS;
char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int ascii_rng[4] = {65, 90, 97, 122};

// Init funcions;
void mut_str_to_upper_case(string key);
bool all_abc_chars_in_str(string str, string abc);
bool char_in_str(char c, string str);
void prnt_str(char str[], int len_str);
void mut_msg_upper(char msg[], char msg_upper[], int msg_upper_bool[], int msg_len);
void mut_encipher_msg(char msg_upper[], char msg_enciphered[], char CIPHER[], int msg_len);



int main(int argc, string argv[])
{
    // 1.   Get key and validate
    // 1.1  Get key or retrun 1 if non is provided
    // 1.2  Key to upper-case
    // 1.3  key-len == 26?
    // 1.4  All alphabetic chars in it?
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }
    string key = argv[1];
    mut_str_to_upper_case(key);
    int key_len = strlen(key);
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    bool all_alphabet_chars_in_str = all_abc_chars_in_str(key, ABC);
    if (!all_alphabet_chars_in_str)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    // 4.   Prompt for input text

    // 5.   Encipher
    //      Preserve case and non-alphabetic characters.

    // 6.   Return enciphered text and return 0;

    // take in command line args
    char CIPHER[] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    char msg[] = "AbC_XyZ!";

    // est. arrays to be mutated;
    int msg_len = strlen(msg);
    char msg_upper[msg_len];
    int msg_upper_bool[msg_len];
    char msg_enciphered[msg_len];

    // convert MSG to MSGUPPER
    //mut_msg_upper(msg, msg_upper, msg_upper_bool, msg_len);
    //prnt_str(msg, msg_len);
    //prnt_str(msg_upper, msg_len);

    // ENCIPHER
    //mut_encipher_msg(msg_upper, msg_enciphered, CIPHER, msg_len);
    //prnt_str(msg_enciphered, msg_len);

    // DECIPHER
};

void mut_str_to_upper_case(string str)
{
    // mutates the passed (&Ref) string to upper case;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        char c = (int)str[i];
        //printf("%c %i \n", c, c);
        if (97 <= c && 122 >= c)
        {
            str[i] = c - 32;
        }
    }
}

bool char_in_str(char c, string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (c == str[i])
        {
            return true;
        }
    }
    return false;
}

bool all_abc_chars_in_str(string str, string abc)
{
    for (int i = 1, n = strlen(str); i < n; i++)
    {
        char c = abc[i];
        bool c_in_str = char_in_str(c, str);
        if (!c_in_str)
        {
            return false;
        }
    }
    return true;
}

void prnt_str(char str[], int len_str)
{
    for (int i = 0; i < len_str; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void mut_msg_upper(char msg[], char msg_upper[], int msg_upper_bool[], int msg_len)
{
    // converts char[] to be msg just in upper cases;
    for (int i = 0; i < msg_len; i++)
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

void mut_encipher_msg(char msg_upper[], char msg_enciphered[], char CIPHER[], int msg_len)
{
    for (int i = 0; i < msg_len; i++)
    {
        int pos_ascii = (int)msg_upper[i];
        if (ascii_rng[0] <= pos_ascii && pos_ascii <= ascii_rng[1])
        {
            int pos_chipr = pos_ascii - 65;
            msg_enciphered[i] = CIPHER[pos_chipr];
        }
        else
        {
            msg_enciphered[i] = msg_upper[i];
        }
    }
}

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