#include <stdio.h>

void hangman_pic_0()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_1()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_2()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf("  |   |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_3()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf(" /|   |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_4()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf(" /|\\  |  \n");
    printf("      |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_5()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf(" /|\\  |  \n");
    printf(" /    |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_pic_6()
{
    printf("\n");
    printf("  +---+  \n");
    printf("  |   |  \n");
    printf("  O   |  \n");
    printf(" /|\\  |  \n");
    printf(" / \\  |  \n");
    printf("      |  \n");
    printf("=========\n");
    printf("\n");
}

void hangman_picture(int step)
{
    switch (step)
    {
    case 1:
        hangman_pic_1();
        break;
    case 2:
        hangman_pic_2();
        break;
    case 3:
        hangman_pic_3();
        break;
    case 4:
        hangman_pic_4();
        break;
    case 5:
        hangman_pic_5();
        break;
    case 6:
        hangman_pic_6();
        break;
    default:
        hangman_pic_0();
        break;
    }
}
