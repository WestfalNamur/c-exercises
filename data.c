#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // Add a value to an array; *******************************************************************
    // 1 Allocate memory; note: check retrun value;
    // 2 Add values to it
    // 3 Allocate space for new array
    // 4 Copy values over
    // 5 Add new one
    // 6 Free list by passing its address
    int *list_0 = malloc(3 * sizeof(int));
    if (list_0 == NULL)
    {
        return 1;
    }
    list_0[0] = 1;
    list_0[1] = 2;
    list_0[2] = 3;
    int *tmp_0 = malloc(4 * sizeof(int));
    if (tmp_0 == NULL)
    {
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        tmp_0[i] = list_0[i];
    }
    tmp_0[3] = 4;
    free(list_0);
    list_0 = tmp_0;
    for (int i = 0; i < 4; i++)
    {
        printf("%i", list_0[i]);
    }
    printf("\n");
    free(list_0);

    // Same with realloc; *************************************************************************
    // It takes over copying the values over and lose pointer to old data in
    // memory. From the documentaion:
    // Reallocates the given area of memory. It must be previously allocated by
    // malloc(), calloc() or realloc() and not yet freed with a call to free or
    // realloc. Otherwise, the results are undefined.
    int *list_1 = malloc(3 * sizeof(int));
    if (list_1 == NULL)
    {
        return 1;
    }
    list_1[0] = 1;
    list_1[1] = 2;
    list_1[2] = 3;
    int *tmp_1 = realloc(list_1, 4 * sizeof(int));
    if (tmp_1 == NULL)
    {
        return 1;
    }
    list_1 = tmp_1;
    list_1[3] = 4;
    for (int i = 0; i < 4; i++)
    {
        printf("%i", list_1[i]);
    }
    printf("\n");
    free(list_1);

    // Linked lists *******************************************************************************
    // Define node struct (value and pointer to next node)
    typedef struct
    {
        int number;
        struct node *next;
    } node;

    node *linked_list = NULL;       // Create list; It is empty so it points to nothing;
    node *n = malloc(sizeof(node)); // Allocate memory for the 1st node; Assogn pointer to it *n;
    n->number = 2;                  // (*n).number = 2; Dereference number asstribute of node tp 2;
    n->next = NULL;                 // Set pointer to NULL as ther is no other node yet;
    linked_list = n;                // With the 1st node finished, point to it;
}