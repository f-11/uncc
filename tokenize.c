/*
 * tokenize.c
 * convert string into token chain
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenize.h"
#include "util.h"

Token *head;

void new_token (Token_kind kind) {
  Token *new = calloc(1, sizeof(Token));
  head->next = new;
  head = new;
  new->kind = kind;
}

void new_number_token(int n) {
  Token *new = calloc(1, sizeof(Token));
  head->next = new;
  head = new;
  new->kind = TK_NUM;
  return;
}

Token *tokenize(char *input) {
  Token dummy;
  head = &dummy;

  char *p = input;
  for (;;) {
    if (*p == '\0' || *p == EOF) {
      new_token(TK_EOF);
      break;
    } else if (isspace(*p)) {
      p++;
      continue;
    } else if (isdigit(*p)) {
      //char *end;
      int n = (int)strtol(p, &p, 10);
      new_number_token(n);
      //p = end - 1;
      continue;
    } else if (*p == '+') {
      new_token(TK_ADD);
      p++;
      continue;
    } else if (*p == '-') {
      new_token(TK_SUB);
      p++;
      continue;
    } else if (*p == '*') {
      new_token(TK_MUL);
      p++;
      continue;
    } else if (*p == '/') {
      new_token(TK_DIV);
      p++;
      continue;
    } else if (*p == ';') {
      new_token(TK_SEMICOLON);
      p++;
      continue;
    }
    error("tokenize failed.");
  }

  return dummy.next;
}

// release memories allocated in function tokenize 
void free_all_tokens(Token *head) {
  Token *next, *p = head;
  while(p != NULL) {
    next = p->next;
    free(p);
    p = next;
  }
}

void debug_tokens_print(Token *head) {
  Token *tk  = head;
  do {
    printf("TOKEN: %d\n", tk->kind);
    tk = tk->next;
  } while(tk != NULL);
}
