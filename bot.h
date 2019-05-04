#ifndef BOT_H
#define BOT_H

typedef struct nodo {
  int lin;
  int col;
  struct nodo *esq, *dir;
} *ABin;
void botN1(ESTADO);

#endif
