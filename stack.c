#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "estado.h"
#include "stack.h"

//Inserir elementos no inicio
void push(ESTADO e)
{
  struct Node* temp;
  temp = (struct Node*)malloc(sizeof(struct Node));

  temp->estado = e;
  temp->next = top;
  top = temp;
}

//Verificar se a stack esta vazia
int isEmpty()
{
  return top == NULL;
}

//Indicar o elemento do topo da stack
ESTADO peek()
{
  if (!isEmpty(top))
    return top->estado;
}

//Remover o elemento no topo da stack
void pop()
{
  struct Node* temp;

  if (top != NULL){
    temp = top;
    top = top->next;
    free(temp);
  }
}

void clean()
{
  top = NULL;
}

ESTADO do_undo(ESTADO e)
{
  pop();
  if (top != NULL) {
    e = peek();
    printa(e,1,1);
    return e;
  }
  push(e);
  return e;
}
