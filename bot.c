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
ESTADO jogadabot(ESTADO e, int line, int column)
{
  int c;
  line--;column--;

  if(listAS(e) > 0)
  {
    if(pecas(e,line,column) == POSSIBLE && line<8 && column<8)
    {
      tpm=0;
      e = preenche(e,line,column);
      printf("Posição da jogada do bot: (%d,%d)\n",line+1,column+1);
      if(e.peca == VALOR_O) {e.peca = VALOR_X;}
      else {e.peca = VALOR_O;}
    }
    else printf("Jogada inválida.\n");
  }
  else
  {
    tpm++;
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
    if (tpm > 1) endGame(e);
  }
  printa(e,1,1);

  if(cheio(e) == 0) endGame(e);
  if(scoreO(e) == 0 || scoreX(e) == 0) endGame(e);

  interpretador(e);
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

  n = rand() % (k-1);
  j = a[n] % 10;
  i = (a[n] - j) / 10;

  jogadabot(e,i+1,j+1);
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
