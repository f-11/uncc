/*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"
#include "util.h"

#define BUFSIZE (1024)

int main(int argc, char **argv) {
  FILE *fp;
  char c, *input;
  int len = 0;

  if (argc > 1) {
    if (strncmp(argv[1], "-", 1) == 0)
      fp = stdin;
    else
      fp = fopen(argv[1], "r");
    if (fp == NULL) {
      fprintf(stderr, "error on file read.\n");
      exit(0);
    }
  } else {
    fprintf(stderr, "no input file.\n");
    exit(0);
  }

  // read file and write to  memory buffer
  input = (char *)calloc(BUFSIZE, sizeof(char));
  do {
    c = fgetc(fp);
    *(input + len) = c;
    len++;
  } while(c != EOF);

  // parse
  Token *head = tokenize(input);

  // create AST node

  // code generation

  debug_tokens_print(head);
  free_all_tokens(head);

  free(input); // release input budder
  fclose(fp);

  return 0;
}
