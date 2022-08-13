/*
 * util.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void error(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

