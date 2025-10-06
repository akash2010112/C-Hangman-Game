/*
    Hangman Game
    ----------------------
    The player must guess a secret word letter by letter before running out of attempts.

    Author: [Sandra Martin Elias]
    Date: [2025/09/29]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void hanged(int tries);
void clearInputBuffer();
void checkLetter(char* word, char* guess, char letter, int* tries, int max_tries);

int main() {
    char words[][10]={"computer", "bread", "tree", "science", "dog", "fantasy", "dragon", "table", "raider", "expedition"}, word[20], playAgain;
    srand(time(NULL));

    while (1) {
        int randomIndex=rand()%10;
        int tries=0, max_tries=6, finished=0;
        char letters[27] = {'\0'};
        strcpy(word, words[randomIndex]);
        int length=strlen(word);
        char* guess=malloc(length+1), letter;
        guess[length]='\0';
        for(int i=0;i<length;i++){
            guess[i]='_';
        }

        while (tries < max_tries && !finished) {
            printf("Word: ");
            for (int i = 0; i < length; i++) {
                printf("%c ", guess[i]);
            }
            printf("\n");
            printf("Tries: %d/%d\n", tries, max_tries);
            printf("Letters used: %s\n", letters);
            hanged(tries);

            printf("Enter a letter: ");
            scanf(" %c", &letter);
            clearInputBuffer();
            letter = tolower(letter);

            if (strchr(letters, letter)) {
                printf("You already used that letter. Use another one.\n");
                continue;
            } else {
                int len = strlen(letters);
                letters[len] = letter;
                letters[len + 1] = '\0';
            }

            checkLetter(word, guess, letter, &tries, max_tries);

            if (tries >= max_tries) {
                printf("You lost! The word was: %s\n", word);
                hanged(tries);
                finished=1;
            } else if (strcmp(word, guess) == 0) {
                printf("Congratulations! You guessed the word: %s\n", word);
                finished = 1;
            }
        }

        free(guess);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        clearInputBuffer();
        if (playAgain != 'y' && playAgain != 'Y') {
            printf("Thanks for playing!\n");
            return 0;
        }
    }
}

void hanged(int tries) {
    if (tries == 1) {
        printf("  _______\n");
        printf(" |/      |\n");        
    } else if (tries == 2) {
        printf("  _______\n");
        printf(" |/      |\n");
        printf(" |      (_)\n");        
    } else if (tries == 3) {
        printf("  _______\n");
        printf(" |/      |\n");
        printf(" |      (_)\n");
        printf(" |       |\n");        
    } else if (tries == 4) {
        printf("  _______\n");
        printf(" |/      |\n");
        printf(" |      (_)\n");
        printf(" |      \\|\n");
        printf(" |       |\n");        
    } else if (tries == 5) {
        printf("  _______\n");
        printf(" |/      |\n");
        printf(" |      (_)\n");
        printf(" |      \\|/\n");
        printf(" |       |\n");        
    } else if (tries == 6) {
        printf("  _______\n");
        printf(" |/      |\n");
        printf(" |      (_)\n");
        printf(" |      \\|/\n");
        printf(" |       |\n");
        printf(" |      / \\\n");        
    }

    return;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void checkLetter(char* word, char* guess, char letter, int* tries, int max_tries) {
    int found=0;
    for(int i=0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            guess[i] = letter;
            found = 1;
        }
    }

    if (!found) {
        (*tries)++;
        printf("Wrong guess! You have %d tries left.\n", max_tries - *tries);
    } else {
        printf("Good guess!\n");
    }
}