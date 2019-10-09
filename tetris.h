/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Autor: Augusto Luengo Pereira Nunes
    Data: 28/08/2019

*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Configuração das dimensões da matriz principal do jogo
#define COLUMNS 60
#define ROWS 25

// Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define A_KEY 97
#define D_KEY 100

// Orientações para as peças

#define ORIENTACAO_UP 1
#define ORIENTACAO_DOWN 2
#define ORIENTACAO_LEFT 3
#define ORIENTACAO_RIGHT 4

// Tipos de peças

#define TIPO_L 1
#define TIPO_L_R 2  // L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5  // Z reverso
#define TIPO_O 6    // Quadrado
#define TIPO_I 7    

//configuraçoes de layout
#define PIXEL 219
#define EMPTY 32

// Estrutura padrao de componentes

typedef struct{
    int i;  // posição das linhas na matirz
    int j;  // posição das colunas na matriz
    int orientacao; // orientação da peça
    int tipo;   // tipo de peça (7 possiveis)
    int width;  // largura da peça
    int height; // altura da peça
    
}Bloco;




/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);