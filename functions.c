#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

void PrintMenu() {
    printf("c - Number of non-whitespace characters\n");
    printf("w - Number of words\n");
    printf("f - Fix capitalization\n");
    printf("r - Replace all !'s\n");
    printf("s - Shorten spaces\n");
    printf("q - Quit\n");
    printf("\n");
}

void ExecuteMenu(char selection, char sentence[]) {

    switch (selection) {
        // c option
            case 'c':
                printf("Number of non-whitespace characters: %d\n", GetChars(sentence));
                printf("\n");
                break;
        // w option
            case 'w':
                printf("Number of words: %d\n", GetWords(sentence));
                printf("\n");
                break;
        // f option
            case 'f':
                FixCapitals(sentence);
                printf("Edited text: %s\n", sentence);
                break;
        // r option
            case 'r':
                ReplaceExclamation(sentence);
                printf("Edited text: %s\n", sentence);
                break;
        // s option
            case 's':
                ShortenSpaces(sentence);
                printf("Edited text: %s\n", sentence);
                break;
        // q option
            case 'q':
                break;
            default:
                break;
        }
    
}


int GetChars(char sentence[]) {
    int count = 0;
    // cycle through each character of the array
    for (int i = 0; i < strlen(sentence); ++i) {
        if (isspace(sentence[i]) == 0) {
            // add to counter if it is not a space
            count += 1;
        }
    }
    return count;
}

int GetWords(char sentence[]) {
    // count the first word
    int count = 1;
    for (int i = 0; i < strlen(sentence); i++) {
        // count words after no more spaces
        if (sentence[i] == ' ' && sentence[i + 1] != ' ') {
            count += 1;
        }
    }
    return count;
}

void FixCapitals(char sentence[]) {
    // start count at one to account for letter spacing
    int count = 1;
    // capitalize first letter of sentence
    sentence[0] = toupper(sentence[0]);
    for (int i = 0; i < strlen(sentence); i++) {
        // find period and start counting spaces
        if (sentence[i] == '.' && isspace(sentence[i+1]) != 0) {
            while (isalpha(sentence[i + 1 + count]) == 0) {
                // add to counter if there are extra spaces
                count += 1;
            }
            // capitalize letter immediately after spaces
            sentence[i + count + 1] = toupper(sentence[i + count + 1]);
        }
    }
}

void ReplaceExclamation(char sentence[]) {
    for (int i = 0; i < strlen(sentence); i++) {
        // switch ! to .
        if (sentence[i] == '!') {
            sentence[i] = '.';
        }
    }
}

void ShortenSpaces(char sentence[]) {
    char tempStr[250];
    int j = 0;

    for (int i = 0; i < strlen(sentence); ++i) {
        // 
        if (sentence[i] == ' ' && sentence[i+1] == ' ') {
            // skip if multiple spaces
        } else {
            // add to new temp array
            tempStr[j] = sentence[i];
            j++;
        }
    } 
    tempStr[j] = '\0';
    // copy tempString to sentence string
    strcpy(sentence, tempStr);
}