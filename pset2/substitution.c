#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char msg[] = "hello, world";

int main(int argc, char *argv[])
{
    // 1 Check if cipher_key exists
    // 2 Cipher is 26 chars long
    // 3 Cipher contains all chars of the alphabet

    if (argc != 2)
    {
        printf("Usage: ./substiturion (string) cipher_key \n");
        return 1;
    }

    string key = argv[1];
    if (key == NULL)
    {
        printf("Usage: ./substiturion (string) cipher_key  \n");
        return 1;
    }
    if (strlen(key) != 26)
    {
        printf("cipher_key must contain exact 26 chars \n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        char c = ABC[i];
        bool c_in_key = false;
        for (int i = 0; i < 26; i++)
        {
            if (key[i] == c)
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
}
