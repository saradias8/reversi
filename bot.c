#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
/*
ESTADO bot(ESTADO e, char *cmd2) {
  int i, j, x = 0, y, l, c, r;
  ESTADO tmp;
  if (*cmd2 == 'O') e.peca = VALOR_O;
  else if (*cmd2 == 'X') e.peca = VALOR_X;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if(pecas(e,i,j) == POSSIBLE)  {
        tmp = preenche(e,i,j);
        if (e.peca==VALOR_O) {
          y =scoreO(e) - scoreO(tmp);
          if (y>x) {
            x = y;
            l = i;
            c = j;
          }
        }
        else if (e.peca==VALOR_X) {
          y =scoreX(e) - scoreX(tmp);
          if (y>x) {
            x = y;
            r = tmp;
            l = i;
            c = j;
          }
        }
      }
    r = l * 10 + c;
  return r;
}*/
