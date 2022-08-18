/*
 * node.h
 * nodes of AST
 */
#ifndef NODE_H
#define NODE_H

#include "tokenize.h"

// definition
typedef struct Node {
  struct Node *child1, *child2, *child3;
  Token *tk;
} Node;

// functions
void create_ast(Token *head);

#endif
