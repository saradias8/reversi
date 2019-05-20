#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "stack.h"
#include "bot.h"

/**
 * @brief Efetua a jogada do bot.
 * @param e estado atual do jogo
 * @param line linha da posição recebida pelo bot
 * @param column coluna da posição recebida pelo bot
 * @return estado atualizado com a jogada do bot
 */
ESTADO jogadabot(ESTADO e, int line, int column)
{
  char c = 'X';
  if(e.peca == VALOR_O) c = 'O';

  if(listAS(e) > 0 && e.grelha[line][column] == VAZIA)
  {
    e = preenche(e,line,column);
    printf("Posição da jogada do bot, peça %c: (%d,%d)\n",c,line+1,column+1);
    e = switchPeca(e);
  }
  else e = switchPeca(e);

  if(e.campeonato == 0) {
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

  jogadabot(e,i,j);
}

/**
 * @brief Função responsável pelas jogadas do bot de nível 2. Estratégia: é selecionada a posição que mais favorece a pontuação momentânea do bot.
 * @param e estado atual do jogo
 */
void botN2(ESTADO e)
{
  int i, j, maior = 0, y, l=0, c=0;
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
  jogadabot(e,l,c);
}

/**
 * @brief Função minmmax.
 * @param e estado atual do jogo
 * @param inicial peça do jogador inicial
 * @param opponent peça do jogador adversário
 * @param search profundidade da pesquisa de jogadas
 * @return posição da jogada do bot
 */
int minmaxmanny (ESTADO e, VALOR inicial, VALOR opponent, int search)
{
  ESTADO tmp;
  int val = 0, bestMove = -9999, x = 0, y = 0, i, j;

  if (search == 5) {
    if (inicial == VALOR_X) return(scoreX(e) - scoreO(e));
    else return(scoreO(e) - scoreX(e));
  }
  else if(listAS(e)==0) return -1;
  else {
    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        if(pecas(e,i,j) == POSSIBLE) {
            tmp = e; tmp = preenche(e,i,j);
            tmp.peca = e.peca == inicial ? opponent : inicial;

            val = minmaxmanny(tmp,inicial,opponent,search+1);

            if (e.peca == inicial && val > bestMove) {
                bestMove = val;
                x = i;
                y = j;
            }
            else if (bestMove == -9999 || val < bestMove) {
                bestMove = val;
                x = i;
                y = j;
            }
        }
    if (search == 0) return (x*10+y);
    else return bestMove;
  }
}

/**
 * @brief Função responsável pelas jogadas do bot de nível 3. Estratégia: minmax.
 * @param e estado atual do jogo
 * @param com variável de decisão que determina se o bot está a jogar em campeonato ou contra utilizador
 * @return estado atualizado com a jogada do bot
 */
ESTADO botN3(ESTADO e)
{
  int l = 0, c = 0, val;

  if (listAS(e) != 0) {
    if (e.peca == VALOR_O) val = minmaxmanny(e,e.peca,VALOR_X,0);
    else val = minmaxmanny(e,e.peca,VALOR_O,0);

    c = val % 10;
    l = (val - c) / 10;
  }
  e = jogadabot(e,l,c);
  return e;
}
