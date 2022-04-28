// use isSpace()

#include <stdio.h>
#include <string.h>
#include "functions.h"

int main () {
    char sentence[250];
    char selection = ' ';
    // enter sample sentence
    printf("Enter a sample text:\n");
    printf("\n");
    fgets(sentence, 250, stdin);
    printf("You entered: %s\n", sentence);

    printf("MENU\n");
    PrintMenu();
    printf("Choose an option:\n");
    scanf(" %c", &selection); 
    // check for initial invalid input
    if (selection != 'c' && selection != 'f' && selection != 'w' && selection != 'r' && selection != 's' && selection != 'q') {
        printf("Choose an option:\n");
        scanf(" %c", &selection); 
    }
    // run until user enters quit
    while (selection != 'q') {
        ExecuteMenu(selection, sentence);
        printf("MENU\n");
        PrintMenu();
        printf("Choose an option:\n");
        scanf(" %c", &selection); 
    }

    return 0;
}