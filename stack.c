#include <malloc.h>
#include <stdio.h>

//Inserir elementos no inicio
void push(ESTADO e){
  //criar um novo nodo temp e alocar memoria
  struct Node* temp;
  temp = (structNode*)malloc(sizeof(struct Node));

  //verificar se a stack esta cheia“out-of-memory”
  if (!temp) {
    printf("\nStack sobrelotada");
  }

  //introduzir os dados no respetivo campo em temp
  temp->data = data;

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
int peek()
{
  //verificar se esta vazia
  if (!isEmpty(top))
    return top->estado;
  else
    return NULL;
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
    free(temp);}
  }
//Mostrar o conteudo da stack
void display(){
  struct Node* temp;
  //verifica se esta vazia
  if (top == NULL) {
    printf("\nStack vazia");
  }
  else {
    temp = top;
    while (temp != NULL) {
      //imprime o valor do nodo
      printf("%d->", temp->data);

      //direciona o apontador para temp
      temp = temp->next;
    }
  }
}

ESTADO do_undo(ESTADO e)  //e toma o valor peek depois fazer pop -> UNDO
{
  e = peek();
  pop();
  return e;
}
