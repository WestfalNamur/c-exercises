#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // hexadecimal ot base 16:
    // Numeral system with the base of 16. Conventional denoted as 0x********;
    // User for in memory addresses;

    // &: address of an object on memory;
    // *: pointer to an object on memory; "go to":
    int n = 50;
    printf("%p\n", &n);

    // *p is a point to the address of n, which is an int;
    // print the bites at address p => go to the address of *p and read it as an int;
    // p here, stores the address of 50 in memory;
    int *p = &n;
    printf("%i\n", *p);

    // a string is just a pointer to the address of the first char in an array
    // of chars terminated by /0 (00000000 in memory);
    char *s = "EMMA";
    printf("%s\n", s);

    // Print address of chars;
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    // Point to and print the 3rd char in "EMMA";
    printf("%c\n", *(s + 2));

    // How do we copy an array or string?
    // x = s is a reference to s pointing to the same object in memory;
    // To copy we:
    // 1. allocated needed memory; Here 4 + 1 (1 for the terminating char);
    // 2. Loop over and copy char by char; Here untit <= to include /0;
    char *t = malloc(strlen(s) + 1);
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // ... or use a standard lib;
    char str1[5] = "EMMA";
    char str2[strlen(str1)];
    strcpy(str2, str1);
}