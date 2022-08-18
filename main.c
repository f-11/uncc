/*
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"
#include "node.h"
#include "gen.h"
#include "util.h"

#define BUFSIZE (1024)
#define NODEBUF (256)

// global var
Token *head;
Node* nodes[NODEBUF];
int nodeline_num = 0;

FILE *cli_fp(int argc, char **argv) {
  FILE *fp;
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
  return fp;
}

int main(int argc, char **argv) {
  FILE *fp;
  char c, *input;
  int len = 0;

  fp = cli_fp(argc, argv);

  // read file and write to  memory buffer
  input = (char *)calloc(BUFSIZE, sizeof(char));
  do {
    c = fgetc(fp);
    *(input + len) = c;
    len++;
  } while(c != EOF);

  // parse
  head = tokenize(input);
  create_ast(head);

  // code generation
  for (int i = 0; i < nodeline_num; i++)
    generate_code();

  debug_tokens_print(head);

  free_all_tokens(head); // release tokens buffer
  free(input); // release input budder
  fclose(fp);

  return 0;
}
