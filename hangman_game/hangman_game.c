#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./hangman_pic.c"

char words[][10] = {"cat", "dog", "bird", "fish", "mouse", "horse", "snake", "lion", "tiger", "elephant"};

// Get random word from words-array
char *get_random_word()
{
    srand(time(0));
    int random_index = rand() % 10;
    return words[random_index];
}

// Request user input guess letter
char get_guess()
{
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);
    return guess;
}

// Show missed letters and guessed letters after each guess (below hangman picture)
void display_missed_guessed_word(char *missed_letters, char *word, char *guessed_letters)
{
    printf("- Missed letters: %s\n", missed_letters);
    printf("- Guess letters: ");
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        if (strchr(guessed_letters, word[i]))
        {
            printf("%c ", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

// Show board game each guess
void display_board(char *secret_word, char *missed_letters, char *guessed_word)
{
    hangman_picture(strlen(missed_letters));
    display_missed_guessed_word(missed_letters, secret_word, guessed_word);
}

int check_letter_in_word(char c, char word[])
{
    return strchr(word, c);
}

// Check game is won
int game_success(char *guessed_word, char *secret_word, char *missed_letters)
{
    int game_success = 1;
    for (int i = 0; i < strlen(secret_word); i++)
    {
        if (strchr(guessed_word, secret_word[i]) == NULL)
        {
            game_success = 0;
            break;
        }
    }

    if (game_success)
    {
        display_board(secret_word, missed_letters, guessed_word);
        printf("\n  Congratulations! You won! The secret word is: %s !\n", secret_word);
    }
    return game_success;
}

// Check game is lost
int game_over(char *missed_letters, char *secret_word, char *guessed_word)
{
    int game_over = (strlen(missed_letters) == 6);
    if (game_over)
    {
        display_board(secret_word, missed_letters, guessed_word);
        printf("\n  Sorry, you lost! The secret word is: %s!\n", secret_word);
    }
    return game_over;
}

// Question: Play again?
int play_again()
{
    char answer;
    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &answer);
    return answer == 'y';
}

int main()
{
    printf("\n Welcome to H-A-N-G-M-A-N! \n");
    char missed_letters[26] = {0};
    char guessed_word[26] = {0};
    char *secret_word = get_random_word();
    int game_done = 0;
    
    while (1)
    {
        // Start game
        display_board(secret_word, missed_letters, guessed_word);
        char guess_letter = get_guess();

        if (check_letter_in_word(guess_letter, secret_word))
        {
            if (check_letter_in_word(guess_letter, guessed_word) == 0)
                guessed_word[strlen(guessed_word)] = guess_letter;
            printf(">>> Good guess! \n");
        }
        else
        {
            missed_letters[strlen(missed_letters)] = guess_letter;
            printf(">>> Oops! That letter is not in my word\n");
        }

        int game_s = game_success(guessed_word, secret_word, missed_letters);
        int game_o = game_over(missed_letters, secret_word, guessed_word);
        game_done = game_s || game_o;

        if (game_done)
        {
            if (play_again())
            {  
                // Play again if user want. Reset all parameters of game
                for (size_t i = 0; i < 26; i++)
                {
                    missed_letters[i] = 0;
                    guessed_word[i] = 0;
                }
                secret_word = get_random_word();
                game_done = 0;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}