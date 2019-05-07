#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "stack.h"
#include "bot.h"

ESTADO e = {0};

/**
 * @brief Inicializa tabuleiro
 * @param e estado atual do jogo
 * @return ESTADO inicializado
 */
ESTADO iniciaE(ESTADO e)
{
  for (l = 0; l < 8; l++)
    for (j = 0; j < 8; j++) e.grelha[l][j] = VAZIA;
  e.grelha[3][4] = VALOR_X;
  e.grelha[4][3] = VALOR_X;
  e.grelha[3][3] = VALOR_O;
  e.grelha[4][4] = VALOR_O;

  return e;
}

/**
 * @brief Executa o input do utilizador.
 * @param e estado atual do jogo
 * @param linha input do utilizador
 * @return ESTADO depois de comando executado
 */
ESTADO commands(ESTADO e,char linha[])
{
  char *cmd1, *cmd2, *cmd3;
  int i=0; int a,b;

  cmd1 = strtok(linha," ");
  cmd2 = strtok(NULL," ");
  cmd3 = strtok(NULL," ");

  while(cmd1[i]) {cmd1[i] = toupper(cmd1[i]); i++;}
  i=0;

  if(cmd2 && cmd3 == NULL) cmd2[strlen(cmd2)-1] = '\0';

  switch (*cmd1) {

    case 'N':
      if(cmd2) {
        while(cmd2[i]) {cmd2[i] = toupper(cmd2[i]); i++;}

        e = iniciaE(e);

        if(*cmd2 == 'O') {
            e.modo = '0';
            e.nivel = 0;
            clean();
            var = 0;
            e.peca = VALOR_O;
            printa(e,1,1);
            push(e);
        }
        else if (*cmd2 == 'X') {
            e.modo = '0';
            e.nivel = 0;
            clean();
            var = 0;
            e.peca = VALOR_X;
            printa(e,1,1);
            push(e);
        }
        else {
          printf("Comando inválido\n\n");
          var = 1;
        }
      }
      else {
        printf("Comando inválido\n\n");
        var = 1;
      }
      break;

    case 'L':
      if(cmd2){
        clean();
        e = leFicheiro(e,cmd2);
        var = 0;
      }
      else {
        printf("Comando inválido\n\n");
        var = 1;
      }
      break;

    case 'E':
      if(cmd2) {
        if(var==0) printE(e,cmd2); }
        else {
          printf("Comando inválido\n\n");
          var = 1;
        }
      break;

    case 'J':
      if(listAS(e) == 0) jogada(e,0,0,&var);
      else if(cmd2 && cmd3) {
          a = atoi(cmd2); b = atoi(cmd3);
          if(var==0) jogada(e,a,b,&var);
      }
      else {
        printf("Comando inválido\n\n");
        var = 1;
      }
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
      if(cmd2 && cmd3) {
        clean();
        e.modo = '1';

        while(cmd2[i]) {cmd2[i] = toupper(cmd2[i]); i++;}
        i=0;

        e = iniciaE(e);

        if(*cmd2 == 'O') e.peca = VALOR_O;
        else if(*cmd2 == 'X') e.peca = VALOR_X;
        else printf("Comando inválido\n\n");

        if(*cmd3 == '2' && e.peca == VALOR_X) {
          printa(e,1,1); push(e);
          var = 0;
          e.nivel = 2;
          e.modo = '1';
          botN2(e);
         }
        else if(*cmd3 == '2' && e.peca == VALOR_O) {
          var = 0;
          e.nivel = 2;
          e.peca = VALOR_X;
          e.modo = '1';
          printa(e,1,1);
        }
        else if(*cmd3 == '1' && e.peca == VALOR_O) {
          var = 0;
          e.nivel = 1;
          e.peca = VALOR_X;
          e.modo = '1';
          printa(e,1,1);
        }
        else if(*cmd3 == '1' && e.peca == VALOR_X) {
          printa(e,1,1); push(e);
          var = 0;
          e.nivel = 1;
          e.modo = '1';
          botN1(e);
          }
      } else {
        printf("Comando inválido\n\n");
        var = 1;
      }
      break;

    case 'Q':
      exit(0);

    default:
      printf("Comando inválido\n\n");
      break;
  }
  return e;
}

/**
 * @brief Recebe o input do utilizador.
 * @param e estado atual do jogo
 */
void interpretador(ESTADO e)
{
  char linha[MAX];

  printf("Reversi > ");
  while(fgets(linha,MAX,stdin)){
    e = commands(e,linha);
    printf("Reversi > ");
  }
}

/**
 * @brief Imprime as opções do menu.
 */
void menu()
{
  printf("\n-> N <peca> : começar novo jogo \n");
  printf("-> L <ficheiro> : ler um jogo do ficheiro\n");
  printf("-> E <ficheiro> : escrever estado do jogo no ficheiro\n");
  printf("-> J <L> <C> : jogar na posição (L,C)\n");
  printf("-> S : mostrar no tabuleiro jogadas possíveis \n");
  printf("-> H : receber sugestão de jogada\n");
  printf("-> U : desfazer última jogada\n");
  printf("-> A <peca> <nivel> : começar jogo com bot com peça <peca> e nível <nivel> (3 níveis disponíveis)\n");
  printf("-> Q : sair do jogo\n\n");
}

/**
 * @brief Função main.
 * @return exit code
 */
int main()
{
  e = iniciaE(e);

  menu();
  interpretador(e);

  return 0;
}
