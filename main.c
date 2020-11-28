#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>


/* 
Reads a txt file, and writes changes to a different file
  @params: 
  filename: the name of the file
  word: the word you want to replace
  to: the word that will replace 'word'
*/
void readData(char* filename, char* word, char* to) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file!");
    exit(-1);
  }
  FILE *nuevo = fopen("new.txt", "w");
  if (fp == NULL) {
    printf("Error opening file!");
    exit(-1);
  }
  char inBible[20];
  while (!feof(fp)) {
    fscanf(fp, " %s ", inBible);
    if (strcmp(inBible, word) == 0) {
      fprintf(nuevo, " %s ", to);
    }
    else{
    fprintf(nuevo, " %s ", inBible);
      }
  }
  fclose(fp);
  fclose(nuevo);
  printf("\nDONE!");
}

/* 
Asks user for: 
  1. filename: the file name they want to reference
  2. word: the word that they want to replace
  3. to: the word that will repalace 'word' 
*/
int main(void) {
  char file[20];
  printf("Enter your file's name: \n ");
  scanf("%s", file);
  char word[20];
  printf("Enter your word that you want to REPLACE: \n");
  scanf("%s", word);
  char to[20];
  printf("Enter the word you want to change it TO: \n");
  scanf("%s", to);
  readData(file, word, to);

  return 0;
}
