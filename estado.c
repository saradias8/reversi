#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"

//função que verifica as posições onde é possível jogar
VALOR pecas(ESTADO e, int line, int column)
{
  int i,j,t=0;
  VALOR r = VAZIA;

  if(e.grelha[line][column] == VAZIA) {

    if(e.peca == VALOR_O) { // jogador O
      //linha direita
      for (j = column+1; j < 8; j++) {
        if(e.grelha[line][j] == VALOR_X) t++;
        else if(e.grelha[line][j] == VALOR_O && t>0) {e.grelha[line][column]=3; r = POSSIBLE; break;}
        else break;
      }
      t=0;
      //linha esquerda
      for (j = column-1; j > 0; j--) {
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
      for (i = line-1; i > 0; i--) {
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
      for (i = line-1, j = column-1; i > 0, j > 0; i--, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE;break;}
          else break;
        }
      }
      t=0;
      for (i = line+1, j = column-1; i < 8, j > 0; i++, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_X) t++;
          else if(e.grelha[i][j] == VALOR_O && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      //diagonal superior direita
      for (i = line-1, j = column+1; i > 0, j < 8; i--, j++) {
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
      for (j = column-1; j > 0; j--) {
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
      for (i = line-1; i > 0; i--) {
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
      for (i = line-1, j = column-1; i > 0, j > 0; i--, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line+1, j = column-1; i < 8, j > 0; i++, j--) {
        if(r==POSSIBLE) break;
        else {
          if(e.grelha[i][j] == VALOR_O) t++;
          else if(e.grelha[i][j] == VALOR_X && t>0) {r = POSSIBLE; break;}
          else break;
        }
      }
      t=0;
      for (i = line-1, j = column+1; i > 0, j < 8; i--, j++) {
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
char* string[MAX];
//função que dá a lista de posições onde o jogador atual pode jogar
int listAS(ESTADO e)
{
  int c = 0; int i,j;
  char line[2]; char column[10];

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
    printf("\n");
  return c;
}

char* listAAAA(ESTADO e)
{
  int c = 0; int i,j;
  
  char line[2]; char column[10];

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
    printf("\n");
  return *string;
}

// função para imprimir o estado (Tabuleiro) na terminal e no ficheiro
void printa(ESTADO e)
{
    char c = ' '; int i,j;
    FILE *tab;
    tab = fopen("reversi.txt","w+");

    if(e.peca == VALOR_O)
      fprintf(tab,"O\n");
    else fprintf(tab,"X\n");

    if(e.peca == VALOR_O)
      printf("Vez do jogador O\n\n");
    else printf("Vez do jogador X\n\n");

    printf("  1 2 3 4 5 6 7 8 \n");
    for (i = 0; i < 8; i++) {
      printf("%d ",(i+1));
      for (j = 0; j < 8; j++) {
        if(e.grelha[i][j] == VALOR_O)      c = 'O';
        else if(e.grelha[i][j] == VALOR_X) c = 'X';
        //else if(pecas(e,i,j) == POSSIBLE)  c = '*';
        else if(e.grelha[i][j] == VAZIA)   c = '-';
        fprintf(tab,"%c ",c);
        printf("%c ", c);
      }
      fprintf(tab,"\n");
      printf("\n");
    }
    fclose(tab);
}

//score do jogador O
int scoreO(ESTADO e)
{
  int conta = 0; int i,j;
    for(i=0;i<8;i++)
      for(j=0;j<8;j++)
        if(e.grelha[i][j] == VALOR_O) conta++;
  return conta;
}

//score do jogador X
int scoreX(ESTADO e)
{
  int conta = 0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      if(e.grelha[i][j] == VALOR_X) conta++;
  return conta;
}

//função que verifica se o tabuleiro está todo preenchido
int cheio(ESTADO e)
{
  int r=0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++)
      if(e.grelha[i][j] == VAZIA) {r++; break;}
  return r;
}

void endGame (ESTADO e){
  if(scoreO(e) > scoreX(e)) printf("O vencedor é o Jogador O!\n");
  else if (scoreO(e) < scoreX(e)) printf("O vencedor é o Jogador X!\n");
  else printf("Empataram... SMH\n");
}

//função que lê a jogada e a executa se for válida
void jogada(ESTADO e, int t, int line, int column)
{
  int x = 0, y1 = 0, y2 = 0;
  int tpm=0;
  FILE *tab;
  tab = fopen("reversi.txt","w+");

  line--;column--;
  if(listAS(e) > 0) {

    if(pecas(e,line,column) == POSSIBLE && line<8 && column<8) {
      tpm=0;
      if (e.peca == VALOR_O) {
        e.grelha[line][column] = VALOR_O;
        for (j = column+1; j < 8; j++) {
          if(e.grelha[line][j] == VALOR_X) x++;
          else if (e.grelha[line][j] == VALOR_O && x>0) {
            for (y2 = (j-1); y2>column; y2--) e.grelha[line][y2] = VALOR_O;
          }
          else break;
        }
        x=0;
        for (j = column-1; j > 0; j--) {
          if(e.grelha[line][j] == VALOR_X) x++;
          else if (e.grelha[line][j] == VALOR_O && x>0) {
            for (y2 = (j+1); y2<column; y2++) e.grelha[line][y2] = VALOR_O;
          }
          else break;
        }
        x=0;
        for (i = line+1; i < 8; i++) {
          if(e.grelha[i][column] == VALOR_X) x++;
          else if (e.grelha[i][column] == VALOR_O && x>0) {
            for (y1 = (i-1); y1>line; y1--) e.grelha[y1][column] = VALOR_O;
          }
          else break;
        }
        x=0;
        for (i = line-1; i > 0; i--) {
          if(e.grelha[i][column] == VALOR_X) x++;
          else if (e.grelha[i][column] == VALOR_O && x>0) {
            for (y1 = (i+1); y1<line; y1++) e.grelha[y1][column] = VALOR_O;
        }
          else break;
        }
        x=0;
        for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
          if(e.grelha[i][j] == VALOR_X) x++;
          else if (e.grelha[i][j] == VALOR_O && x>0) {
            for (y1 = (i-1), y2 = (j-1); y1>line, y2>column; y1--, y2--) e.grelha[y1][y2] = VALOR_O;
        }
          else break;
        }
        x=0;
        for (i = line-1, j = column-1; i > 0, j > 0; i--, j--) {
          if(e.grelha[i][j] == VALOR_X) x++;
          else if (e.grelha[i][j] == VALOR_O && x>0) {
            for (y1 = (i+1), y2 = (j+1); y1<line, y2<column; y1++, y2++) e.grelha[y1][y2] = VALOR_O;
        }
          else break;
        }
        x=0;
        for (i = line+1, j = column-1; i < 8, j > 0; i++, j--) {
          if(e.grelha[i][j] == VALOR_X) x++;
          else if (e.grelha[i][j] == VALOR_O && x>0) {
            for (y1 = (i-1), y2 = (j+1); y1>line, y2<column; y1--, y2++) e.grelha[y1][y2] = VALOR_O;
        }
          else break;
        }
        x=0;
        for (i = line-1, j = column+1; i > 0, j < 8; i--, j++) {
          if(e.grelha[i][j] == VALOR_X) x++;
          else if (e.grelha[i][j] == VALOR_O && x>0) {
            for (y1 = (i+1), y2 = (j-1); y1<line, y2>column; y1++, y2--) e.grelha[y1][y2] = VALOR_O;
        }
          else break;
        }
        x=0;
      }
      else {
        e.grelha[line][column] = VALOR_X;
        for (j = column+1; j < 8; j++) {
          if(e.grelha[line][j] == VALOR_O) x++;
          else if (e.grelha[line][j] == VALOR_X && x>0) {
            for (y2 = (j-1); y2>column; y2--) e.grelha[line][y2] = VALOR_X;
          }
          else break;
        }
        x=0;
        for (j = column-1; j > 0; j--) {
          if(e.grelha[line][j] == VALOR_O) x++;
          else if (e.grelha[line][j] == VALOR_X && x>0) {
            for (y2 = (j+1); y2<column; y2++) e.grelha[line][y2] = VALOR_X;
          }
          else break;
        }
        x=0;
        for (i = line+1; i < 8; i++) {
          if(e.grelha[i][column] == VALOR_O) x++;
          else if (e.grelha[i][column] == VALOR_X && x>0) {
            for (y1 = (i-1); y1>line; y1--) e.grelha[y1][column] = VALOR_X;
          }
          else break;
        }
        x=0;
        for (i = line-1; i > 0; i--) {
          if(e.grelha[i][column] == VALOR_O) x++;
          else if (e.grelha[i][column] == VALOR_X && x>0) {
            for (y1 = (i+1); y1<line; y1++) e.grelha[y1][column] = VALOR_X;
        }
          else break;
        }
        x=0;
        for (i = line+1, j = column+1; i < 8, j < 8; i++, j++) {
          if(e.grelha[i][j] == VALOR_O) x++;
          else if (e.grelha[i][j] == VALOR_X && x>0) {
            for (y1 = (i-1), y2 = (j-1); y1>line, y2>column; y1--, y2--) e.grelha[y1][y2] = VALOR_X;
        }
          else break;
        }
        x=0;
        for (i = line-1, j = column-1; i > 0, j > 0; i--, j--) {
          if(e.grelha[i][j] == VALOR_O) x++;
          else if (e.grelha[i][j] == VALOR_X && x>0) {
            for (y1 = (i+1), y2 = (j+1); y1<line, y2<column; y1++, y2++) e.grelha[y1][y2] = VALOR_X;
        }
          else break;
        }
        x=0;
        for (i = line+1, j = column-1; i < 8, j > 0; i++, j--) {
          if(e.grelha[i][j] == VALOR_O) x++;
          else if (e.grelha[i][j] == VALOR_X && x>0) {
            for (y1 = (i-1), y2 = (j+1); y1>line, y2<column; y1--, y2++) e.grelha[y1][y2] = VALOR_X;
        }
          else break;
        }
        x=0;
        for (i = line-1, j = column+1; i > 0, j < 8; i--, j++) {
          if(e.grelha[i][j] == VALOR_O) x++;
          else if (e.grelha[i][j] == VALOR_X && x>0) {
            for (y1 = (i+1), y2 = (j-1); y1<line, y2>column; y1++, y2--) e.grelha[y1][y2] = VALOR_X;
        }
          else break;
        }
      }
      if(e.peca == VALOR_O) {e.peca = VALOR_X; }
      else{ e.peca = VALOR_O;}
    }
    else printf("Jogada inválida.\n");
  }
  else {
    tpm++;
    printf("Não existem jogadas válidas\n");
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else e.peca = VALOR_O;
    if (tpm > 1) endGame(e);
  }

  printf("\n");
  printa(e);
  printf("\n");

  printf("Score O: %d\n", scoreO(e));
  printf("Score X: %d\n", scoreX(e));
  printf("\n");

  if(cheio(e) == 0) endGame(e);
  interpretador(e);
}

void leFicheiro()
{
  char c;
  FILE *tab;
  tab = fopen("reversi.txt","r");

  while((c = fgetc(tab)) != EOF)
    printf("%c", c);

  fclose(tab);
}

int possible(int line,int column) // NAO FUNCIONA
{
  int i,l,c;
  char linha[2], coluna[2];

  sprintf(linha, "%d", line);
  sprintf(coluna, "%d", column);
  strcat(linha,coluna);

  for(i=0;string[i];i++) {
    if(linha == string[i]) return 0;
  }
  return 1;
}

void printS(ESTADO e)
{
  char c = ' '; int i,j;

  if(e.peca == VALOR_O)
    printf("Vez do jogador O\n\n");
  else printf("Vez do jogador X\n\n");

  printf("  1 2 3 4 5 6 7 8 \n");
  for (i = 0; i < 8; i++) {
    printf("%d ",(i+1));
    for (j = 0; j < 8; j++) {
      if(e.grelha[i][j] == VALOR_O)      c = 'O';
      else if(e.grelha[i][j] == VALOR_X) c = 'X';
      else if(possible(i,j) == 0)        c = '*';
      else if(e.grelha[i][j] == VAZIA)   c = '-';
      printf("%c ", c);
    }
    printf("\n");
  }
}
