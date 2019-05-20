#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "estado.h"
#include "stack.h"

/**
 * @brief Adiciona o estado atual do jogo à stack.
 * @param e estado atual do jogo
 */
void push(ESTADO e)
{
  struct Node* temp;
  temp = (struct Node*)malloc(sizeof(struct Node));

  temp->estado = e;
  temp->next = top;
  top = temp;
}

/**
 * @brief Verifica se a stack está vazia.
 * @return booleano
 */
int isEmpty()
{
  return top == NULL;
}

/**
 * @brief Indica o último estado adicionado à stack.
 * @return último estado adicionado à stack.
 */
ESTADO peek()
{
  if (!isEmpty())
    return top->estado;
}

/**
 * @brief Remove o último estado adicionado à stack.
 */
void pop()
{
  struct Node* temp;

  if (top != NULL){
    temp = top;
    top = top->next;
    free(temp);
  }
}

/**
 * @brief Inicializa uma stack vazia.
 */
void clean()
{
  top = NULL;
}

/**
 * @brief Devolve o estado do jogo anterior ao atual, acrescenta-o à stack e imprime-o.
 * @param e estado atual do jogo
 * @return estado do jogo anterior ao atual
 */
ESTADO do_undo(ESTADO e)
{
  VALOR tmp = e.peca;
  pop();

  if (top != NULL) {
    e = peek();
    if (tmp==e.peca) e = switchPeca(e);
    printa(e,1,1);
    return e;
  }
  push(e);
  return e;
}
