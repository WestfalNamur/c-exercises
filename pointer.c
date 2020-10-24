#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);

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

    // Do not forget to free t again!
    // To check:
    // clear && clang pointer.c -o pointer && valgrind --leak-check=yes -s ./pointer
    free(t);

    // ... or use a standard lib;
    char str1[5] = "EMMA";
    char str2[strlen(str1)];
    strcpy(str2, str1);

    // Swap
    int x = 1;
    int y = 2;
    printf("x: %i, y: %i \n", x, y);
    swap(&x, &y);
    printf("x: %i, y: %i \n", x, y);
}

void swap(int *a, int *b)
{
    // Get passed addresses of two ints: swap(&x, &y);
    // The function input takes these addresses to point to theses ints;
    // 1. tmp goes to address *a is pointing to and get the stored value;
    // 2. *a go to *b and takes what is there to address a;
    // 3. put what is stored as tmp at the address of *b;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}