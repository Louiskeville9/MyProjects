//Program which creates a guessing game for a word. This prompts a user to input a character and then compares this to all characters in a word and returns th result of the game
//Author: Louis Keville | 09/04/24
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defines
#define SIZE 7

int main()
{
    //Variables
    char word[SIZE] = "coding";
    char word1[SIZE] = "------";
    char guess;
    int position;
    int correct;
    int attempts = 6;

    //While loop to keep track of attemps
    while (attempts >= 0)
    {
        int correct = 0; //correct = 1, incorrect = 0

        printf("\nPlease enter your guess: "); //Prompt user for input
        scanf(" %c", &guess); //Scan character entered

        //For loop to compare the guessed character with each element of the word
        for (int i = 0; i < SIZE; i++)
        {
            correct = 0;

                if (guess == word[i]) //comparison is true
                {
                    correct = 1; //Update to correct
                    word1[i] = guess; //Update the word to contain the guessed character
                    printf("\ncorrect guess, it is located here %s\n", word1); //Show user where guess is located
                }
                
        }
                if (correct != 1) //If not correctly guessed
                {
                    printf("\n%c is not in the word %s, Attempts remaining: %d\n", guess, word, attempts); //Show user they are incorrect
                    attempts--; //Decrement the attempts
                }

                int compare = strcmp(word, word1); //Compare if the guessed word is the same as the original

                if (compare == 0)
                {
                    break;
                }
    }

    int compare = strcmp(word, word1); //Compare if the guessed word is the same as the original

    if (compare == 0) //if they are the same
    {
        printf("\nYou Win! the word is %s\n", word); 
    }

    else //if not the same
    {
        printf("\nGame over, you have run out of attempts, correct word is %s\n", word);
    }

    return 0;
    
}
