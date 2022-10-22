#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char c, int i);

int main(int argc, string argv[])
{
    // プログラムが1つのコマンドライン引数で実行されたことを確認する。
    if (argv[2] != NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // argv[1] に含まれるすべての文字が数字であることを確認する。
    bool is_digit = only_digits(argv[1]);
    if (!is_digit)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // argv[1] を string から int に変換する。
    int k = atoi(argv[1]);

    // 平文を入力するようにユーザに促す
    string plain_text = get_string("Plaintext: ");
    // 平文に含まれる各文字ごとに繰り返す

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        printf("%c", rotate(plain_text[i], k));
    }
    printf("\n");

    // 文字の場合は、その文字を回転します
}

bool only_digits(string text)
{
    bool is_digit = true;
    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (!(text[i] >= '0' && text[i] <= '9'))
        {
            is_digit = false;
        }
    }
    return is_digit;
}

char rotate(char c, int i)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int result = c + i;
            while (result >= 90)
            {
                result -= 26;
            }
            return (char) result;
        }
        else
        {
            int result = c + i;
            while (result >= 122)
            {
                result -= 26;
            }
            return (char) result;
        }
    }
    else
    {
        return c;
    }
}
