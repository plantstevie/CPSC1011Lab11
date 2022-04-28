#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void PrintMenu();
void ExecuteMenu(char selection, char sentence[]);
int GetChars(char sentence[]);
int GetWords(char sentence[]);
void FixCapitals(char sentence[]);
void ReplaceExclamation(char sentence[]);
void ShortenSpaces(char sentence[]);

#endif