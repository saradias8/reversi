#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "stack.h"

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
// variável global -> lista de posições possíveis
char* string[MAX];
//função que dá a lista de posições onde o jogador atual pode jogar
char* listAS(ESTADO e)
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
  return *string;
}

// função que imprime estado do jogo
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

//funcao que guarda estado em ficheiro
void printE(ESTADO e, char* cmd2)
{
    char c = ' '; int i,j;
    FILE *tab;
    tab = fopen(cmd2,"w");

    if(e.modo == '0') fprintf(tab,"M ");
    else fprintf(tab,"A ");

    if(e.peca == VALOR_O) fprintf(tab,"O\n");
    else fprintf(tab,"X\n");

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

//score do jogador O
int scoreO(ESTADO e)
{
  int conta = 0; int i,j;
    for(i=0;i<8;i++)
      for(j=0;j<8;j++) if(e.grelha[i][j] == VALOR_O) conta++;
  return conta;
}

//score do jogador X
int scoreX(ESTADO e)
{
  int conta = 0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++) if(e.grelha[i][j] == VALOR_X) conta++;
  return conta;
}

//verifica se o tabuleiro está todo preenchido
int cheio(ESTADO e)
{
  int r=0; int i,j;
  for(i=0;i<8;i++)
    for(j=0;j<8;j++) if(e.grelha[i][j] == VAZIA) {r++; break;}
  return r;
}

void endGame (ESTADO e)
{
  if(scoreO(e) > scoreX(e)) printf("O vencedor é o Jogador O!\n");
  else if (scoreO(e) < scoreX(e)) printf("O vencedor é o Jogador X!\n");
  else printf("Empataram... SMH\n");
}
//variável global
static int tpm=0;

// atualiza as peças do tabuleiro quando é efetuada uma jogada
ESTADO preenche(ESTADO e, int line, int column) //ERRO !!!
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
    x=0;
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

//função que lê a jogada e verifica se é válida
ESTADO jogada(ESTADO e, int line, int column)
{
  line--;column--;

  if(strlen(listAS(e)) > 0) {
    if(pecas(e,line,column) == POSSIBLE && line<8 && column<8) {
      tpm=0;
      e = preenche(e,line,column);
      if(e.peca == VALOR_O) {e.peca = VALOR_X;}
      else {e.peca = VALOR_O;}
      push(e);
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

ESTADO leFicheiro(ESTADO e,char *cmd2)
{
  char mode,peca,level; int c,i=0,j=0;
  FILE *file;
  file = fopen(cmd2,"r+");

  fscanf(file,"%c %c %c",&mode,&peca,&level);

  if(mode == 'M') e.modo = '0';
  else e.modo = '1';

  if(peca == 'O') e.peca = VALOR_O;
  else e.peca = VALOR_X;

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
