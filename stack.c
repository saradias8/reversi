#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "estado.h"
#include "stack.h"

//Inserir elementos no inicio
void push(ESTADO e){
  struct Node* temp;
  temp = (struct Node*)malloc(sizeof(struct Node));

  if (!temp) {
    printf("\nStack sobrelotada");
  }
  temp->estado = e;
  temp->next = top;
  top = temp;
}

//Verificar se a stack esta vazia
int isEmpty(){
  return top == NULL;
}

//Indicar o elemento do topo da stack
ESTADO peek()
{
  if (!isEmpty(top))
    return top->estado;
}

//Remover o elemento no topo da stack
void pop(){
  struct Node* temp;

  if (top == NULL) {
    printf("\nStack vazia");
  }
  else {
    temp = top;
    top = top->next;
    free(temp);
  }
}

//Mostrar o conteudo da stack
void display(){
  struct Node* temp; char c;
  if (top == NULL) {
    printf("\nStack vazia");
  }
  else {
    temp = top;
    while (temp != NULL) {
      for (i = 0; i < 8; i++) {
      printf("%d ",(i+1));
      for (j = 0; j < 8; j++) {
        if(temp->estado.grelha[i][j] == VALOR_O)      c = 'O';
        else if(temp->estado.grelha[i][j] == VALOR_X) c = 'X';
        else if(temp->estado.grelha[i][j] == VAZIA)   c = '-';
        printf("%c ", c);
      }
      printf("\n");
    }
      temp = temp->next;
    }
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
