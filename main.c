#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
/*
ESTADO commands(ESTADO e, char linha[])
{
  int n; char cmd[MAX];
  strcpy(cmd,linha);
  //n = fscanf(linha,"%s",cmd);
  switch (toupper(cmd[0])) {
    case "N O":
      printf("Ola");
      break;
    case 'Q':
      exit(0);
    default:
      printf("Comando inválido\n");
  }
  return e;
}*/

ESTADO commands(ESTADO e,char linha[])
{
  char *cmd1, *cmd2, *cmd3;
  int i=0; int a,b; static int t = 0;

  while(linha[i]) {linha[i] = toupper(linha[i]); i++;}

  cmd1 = strtok(linha," ");
  cmd2 = strtok(NULL," ");
  cmd3 = strtok(NULL," ");

  if(*cmd1 == 'N') {

    ESTADO e = {0};
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    if(*cmd2 == 'O') e.peca = VALOR_O;
    else e.peca = VALOR_X;

    printf("\n");
    printa(e);
    printf("\n");
  }
  else if(*cmd1 == 'L') {
    leFicheiro();
  }
  else if(*cmd1 == 'J') {
    a = atoi(cmd2); b = atoi(cmd3);
    printf("%d\n", e.peca);
    jogada(e,t,a,b);
  }
  else if(*cmd1 == 'S') printS(e);
  else if(*cmd1 == 'Q') exit(0);
  else printf("Comando inválido\n");

  return e;
}

void interpretador(ESTADO e)
{
  char linha[MAX];

  printf("Reversi > ");
  while(fgets(linha,MAX,stdin)){
    e = commands(e,linha);
    printf("Reversi > ");
  }
}

void menu()
{
  printf("-> N <peca> : começar novo jogo \n");
  printf("-> L <ficheiro> : ler um jogo do ficheiro\n");
  printf("-> E <ficheiro> : escrever estado do jogo no ficheiro\n");
  printf("-> J <L> <C> : jogar na posição (L,C)\n");
  printf("-> S : mostrar no tabuleiro jogadas possíveis \n");
  printf("-> H : receber sugestão de jogada\n");
  printf("-> U : desfazer última jogada\n");
  printf("-> A <peca> <nivel> : começar jogo com bot com peça <peca> e nível <nivel> (3 níveis disponíveis)\n");
}

int main()
{
    FILE *tab;
    tab = fopen("reversi.txt","r+");

    //estado inicial
    ESTADO e = {0};
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    menu();
    interpretador(e);

    return 0;
}
