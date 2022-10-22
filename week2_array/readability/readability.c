#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = letters / (float)words * 100;
    float s = sentences / (float)words * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);



    // print
    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentences(s)\n", sentences);

    // printf("%f", l);
    // printf("%f", s);
    // printf("%i sentences(s)\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char upper_case = toupper(text[i]);
        if (upper_case >= 'A' && upper_case <= 'Z')
        {
            letter_count += 1;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int blank_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            blank_count += 1;
        }
    }
    blank_count += 1;
    return blank_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}
