#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "stack.h"
#include "bot.h"

//variáveis globais
ESTADO e = {0};
static int var = 1;

/**
 * @brief
 * @param e
 * @param linha
 * @return
 */
ESTADO commands(ESTADO e,char linha[])
{
  char *cmd1, *cmd2, *cmd3;
  int i=0; int a,b;

  while(linha[i]) {linha[i] = toupper(linha[i]); i++;}

  cmd1 = strtok(linha," ");
  cmd2 = strtok(NULL," ");
  cmd3 = strtok(NULL," ");

  switch (*cmd1) {

    case 'N':
      if(cmd2) {
        //inicializa tabuleiro
        for (i = 0; i < 8; i++)
          for (j = 0; j < 8; j++) e.grelha[i][j] = VAZIA;
        e.grelha[3][4] = VALOR_X;
        e.grelha[4][3] = VALOR_X;
        e.grelha[3][3] = VALOR_O;
        e.grelha[4][4] = VALOR_O;

        if(*cmd2 == 'O') {
            e.modo = '0';
            clean();
            var = 0;
            e.peca = VALOR_O;
            printf("\n");
            printa(e,1,1);
            printf("\n");
            push(e); }
        else if (*cmd2 == 'X') {
            e.modo = '0';
            clean();
            var = 0;
            e.peca = VALOR_X;
            printf("\n");
            printa(e,1,1);
            printf("\n");
            push(e); }
        else printf("Comando inválido\n");}
      else printf("Comando inválido\n");
      break;

    case 'L':
      if(cmd2) {e = leFicheiro(e,cmd2); var = 0;}
      else printf("Comando inválido\n");
      break;

    case 'E':
      if(cmd2) {
        if(var==0) printE(e,cmd2); }
      else printf("Comando inválido\n");
      break;

    case 'J':
      if(listAS(e) == 0) {printf("Não existem jogadas válidas\n"); jogada(e,0,0);}
      else if(cmd2 && cmd3) {
          a = atoi(cmd2); b = atoi(cmd3);
          if(var==0) jogada(e,a,b); }
      else printf("Comando inválido\n");
      break;

    case 'S':
      if(var==0) printa(e,0,1);
      break;

    case 'H':
      if(var==0) printa(e,1,0);
      break;

    case 'U':
      if(var==0) e = do_undo(e);
      break;

    case 'A':
      if(cmd2 && cmd3) e.modo = '1';
        //if(var==0) bot(e,cmd2);
      else printf("Comando inválido\n");
      break;

    case 'Q':
      exit(0);

    default:
      printf("Comando inválido\n");
      break;
  }
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
  printf("-> Q : sair do jogo\n");
}

int main()
{
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
