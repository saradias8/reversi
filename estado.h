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
    int nivel; // nivel do bot
} ESTADO;

static int var = 1;
int i, l, j;
static int tpm=0;
static int variavel = 0;
char* string[MAX];

int listAS(ESTADO);
void printa(ESTADO,int,int);
void printE(ESTADO,char*);
ESTADO preenche(ESTADO,int,int);
ESTADO jogada(ESTADO,int,int,int*);
ESTADO leFicheiro(ESTADO,char*);
void interpretador(ESTADO);
VALOR pecas(ESTADO,int,int);
int scoreO(ESTADO);
int scoreX(ESTADO);
int cheio(ESTADO);
void endGame(ESTADO);

#endif //PROJ_ESTADO_H
