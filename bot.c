#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "stack.h"

ESTADO jogadabot(ESTADO e, int line, int column)
{
  line--;column--;

  if(listAS(e) > 0) {
    if(pecas(e,line,column) == POSSIBLE && line<8 && column<8) {
      tpm=0;
      e = preenche(e,line,column);
      printf("Posição da jogada do bot: (%d,%d)\n",line+1,column+1);
      if(e.peca == VALOR_O) {e.peca = VALOR_X;}
      else {e.peca = VALOR_O;}
    }
    else printf("Jogada inválida.\n");
  }
  else {
    tpm++;
    //printf("Não existem jogadas válidas\n");
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
    if (tpm > 1) endGame(e);
  }
  printa(e,1,1);

  if(cheio(e) == 0) endGame(e);
  interpretador(e);
  return e;
}

void botN2(ESTADO e) {
  int i, j, maior = 0, y, l, c;
  ESTADO tmp;

  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if(pecas(e,i,j) == POSSIBLE)  {
        tmp = preenche(e,i,j);
        if (e.peca==VALOR_O) {
          y =scoreO(tmp) - scoreO(e);
          if (y>maior) {
            maior = y;
            l = i;
            c = j;
          }
        }
        else if (e.peca==VALOR_X) {
          y =scoreX(tmp) - scoreX(e);
          if (y>maior) {
            maior = y;
            l = i;
            c = j;
          }
        }
      }
  jogadabot(e,l+1,c+1);
}
