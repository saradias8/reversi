#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "stack.h"
#include "bot.h"

/**
 * @brief Verifica as posições onde o jogador atual pode jogar.
 * @param e estado atual do jogo
 * @param line linha da posição a verificar
 * @param column coluna da posição a verificar
 * @return retorna VALOR POSSIBLE se o jogador puder jogar na posição recebida
 */
VALOR pecas(ESTADO e, int line, int column)
{
  int i,j,t=0;
  VALOR r = VAZIA;

  if(e.grelha[line][column] == VAZIA) {

    if(e.peca == VALOR_O) { // jogador O
      //linha direita
      for (j = column+1; j < 8; j++) {
        if(e.grelha[line][j] == VALOR_X) t++;
        else if(e.grelha[line][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
        else break;
      }
      t=0;
      //linha esquerda
      for (j = column-1; j >= 0; j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[line][j] == VALOR_X) t++;
          else if(e.grelha[line][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //coluna baixo
      for (i = line+1; i < 8; i++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][column] == VALOR_X) t++;
          else if(e.grelha[i][column] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //coluna cima
      for (i = line-1; i >= 0; i--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][column] == VALOR_X) t++;
          else if(e.grelha[i][column] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //diagonal inferior direita
      for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //diagonal superior esquerda
      for (i = line-1, j = column-1; i >= 0, j >= 0; i--, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE;break;}
          else break;
        }
      }
      t=0;
      for (i = line+1, j = column-1; i < 8, j >= 0; i++, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //diagonal superior direita
      for (i = line-1, j = column+1; i >= 0, j < 8; i--, j++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      return r;
    }
    else { // jogador X

      for (j = column+1; j < 8; j++) {
        if(e.grelha[line][j] == VALOR_O) t++;
        else if(e.grelha[line][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
        else break;
      }
      t=0;
      for (j = column-1; j >= 0; j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[line][j] == VALOR_O) t++;
          else if(e.grelha[line][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line+1; i < 8; i++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][column] == VALOR_O) t++;
          else if(e.grelha[i][column] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line-1; i >= 0; i--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][column] == VALOR_O) t++;
          else if(e.grelha[i][column] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line-1, j = column-1; i >= 0, j >= 0; i--, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line+1, j = column-1; i < 8, j >= 0; i++, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line-1, j = column+1; i >= 0, j < 8; i--, j++) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
    return r;
    }
  }
}

/**
 * @brief Dá a lista de posições onde o jogador atual pode jogar.
 * @param e estado atual do jogo
 * @return comprimento da lista das posições possíveis
 */
int listAS(ESTADO e)
{
  int c = 0; int i,j;
  char line[2],column[10];

  for(i=0;i<8;i++)
    for (j=0;j<8;j++) {
      if (pecas(e,i,j)==POSSIBLE) {
        sprintf(line, "%d", i);
        sprintf(column, "%d", j);
        strcat(line,column);
        string[c] = line;
        c++;
      }
    }
  return c;
}

/**
 * @brief Imprime o estado atual do jogo: tabuleiro, próximo jogador a jogar e as pontuações dos jogadores.
 * @param e estado atual do jogo
 * @param m variável que determina se foi executado o comando 'S'
 * @param n variável que determina se foi executado o comando 'H'
 */
void printa(ESTADO e, int m, int n)
{
  char c = ' '; int i,j, p = 0;

  if(e.peca == VALOR_O)
    printf("\nVez do jogador O\n\n");
  else printf("\nVez do jogador X\n\n");

  printf("  1 2 3 4 5 6 7 8 \n");
  for (i = 0; i < 8; i++) {
    printf("%d ",(i+1));
    for (j = 0; j < 8; j++) {
      if(e.grelha[i][j] == VALOR_O)      c = 'O';
      else if(e.grelha[i][j] == VALOR_X) c = 'X';
      else if(m == 0 && pecas(e,i,j) == POSSIBLE)  c = '.';
      else if(n == 0 && pecas(e,i,j) == POSSIBLE && p == 0) {c = '?'; p = 1;}
      else if(e.grelha[i][j] == VAZIA)   c = '-';
      printf("%c ", c);
    }
    printf("\n");
  }
  printf("\n");
  printf("Score O: %d\n", scoreO(e));
  printf("Score X: %d\n", scoreX(e));
  printf("\n");
}

/**
 * @brief Imprime num ficheiro o estado atual do jogo.
 * @param e estado atual do jogo
 * @param cmd2 nome do ficheiro escolhido pelo utilizador
 */
void printE(ESTADO e, char* cmd2)
{
    char c = ' '; int i,j;
    FILE *tab;
    tab = fopen(cmd2,"w");

    if(e.modo == '0') fprintf(tab,"M ");
    else fprintf(tab,"A ");

    if(e.peca == VALOR_O && e.modo == '0') fprintf(tab,"O\n");
    else if(e.peca == VALOR_X && e.modo == '0') fprintf(tab,"X\n");
    else if(e.peca == VALOR_O && e.modo == '1') fprintf(tab,"O ");
    else fprintf(tab,"X ");

    if(e.nivel == 1) fprintf(tab,"1\n");
    else if(e.nivel == 2) fprintf(tab,"2\n");
    else if(e.nivel == 3) fprintf(tab,"3\n");

    if(e.peca == VALOR_O) printf("\nVez do jogador O\n\n");
    else printf("\nVez do jogador X\n\n");

    printf("  1 2 3 4 5 6 7 8 \n");
    for (i = 0; i < 8; i++) {
      printf("%d ",(i+1));
      for (j = 0; j < 8; j++) {
        if(e.grelha[i][j] == VALOR_O)      c = 'O';
        else if(e.grelha[i][j] == VALOR_X) c = 'X';
        else if(e.grelha[i][j] == VAZIA)   c = '-';
        fprintf(tab,"%c ",c);
        printf("%c ", c);
      }
      fprintf(tab,"\n");
      printf("\n");
    }
    printf("\n");
    printf("Score O: %d\n", scoreO(e));
    printf("Score X: %d\n", scoreX(e));
    printf("\n");

    fclose(tab);
}

/**
 * @brief Devolve a pontuação do jogador O.
 * @param e estado atual do jogo
 * @return pontuação do jogador O
 */
int scoreO(ESTADO e)
{
  int conta = 0; int i,j;
    for(i=0;i<8;i++)
      for(j=0;j<8;j++) if(e.grelha[i][j] == VALOR_O) conta++;
  return conta;
}

/**
 * @brief Devolve a pontuação do jogador X.
 * @param e estado atual do jogo
 * @return pontuação do jogador X
 */
int scoreX(ESTADO e)
{
  int conta = 0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++) if(e.grelha[i][j] == VALOR_X) conta++;
  return conta;
}

/**
 * @brief Verifica se o tabuleiro do jogo se encontra preenchido.
 * @param e estado atual do jogo
 * @return valor 0 se estiver preenchido
 */
int cheio(ESTADO e)
{
  int r=0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++) if(e.grelha[i][j] == VAZIA) {r++; break;}
  return r;
}

/**
 * @brief Imprime uma mensagem a anunciar o vencedor do jogo atual.
 * @param e estado atual do jogo
 */
void endGame (ESTADO e)
{
  if(scoreO(e) > scoreX(e)) printf("O vencedor é o Jogador O!\n");
  else if (scoreO(e) < scoreX(e)) printf("O vencedor é o Jogador X!\n");
  else printf("Empataram... SMH\n");
}

/**
 * @brief Preenche os campos do tabuleiro depois de efetuada uma jogada.
 * @param e estado atual do jogo
 * @param line linha da posição escolhida pelo jogador
 * @param column coluna da posição escolhida pelo jogador
 * @return estado atualizado com a jogada
 */
ESTADO preenche(ESTADO e, int line, int column)
{
  int x = 0, y1 = 0, y2 = 0;

  if (e.peca == VALOR_O) {

    e.grelha[line][column] = VALOR_O;
    for (j = column+1; j < 8; j++) {
      if(e.grelha[line][j] == VALOR_X) x++;
      else if (e.grelha[line][j] == VALOR_O && x>0) {
        for (y2 = (j-1); y2>column; y2--) e.grelha[line][y2] = VALOR_O;
        break;
      }
      else break;
    }
    x=0;
    for (j = column-1; j >= 0; j--) {
      if(e.grelha[line][j] == VALOR_X) x++;
      else if (e.grelha[line][j] == VALOR_O && x>0) {
        for (y2 = (j+1); y2<column; y2++) e.grelha[line][y2] = VALOR_O;
        break;
      }
      else break;
    }
    x=0;
    for (i = line+1; i < 8; i++) {
      if(e.grelha[i][column] == VALOR_X) x++;
      else if (e.grelha[i][column] == VALOR_O && x>0) {
        for (y1 = (i-1); y1>line; y1--) e.grelha[y1][column] = VALOR_O;
        break;
      }
      else break;
    }
    x=0;
    for (i = line-1; i >= 0; i--) {
      if(e.grelha[i][column] == VALOR_X) x++;
      else if (e.grelha[i][column] == VALOR_O && x>0) {
        for (y1 = (i+1); y1<line; y1++) e.grelha[y1][column] = VALOR_O;
        break;
    }
      else break;
    }
    x=0;
    for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
      if(e.grelha[i][j] == VALOR_X) x++;
      else if (e.grelha[i][j] == VALOR_O && x>0) {
        for (y1 = (i-1), y2 = (j-1); y1>line, y2>column; y1--, y2--) e.grelha[y1][y2] = VALOR_O;
        break;
    }
      else break;
    }
    x=0;
    for (i = line-1, j = column-1; i >= 0, j >= 0; i--, j--) {
      if(e.grelha[i][j] == VALOR_X) x++;
      else if (e.grelha[i][j] == VALOR_O && x>0) {
        for (y1 = (i+1), y2 = (j+1); y1<line, y2<column; y1++, y2++) e.grelha[y1][y2] = VALOR_O;
        break;
    }
      else break;
    }
    x=0;
    for (i = line+1, j = column-1; i < 8, j >= 0; i++, j--) {
      if(e.grelha[i][j] == VALOR_X) x++;
      else if (e.grelha[i][j] == VALOR_O && x>0) {
        for (y1 = (i-1), y2 = (j+1); y1>line, y2<column; y1--, y2++) e.grelha[y1][y2] = VALOR_O;
        break;
    }
      else break;
    }
    x=0;
    for (i = line-1, j = column+1; i >= 0, j < 8; i--, j++) {
      if(e.grelha[i][j] == VALOR_X) x++;
      else if (e.grelha[i][j] == VALOR_O && x>0) {
        for (y1 = (i+1), y2 = (j-1); y1<line, y2>column; y1++, y2--) e.grelha[y1][y2] = VALOR_O;
        break;
    }
      else break;
    }
  }
  else {
    e.grelha[line][column] = VALOR_X;

    for (j = column+1; j < 8; j++) {
      if(e.grelha[line][j] == VALOR_O) x++;
      else if (e.grelha[line][j] == VALOR_X && x>0) {
        for (y2 = (j-1); y2>column; y2--) e.grelha[line][y2] = VALOR_X;
        break;
      }
      else break;
    }
    x=0;
    for (j = column-1; j >= 0; j--) {
      if(e.grelha[line][j] == VALOR_O) x++;
      else if (e.grelha[line][j] == VALOR_X && x>0) {
        for (y2 = (j+1); y2<column; y2++) e.grelha[line][y2] = VALOR_X;
        break;
      }
      else break;
    }
    x=0;
    for (i = line+1; i < 8; i++) {
      if(e.grelha[i][column] == VALOR_O) x++;
      else if (e.grelha[i][column] == VALOR_X && x>0) {
        for (y1 = (i-1); y1>line; y1--) e.grelha[y1][column] = VALOR_X;
        break;
      }
      else break;
    }
    x=0;
    for (i = line-1; i >= 0; i--) {
      if(e.grelha[i][column] == VALOR_O) x++;
      else if (e.grelha[i][column] == VALOR_X && x>0) {
        for (y1 = (i+1); y1<line; y1++) e.grelha[y1][column] = VALOR_X;
        break;
    }
      else break;
    }
    x=0;
    for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
      if(e.grelha[i][j] == VALOR_O) x++;
      else if (e.grelha[i][j] == VALOR_X && x>0) {
        for (y1 = (i-1), y2 = (j-1); y1>line, y2>column; y1--, y2--) e.grelha[y1][y2] = VALOR_X;
        break;
    }
      else break;
    }
    x=0;
    for (i = line-1, j = column-1; i >= 0, j >= 0; i--, j--) {
      if(e.grelha[i][j] == VALOR_O) x++;
      else if (e.grelha[i][j] == VALOR_X && x>0) {
        for (y1 = (i+1), y2 = (j+1); y1<line, y2<column; y1++, y2++) e.grelha[y1][y2] = VALOR_X;
        break;
    }
      else break;
    }
    x=0;
    for (i = line+1, j = column-1; i < 8, j >= 0; i++, j--) {
      if(e.grelha[i][j] == VALOR_O) x++;
      else if (e.grelha[i][j] == VALOR_X && x>0) {
        for (y1 = (i-1), y2 = (j+1); y1>line, y2<column; y1--, y2++) e.grelha[y1][y2] = VALOR_X;
        break;
    }
      else break;
    }
    x=0;
    for (i = line-1, j = column+1; i >= 0, j < 8; i--, j++) {
      if(e.grelha[i][j] == VALOR_O) x++;
      else if (e.grelha[i][j] == VALOR_X && x>0) {
        for (y1 = (i+1), y2 = (j-1); y1<line, y2>column; y1++, y2--) e.grelha[y1][y2] = VALOR_X;
        break;
    }
      else break;
    }
  }
  return e;
}

/**
 * @brief Lê a jogada do jogador atual: verifica se é válida e se há situação de fim de jogo.
 * @param e estado atual do jogo
 * @param line linha da posição escolhida pelo jogador
 * @param column coluna da posição escolhida pelo jogador
 * @return estado atualizado com a jogada
 */
ESTADO jogada(ESTADO e, int line, int column)
{
  char c; variavel = 0;
  line--; column--;

  if(listAS(e) > 0)
  {
    if(pecas(e,line,column) == POSSIBLE && line<8 && column<8)
    {
      tpm=0;
      e = preenche(e,line,column);
      if(e.peca == VALOR_O) {e.peca = VALOR_X;}
      else {e.peca = VALOR_O;}
      push(e);
      printa(e,1,1);
      if(e.peca == VALOR_O) c = 'O';
      else c = 'X';
      if(listAS(e) == 0)
      {
        variavel = 1;
        printf("Não existem jogadas válidas para o jogador %c\n",c);
        if(e.peca == VALOR_O) e.peca = VALOR_X;
        else e.peca = VALOR_O;
        if(e.modo == '0') printa(e,1,1);
      }
      if (e.modo == '1' && e.nivel == 1)
      {
        if(variavel == 1) {
          if(e.peca == VALOR_O) e.peca = VALOR_X;
          else e.peca = VALOR_O;
        }
        botN1(e);
      }
      else if (e.modo == '1' && e.nivel == 2)
      {
        if(variavel == 1) {
          if(e.peca == VALOR_O) e.peca = VALOR_X;
          else e.peca = VALOR_O;
        }
        botN2(e);
      }
    }
    else {
      printf("Jogada inválida.\n");
      printa(e,1,1);
    }
  }
  else
  {
    if(e.peca == VALOR_O) c = 'O';
    else c = 'X';
    printf("Não existem jogadas válidas para o jogador %c\n",c);
    tpm++;
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
    if (tpm > 1) endGame(e);
    else printa(e,1,1);
  }

  if(cheio(e) == 0) endGame(e);
  if(scoreO(e) == 0 || scoreX(e) == 0)
  {
    if(scoreO(e) == 0) printf("Não existem jogadas válidas para o jogador O\n");
    else if(scoreX(e) == 0) printf("Não existem jogadas válidas para o jogador X\n");
    endGame(e);
  }
  interpretador(e);
  return e;
}

/**
 * @brief Lê um ficheiro de jogo e substitui o jogo atual pelo lido no ficheiro
 * @param e estado atual do jogo
 * @param cmd2 nome do ficheiro escolhido pelo utilizador
 * @return estado substituído pelo estado do jogo no ficheiro
 */
ESTADO leFicheiro(ESTADO e,char *cmd2)
{
  char mode,peca,level; int c,i=0,j=0;
  FILE *file;
  file = fopen(cmd2,"r+");

  fscanf(file,"%c %c %c",&mode,&peca,&level);

  if(mode == 'M') {e.modo = '0'; printf("\nModo de Jogo Manual\n");}
  else {e.modo = '1';printf("\nModo de Jogo Automático\nBot de nível %c\n",level);}

  if(peca == 'O') e.peca = VALOR_O;
  else e.peca = VALOR_X;

  if(level == '1') e.nivel = 1;
  else if(level == '2') e.nivel = 2;
  else if(level == '3') e.nivel = 3;

  printf("\nVez do Jogador %c\n\n",peca);

  if(e.modo == '0') fseek(file,4,SEEK_SET);
  else fseek(file,6,SEEK_SET);

  printf("  1 2 3 4 5 6 7 8\n");
  printf("1 ");
  while((c = fgetc(file)) != EOF) {
      if(c == 'X') {e.grelha[i][j] = VALOR_X; j++; printf("%c ",c);}
      else if(c == 'O') {e.grelha[i][j] = VALOR_O; j++; printf("%c ",c);}
      else if(c == '-') {e.grelha[i][j] = VAZIA; j++; printf("%c ",c);}
      else if(c == '\n') {
        i++;
        if(i<8) printf("\n%d ",i+1);
        j=0;
      }
  }
  printf("\n\n");
  printf("Score O: %d\n", scoreO(e));
  printf("Score X: %d\n", scoreX(e));
  printf("\n");

  fclose(file);
  return e;
}
