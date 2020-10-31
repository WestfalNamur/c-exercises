#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // 2. Your program must prompt the user for a string of text (using get_string).
    string text_str = get_string("Text: ");

    // 3. Your program should count the number of letters, words, and sentences
    // in the text. You may assume that a letter is any lowercase character
    // from a to z or any uppercase character from A to Z, any sequence of
    // characters separated by spaces should count as a word, and that any
    // occurrence of a period, exclamation point, or question mark indicates
    // the end of a sentence.
    int n_words = 0;
    int n_sentences = 0;
    int n_letters = 0;
    for (int i = 0, len = strlen(text_str); i < len; i++)
    {
        char c = text_str[i];
        if (isalpha(c))
        {
            n_letters++;
        }
        if ((i == 0 && c != ' ') || (i != len - 1 && c == ' ' && text_str[i + 1] != ' '))
        {
            n_words++;
        }
        if (c == '.' || c == '?' || c == '!')
        {
            n_sentences++;
        }
    }

    // 4. Your program should print as output "Grade X" where X is the grade
    // level computed by the Coleman-Liau formula, rounded to the nearest
    // integer.
    // 5. If the resulting index number is 16 or higher (equivalent to or
    // greater than a senior undergraduate reading level), your program should
    // output "Grade 16+" instead of giving the exact index number. If the
    // index number is less than 1, your program should output "Before Grade 1".
    float L = (n_letters / (float)n_words) * 100;
    float S = (n_sentences / (float)n_words) * 100;
    int coleman_liau_index = round(0.0588 * L - 0.296 * S - 15.8);
    if (coleman_liau_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_liau_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", coleman_liau_index);
    }

    return 0;
}
