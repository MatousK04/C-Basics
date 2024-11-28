/*
Author - Matous Kloucek
Description - Word Guessing
Date - 09/04/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GUESSAMOUNT 6
#define WORDLENGTH 7
int main()
{
    char *ptr; 
    char guessThis[WORDLENGTH] = "coding";
    ptr = guessThis; //Points at start string
    char underThing = '_'; //Underscore character initalised
    char guess; //Will hold guess
    int correct = 0; //Checks if the guess was correct
    int correctWord = 0; //Increments as word is guessed correctly
    int attemptsLeft = GUESSAMOUNT; //Initalised attempts left
    int temp; //holds index of character
    int wrongGuess = - 0;
    printf("Guess the word! Enter a character!\n");
    while(correctWord != WORDLENGTH - 1)
    {
        scanf("%c",&guess);
        for(int i = 0; i < WORDLENGTH; i++) //For loop goes through the word coding checking if it finds the guess
        {
            if(*(ptr+i) == guess && correct != 1) //Checks if your guess is the certain character
            {
                temp = i; //holds index of correct character
                printf("\nCorrect guess. It is located here:\n");
                while(i > 0) //Prints underscore 
                {
                    printf("%c ",underThing); 
                    i--;
                }
                printf("%c",*(ptr+temp));
                temp = 5 - temp;
                while(temp > 0)
                {
                    printf(" %c ",underThing);
                    temp--;
                }
                correct++;
                correctWord++;
            }
            if(*(ptr+i) != guess)
            {
                wrongGuess++; 
            }
        }
        if(wrongGuess == 7)
        {
            attemptsLeft--;
            wrongGuess = 0;
        }
        if(correctWord == WORDLENGTH - 1) //prints if you get it correct
        {
            printf("\nCongrats you Won the word was %s",guessThis); 
        }
        printf("\n");
        correct = 0;
        if(attemptsLeft == 0)
        {
            printf("\nGame over, you have run out of attempts. The correct word is: coding");
            break;
        }
    }
    return 0;
}