#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <dirent.h>

/* 
Reads a txt file, and writes changes to a different file
  @params: 
  filename: the name of the file
  word: the word you want to replace
  to: the word that will replace 'word'
*/
void readData(char* filename, char* word, char* to) {

  //filename = concat("reference-files/", filename);
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


/* A Function that prints the contents of a folder.
  @params:
  folder_name: the name of the folder you want to view inside. 
  @return: 0 upon completion, 1 upon failure 
*/
int print_contents(char *folder_name) {
  DIR *folder = opendir(folder_name);
  if (folder == NULL) {
    printf("Unable to open the folder!");
    return 1;
  }

  struct dirent *entry;
  int files = 0;
  while( (entry = readdir(folder)) ) {
    printf("File %3d: %s\n", files, entry->d_name);
    files++;
  }
  return 0;
}

/* 
Asks user for: 
  1. filename: the file name they want to reference
  2. word: the word that they want to replace
  3. to: the word that will repalace 'word' 
*/
int main(void) {
  printf("Search & Replace! \n");

  /* Ask the user if they wanna see the contents of the reference folder. */
  char choice[3];
  printf("\nWould you like to see the .txt files in 'reference-files? 'Y'/'N' \n\n");
  if (*choice == 'Y') {
    print_contents("reference-files");
  }

   /* Get the name of the file. */
  char file[20];
  printf("Enter your file's name: \n ");
  scanf("%s", file);

  /* Setup the directory.*/ 
  char dest[40] = "reference-files/";
  strcat(dest, file);

  /* Get the word the user wants to replace. */ 
  char word[20];
  printf("Enter your word that you want to REPLACE: \n");
  scanf("%s", word);

  /* Get the word the user wants to replace TO. */ 
  char to[20];
  printf("Enter the word you want to change it TO: \n");
  scanf("%s", to);

  /* Call to function that does all the work. */ 
  readData(dest, word, to);

  return 0;
}


