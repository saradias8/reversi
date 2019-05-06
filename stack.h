#ifndef TESTES_STACK_H
#define TESTES_STACK_H
#include "estado.h"

struct Node {
  ESTADO estado;
  struct Node* next;
};
struct Node* top;

void clean();
void push(ESTADO);
int isEmpty();
ESTADO peek();
void pop();
ESTADO do_undo(ESTADO);

#endif
