#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include "estado.h"
#include "stack.h"
#include "bot.h"

ESTADO e = {0};
static int var=1;
pid_t getppid(void);

/**
 * @brief Executa o input do utilizador.
 * @param e estado atual do jogo
 * @param linha input do utilizador
 * @return ESTADO depois de comando executado
 */
ESTADO commands(ESTADO e,char linha[],int* var)
{
  char *cmd1, *cmd2, *cmd3;
  int i=0,a,b;

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

        if(*cmd2 == 'O' || *cmd2 == 'X') {
            e.modo = '0';
            e.nivel = 0;
            clean();
            *var = 0;
            if (*cmd2 == 'O') e.peca = VALOR_O;
            else e.peca = VALOR_X;
            printa(e,1,1);
            push(e);
        }
        else {
          printf("Comando inválido\n");
          *var = 1;
        }
      }
      else {
        printf("Comando inválido\n");
        *var = 1;
      }
      break;

    case 'L':
      if(cmd2){
        clean();
        e = leFicheiro(e,cmd2,var);
        *var = 0;
      }
      else printf("Comando inválido\n");
      break;

    case 'E':
      if(cmd2) {
        if(*var==0) printE(e,cmd2);
        else printf("É necessário iniciar um jogo primeiro.\n");
      }
      else {
          printf("Comando inválido\n");
          *var = 1;
      }
      break;

    case 'J':
      if(*var==0) if(listAS(e) == 0) jogada(e,0,0,var);
      if(cmd2 && cmd3) {
          a = atoi(cmd2); b = atoi(cmd3);
          if(*var==0) jogada(e,a,b,var);
          else printf("É necessário iniciar um jogo primeiro.\n");
      }
      else printf("Comando inválido\n");
      break;

    case 'S':
      if(*var==0) printa(e,0,1);
      else printf("É necessário iniciar um jogo primeiro.\n");
      break;

    case 'H':
      if(*var==0) printa(e,1,0);
      else printf("É necessário iniciar um jogo primeiro.\n");
      break;

    case 'U':
      if(*var==0) e = do_undo(e);
      else printf("É necessário iniciar um jogo primeiro.\n");
      break;

    case 'A':
      if(cmd2 && cmd3) {
        clean();
        e.modo = '1';

        while(cmd2[i]) {cmd2[i] = toupper(cmd2[i]); i++;}

        e = iniciaE(e);

        if(*cmd2 == 'O') e.peca = VALOR_O;
        else if(*cmd2 == 'X') e.peca = VALOR_X;
        else printf("Comando inválido\n\n");

        if(*cmd3 == '2') {
          if(e.peca == VALOR_X) printa(e,1,1);
          *var = 0;
          e.nivel = 2;
          if(e.peca == VALOR_X) botN2(e);
          else {e.peca = VALOR_X; push(e); printa(e,1,1);}
        }
        else if(*cmd3 == '1') {
          if(e.peca == VALOR_X) printa(e,1,1);
          *var = 0;
          e.nivel = 1;
          if(e.peca == VALOR_X) botN1(e);
          else {e.peca = VALOR_X; push(e); printa(e,1,1);}
        }
        else if(*cmd3 == '3') {
          if(e.peca == VALOR_X) printa(e,1,1);
          *var = 0;
          e.nivel = 3;
          if(e.peca == VALOR_X) botN3(e,0);
          else {e.peca = VALOR_X; push(e); printa(e,1,1);}
        }
      } else {
        printf("Comando inválido\n");
        *var = 1;
        }
      break;

    case 'C':
      if(cmd2){
        clean();
        *var = 0;
        e = campeonato(e,cmd2,var);
      }
      else printf("Comando inválido\n");
      break;

    case 'Q':
      printf("Até à próxima!\n");
      exit(0);
      //kill(getppid(),SIGQUIT);

    default:
      printf("Comando inválido\n");
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

  if(fimJogo(e,&var)==0) var = 1;

  printf("Reversi > ");
  while(fgets(linha,MAX,stdin)){
    e = commands(e,linha,&var);
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
  printf("-> C <ficheiro> : começar um campeonato\n");
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
