/*
    Jogo Tetris implementado em linguagem C.

    Para executar:
        > start programa.exe

    Autor: Gabriel Minusso Figueira
    Data: 28/08/2019

*/

#include "tetris.h"
#include "display.h"
#define DEBUG 1

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int KeyPressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;


    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while( KeyPressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("@ = (%d, %d)\n", tijolo.i, tijolo.j);
        #endif
        //posicionar o @ no meio da tela
        matrix[tijolo.i][tijolo.j-4] =  PIXEL;
        matrix[tijolo.i][tijolo.j-3] =  PIXEL;
        matrix[tijolo.i][tijolo.j-2] =  PIXEL;
        matrix[tijolo.i][tijolo.j-1] =  PIXEL;
        matrix[tijolo.i][tijolo.j+0] =  PIXEL;
        matrix[tijolo.i][tijolo.j+1] =  PIXEL;
        matrix[tijolo.i][tijolo.j+2] =  PIXEL;
        matrix[tijolo.i][tijolo.j+3] =  PIXEL;
        matrix[tijolo.i][tijolo.j+4] =  PIXEL;


        //mostro a matriz na tela
        printMatrix(matrix);

        // faz posição anterior do @ ser apagada
        matrix[tijolo.i][tijolo.j-4] =  EMPTY;
        matrix[tijolo.i][tijolo.j-3] =  EMPTY;
        matrix[tijolo.i][tijolo.j-2] =  EMPTY;
        matrix[tijolo.i][tijolo.j-1] =  EMPTY;
        matrix[tijolo.i][tijolo.j+0] =  EMPTY;
        matrix[tijolo.i][tijolo.j+1] =  EMPTY;
        matrix[tijolo.i][tijolo.j+2] =  EMPTY;
        matrix[tijolo.i][tijolo.j+3] =  EMPTY;
        matrix[tijolo.i][tijolo.j+4] =  EMPTY;

        
        //faz a posição da @ ir para a direita
        if(tijolo.i < (ROWS-1)) tijolo.i++;

        //lendo teclas

        KeyPressed = 0;
        if(kbhit()) KeyPressed = getch();
        if(KeyPressed==ARROWS) KeyPressed = getch();

        switch(KeyPressed){
            case A_KEY:
            case LEFT:           
                if(tijolo.j>0) tijolo.j--; 
                break;
            case D_KEY:
            case RIGHT:
                if(tijolo.j<(COLUMNS-1)) tijolo.j++; 
                break;
            
        }
    }

    system("pause");

    return 0;
}