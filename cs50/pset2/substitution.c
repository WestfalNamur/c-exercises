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
    {
        printf("No key!");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("key is not 26 chars long");
        return 1;
    }

    // ************************************************************************
    // KEY TO UPPER
    char key[strlen(argv[1])];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        int ci = (int)argv[1][i];
        char c;
        if (ci >= 65 && ci <= 90)
        {
            c = ci;
        }
        else if (ci >= 97 && ci <= 122)
        {
            c = ci - 32;
        }
        else
        {
            printf("%c is not an ABC char! \n", ci);
        }
        key[i] = (char)c;
    }

    // ************************************************************************
    // Check key
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
            printf("%c not in ABC \n", c);
            return 1;
        }
    }

    // ************************************************************************
    string msg = get_string("plaintext: ");
    int msg_upper_012[strlen(msg)];
    char msg_upper[strlen(msg)];
    char msg_upper_enrypted[strlen(msg)];
    char msg_enrypted[strlen(msg)];

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

    // ************************************************************************
    // ENCRYPT UPPER
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        int c = (int)msg_upper[i];
        if (c >= 65 && c <= 90)
        {
            int x = key[c - 65];
            msg_upper_enrypted[i] = (char)x;
        }
        else
        {
            msg_upper_enrypted[i] = (char)c;
        }
    }

    // ************************************************************************
    // ADD CASING back
    for (int i = 0, n = strlen(msg_upper_enrypted); i < n; i++)
    {
        int u = msg_upper_012[i];
        int c;
        if (u == 0)
        {
            c = (int)msg_upper_enrypted[i] + 32;
        }
        else
        {
            c = (int)msg_upper_enrypted[i];
        }
        msg_enrypted[i] = (char)c;
    }
    msg_enrypted[strlen(msg)] = '\0';
    printf("ciphertext: ");
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