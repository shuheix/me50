#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int count;
    do
    {
        height = get_int("Height: ");
    }
    while (height >= 9 || height <= 0);

    for (int i = 0; i < height; i++)
    {
        // left
        for (int k = 1; k < height - i; k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // right
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        // for(int m = 1; m < height - i; m++)
        // {
        //     printf(" ");
        // }


        printf("\n");

    }
}

