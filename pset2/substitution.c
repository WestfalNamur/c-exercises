#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>

char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void prnt_str(string s);

int main(int argc, char *argv[])
{
    // ************************************************************************
    if (argc != 2)
        return 1;
    if (strlen(argv[1]) != 26)
        return 1;
    for (int i = 0; i < 26; i++)
    {
        char c = ABC[i];
        bool c_in_key = false;
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][j] == c)
                c_in_key = true;
        }
        if (c_in_key == false)
            return 1;
    }

    // ************************************************************************
    string msg = get_string("Input: ");
    int msg_upper_012[strlen(msg)];
    char msg_upper[strlen(msg)];
    char msg_upper_enrypted[strlen(msg)];
    char msg_enrypted[strlen(msg)];

    printf("plaintext: ");
    prnt_str(msg);

    // ************************************************************************
    //  TO UPPER
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        int c = msg[i];
        if (c >= 65 && c <= 90)
        {
            msg_upper[i] = c;
            msg_upper_012[i] = 1;
        }
        else if (c >= 97 && c <= 122)
        {
            msg_upper[i] = c - 32;
            msg_upper_012[i] = 0;
        }
        else
        {
            msg_upper[i] = c;
            msg_upper_012[i] = 2;
        }
    }
    printf("plaintext upper: ");
    prnt_str(msg_upper);

    // ************************************************************************
    // ENCRYPT UPPER
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        int c = (int)msg_upper[i];
        if (c >= 65 && c <= 90)
        {
            int x = argv[1][c - 65];
            msg_upper_enrypted[i] = (char)x;
            printf("In: %c  Out: %c \n", c, msg_upper_enrypted[i]);
        }
        else
        {
            msg_upper_enrypted[i] = (char)c;
            printf("In: %c  Out: %c \n", c, msg_upper_enrypted[i]);
        }
    }
    printf("encrypted upper: ");
    prnt_str(msg_upper_enrypted);

    // ************************************************************************
    // CASING
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        if (msg_upper_012[i] == 0)
        {
            int c = msg_upper_enrypted[i];
            int x = c + 32;
            msg_enrypted[i] = (char)x;
        }
        else
        {
            msg_enrypted[i] = msg_upper_enrypted[i];
        }
    }
    printf("encrypted: ");
    prnt_str(msg_enrypted);

    // ************************************************************************
    printf("Success! \n");
    return 0;
}

void prnt_str(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}