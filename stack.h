#ifndef TESTES_STACK_H
#define TESTES_STACK_H
#include "estado.h"

//Declarar o nodo da lista-ligada
struct Node {
  ESTADO estado;
  struct Node* next;
};
struct Node* top; //stack

void push(ESTADO);
int isEmpty();
ESTADO peek();
void pop();
void display();
ESTADO do_undo(ESTADO);

#endif 
