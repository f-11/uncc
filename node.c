/* node.c
 * AST
 */
#include <stddef.h>
#include "node.h"
#include "uncc.h"

Token *tk;

Node *create_node() {
  Node *node;
  return node;
}

// creating AST to 'nodes' from tokens
void create_ast(Token *head) {
  tk = head;
  int i;
  while(tk != NULL) {
    nodes[i] = create_node();
    i++;
  }
  nodeline_num = i;
  return;
}
