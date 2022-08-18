/*
 * tokenize.h
 */
#ifndef TOKENIZE_H
#define TOKENIZE_H

// structure
typedef enum {
  TK_ADD, TK_SUB, TK_MUL, TK_DIV, TK_MOD,       // + - * / %
  TK_BAND, TK_BOR, TK_BXOR,                     // & | ^
  TK_AND, TK_OR, TK_LSHIFT, TK_RSHIFT,          // && || << >>
  TK_LT, TK_LTE, TK_GT, TK_GTE, TK_EQ, TK_NEQ,  // < <= > >=
  TK_LPARA, TK_RPARA, TK_LBLOCK, TK_RBLOCK,     // ( ) { }
  TK_SINGLEQUOTE, TK_DOUBLEQUOTE,               // ' "
  TK_COMMA, TK_PERIOD, TK_COLON, TK_SEMICOLON,  // , . : ;
  TK_NUM, TK_FUNC, TK_VAR,
  TK_EOF
} Token_kind;

typedef struct Token {
  Token_kind kind;
  struct Token *next;
  char *p;    // if token is TK_VAR: use as a name of variable
  union {
    int len;    // if token is TK_VAR: length of variable name. 
    int n;      // else if token is TK_NUM: value of itself
  };
} Token;

// global variable
//extern Token *head;

// functions
Token *tokenize(char *input);
void free_all_tokens(Token *head);
void debug_tokens_print(Token *head);

#endif
