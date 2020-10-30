#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// char msg[] = "Hello, World";

int main(int argc, char *argv[])
{
    // 1 Check if cipher_key exists
    // 2 Cipher is 26 chars long
    // 3 Cipher contains all chars of the alphabet
    // 4 Get msg
    // 5 Create copy of msg to manipulate
    // 6 Create int array to store if msg char is upper

    if (argc != 2)
    {
        printf("Usage: ./substiturion (string) cipher_key \n");
        return 1;
    }

    string key = argv[1];
    if (key == NULL)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        char c = ABC[i];
        bool c_in_key = false;
        for (int j = 0; j < 26; j++)
        {
            if (key[j] == c)
            {
                c_in_key = true;
            }
        }
        if (c_in_key == false)
        {
            printf("%c is missing in key \n", c);
            return 1;
        }
    }

    string msg = get_string("Input: ");

    char msg_upper[strlen(msg)];
    int msg_c_is_upper[strlen(msg)];
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        int c = (int)msg[i];
        if (c >= 65 && c <= 90)
        {
            msg_upper[i] = c;
            msg_c_is_upper[i] = 1;
        }
        else if (c >= 97 && c <= 122)
        {
            msg_upper[i] = c - 32;
            msg_c_is_upper[i] = 0;
        }
        else
        {
            msg_upper[i] = c;
            msg_c_is_upper[i] = 2;
        }
    }

    char msg_encypted_upper[strlen(msg)];
    for (int i = 0, n = strlen(msg_upper); i < n; i++)
    {
        int c_int = (int)msg_upper[i];
        char c_enrypted;
        if (c_int >= 65 && c_int <= 90)
        {
            c_enrypted = key[c_int - 65];
        }
        else
        {
            c_enrypted = msg_upper[i];
        }
        msg_encypted_upper[i] = c_enrypted;
        printf("In: %c  Out: %c", msg_upper[i], c_enrypted);
        printf("\n");
    }

    printf("plaintext:  ");
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        printf("%c", msg[i]);
    }
    printf("\n");
    printf("ciphertext: :  ");
    for (int i = 0, n = strlen(msg_encypted_upper); i < n; i++)
    {
        int was_upper = msg_c_is_upper[i];
        if (was_upper == 0)
        {
            int c_int = (int)msg_encypted_upper[i] + 32;
            printf("%c", c_int);
        }
        else
        {
            printf("%c", msg_encypted_upper[i]);
        }
    }
    printf("\n");

    // ************************************************************************
    // for (int i = 0, n = strlen(key); i < n; i++)
    // {
    //     printf("%c", key[i]);
    // }
    // printf("\n");
    // for (int i = 0, n = strlen(msg); i < n; i++)
    // {
    //     printf("%c", msg[i]);
    // }
    // printf("\n");
    // for (int i = 0, n = strlen(msg_upper); i < n; i++)
    // {
    //     printf("%c", msg_upper[i]);
    // }
    // printf("\n");
    // for (int i = 0, n = strlen(msg_upper); i < n; i++)
    // {
    //     printf("%i", msg_c_is_upper[i]);
    // }
    // printf("\n");
    // for (int i = 0, n = strlen(msg_encypted_upper); i < n; i++)
    // {
    //     printf("%c", msg_encypted_upper[i]);
    // }
    // printf("\n");

    return 0;
}