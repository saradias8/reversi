#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "estado.h"
#include "stack.h"

//Inserir elementos no inicio
void push(ESTADO e){
  //criar um novo nodo temp e alocar memoria
  struct Node* temp;
  temp = (struct Node*)malloc(sizeof(struct Node));

  //verificar se a stack esta cheia“out-of-memory”
  if (!temp) {
    printf("\nStack sobrelotada");
  }

  //introduzir os dados no respetivo campo em temp
  temp->estado = e;

  //direcionar o apontador top para temp
  temp->next = top;

  //tornar temp o topo da stack
  top = temp;
}

//Verificar se a stack esta vazia
int isEmpty(){
  return top == NULL;
}

//Indicar o elemento do topo da stack
ESTADO peek()
{
  //verificar se esta vazia
  if (!isEmpty(top))
    return top->estado;
}

//Remover o elemento no topo da stack
void pop(){
  struct Node* temp;

  //verificar se esta vazia
  if (top == NULL) {
    printf("\nStack vazia");
  }
  else {
    //top fica com o valor de temp
    temp = top;
    //o nodo seguinte passa a ser o topo
    top = top->next;
    //libertar memoria do nodo de topo
    free(temp);
  }
}

//Mostrar o conteudo da stack
void display(){
  struct Node* temp; char c;
  //verifica se esta vazia
  if (top == NULL) {
    printf("\nStack vazia");
  }
  else {
    temp = top;
    while (temp != NULL) {
      //imprime o valor do nodo
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
      //direciona o apontador para temp
      temp = temp->next;
    }
  }
}

ESTADO do_undo(ESTADO e)
{
  pop();
  if (top != NULL) {
    //display();
    e = peek();
    printa(e,1,1);
    return e;
  }
  push(e);
  //printa(e,1,1);
  return e;
}
