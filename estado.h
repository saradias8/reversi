#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H
#define MAX 1024

/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/

// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O, POSSIBLE} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;

int line, column, i, j;

int listAS(ESTADO);
void printa(ESTADO,int,int);
ESTADO preenche(ESTADO,int,int);
ESTADO jogada(ESTADO,int,int);
ESTADO leFicheiro(char *);
void interpretador(ESTADO);
void printS();
void printE();

#endif //PROJ_ESTADO_H