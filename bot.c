#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "stack.h"

/**
 * @brief Efetua a jogada do bot.
 * @param e estado atual do jogo
 * @param line linha da posição recebida pelo bot
 * @param column coluna da posição recebida pelo bot
 * @return estado atualizado com a jogada do bot
 */
ESTADO jogadabot(ESTADO e, int line, int column, int com)
{
  int c;
  line--;column--;

  if(e.peca == VALOR_O) c = 'O';
  else c = 'X';

  if(listAS(e) > 0)
  {
    e = preenche(e,line,column);
    printf("Posição da jogada do bot, peça %c: (%d,%d)\n",c,line+1,column+1);
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
  }
  else {
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
  }

  if(com == 0) {
    printa(e,1,1);
    interpretador(e);
  }

  return e;
}

/**
 * @brief Função responsável pelas jogadas do bot de nível 1. Estratégia: é selecionada aleatoriamente uma posição da lista de posições possíveis.
 * @param e estado atual do jogo.
 */
void botN1(ESTADO e)
{
  int i,j,n,k=0;
  int a[MAX];

  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      if(pecas(e,i,j) == POSSIBLE) {a[k] = i*10 + j; k++;}

  if(k>1) n = rand() % (k-1);
  else n = 0;

  j = a[n] % 10;
  i = (a[n] - j) / 10;

  jogadabot(e,i+1,j+1,0);
}

/**
 * @brief Função responsável pelas jogadas do bot de nível 2. Estratégia: é selecionada a posição que mais favorece a pontuação momentânea do bot.
 * @param e estado atual do jogo
 */
void botN2(ESTADO e)
{
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
              } else if (e.peca==VALOR_X) {
                  y =scoreX(tmp) - scoreX(e);
                  if (y>maior) {
                    maior = y;
                    l = i;
                    c = j;
                  }
                }
          }
  jogadabot(e,l+1,c+1,0);
}

int minimaxValue(ESTADO e, VALOR original, VALOR current, int search)
{
  if( search == 5 || fimJogo(e,0) == 0)
  {
    if(original == VALOR_O) return scoreO(e) - scoreX(e);
    else return scoreX(e) - scoreO(e);
  }

  VALOR opponent = VALOR_X;
  if(e.peca == VALOR_X) opponent = VALOR_O;

  if(listAS(e) == 0) return minimaxValue(e,original,opponent,search+1);
  else {
    int bestMove = -99999;
    if(original != current) bestMove = 99999;

    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        if(pecas(e,i,j) == POSSIBLE) {
          ESTADO tmp = e;
          tmp = preenche(e,i,j);
          int val = minimaxValue(e,original,opponent,search +1);

          if(original == current)
            if(val > bestMove) bestMove = val;
          else
            if(val < bestMove) bestMove = val;
        }
    return bestMove;
  }
  return -1;
}

int minmaxDecision (ESTADO e)
{
  int x,y;
  VALOR opponent = VALOR_X;
  if(e.peca == VALOR_X) opponent = VALOR_O;

  if(listAS(e) == 0) {x = -1; y = -1;}
  else {
    int bestMove = -99999;
    int bestX,bestY;

    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        if(pecas(e,i,j) == POSSIBLE) {
          ESTADO tmp = e;
          tmp = preenche(e,i,j);
          int val = minimaxValue(tmp,e.peca,opponent,1);

          if(val > bestMove){
            bestMove = val;
            bestX = i;
            bestY = j;
          }
        }
        x = bestX;
        y = bestY;
  }
  return (x*10 + y);
}

ESTADO botN3(ESTADO e, int com) //position strategy && ponctuation tree
{
  int i, j, maior = -80, y, l, c, val;
  ESTADO tmp; int tabu[8][8];

  val = minmaxDecision(e);

  c = val % 10;
  l = (val - c) / 10;

/* //tentar juntar os dois quando funcionar
  tabu[0][0] = 99; tabu[0][1] = -8; tabu[0][2] = 8; tabu[0][3] = 6; tabu[0][4] = 6; tabu[0][5] = 8; tabu[0][6] = -8; tabu[0][7] = 99;
  tabu[1][0] = -8; tabu[1][1] = -24; tabu[1][2] = -4; tabu[1][3] = -3; tabu[1][4] = -3; tabu[1][5] = -4; tabu[1][6] = -24; tabu[1][7] = -8;
  tabu[2][0] = 8; tabu[2][1] = -4; tabu[2][2] = 7; tabu[2][3] = 4; tabu[2][4] = 4; tabu[2][5] = 7; tabu[2][6] = -4; tabu[2][7] = 8;
  tabu[3][0] = 6; tabu[3][1] = -3; tabu[3][2] = 4; tabu[3][3] = 0; tabu[3][4] = 0; tabu[3][5] = 4; tabu[3][6] = -3; tabu[3][7] = 6;
  tabu[4][0] = 6; tabu[4][1] = -3; tabu[4][2] = 4; tabu[4][3] = 0; tabu[4][4] = 0; tabu[4][5] = 4; tabu[4][6] = -3; tabu[4][7] = 6;
  tabu[5][0] = 8; tabu[5][1] = -4; tabu[5][2] = 7; tabu[5][3] = 4; tabu[5][4] = 4; tabu[5][5] = 7; tabu[5][6] = -4; tabu[5][7] = 8;
  tabu[6][0] = -8; tabu[6][1] = -24; tabu[6][2] = -4; tabu[6][3] = -3; tabu[6][4] = -3; tabu[6][5] = -4; tabu[6][6] = -24; tabu[6][7] = -8;
  tabu[7][0] = 99; tabu[7][1] = -8; tabu[7][2] = 8; tabu[7][3] = 6; tabu[7][4] = 6; tabu[7][5] = 8; tabu[7][6] = -8; tabu[7][7] = 99;

  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if(pecas(e,i,j) == POSSIBLE)
        if (tabu[i][j]>maior) {
          maior = tabu[i][j];
          l = i;
          c = j;
        }
*/
  e = jogadabot(e,l+1,c+1,com);
  return e;
}
