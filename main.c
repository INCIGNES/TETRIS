/*
    Jogo Tetris implementado em linguagem C.

    Para executar:
        > start programa.exe

    Autor: Gabriel Minusso Figueira
    Data: 28/08/2019

*/

#include "tetris.h"
#include "display.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    int KeyPressed=0;

    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while( KeyPressed != ESC){        
        gotoxy(0,0);

        //posicionar o @ no meio da tela
        matrix[posI][posJ] = '@';

        //mostro a matriz na tela
        printMatrix(matrix);

        //faça posição anterior do @ ser apagada
        matrix[posI][posJ] = ' ';
        
        //faço a posição da @ ir para a direita
        if(posI < (ROWS-1)) posI++;

        //lendo teclas

        KeyPressed = 0;
        if(kbhit()) KeyPressed = getch();
        if(KeyPressed==ARROWS) KeyPressed = getch();

        switch(KeyPressed){
            case A_KEY:
            case LEFT:           
                if(posJ>0) posJ--; 
                break;
            case D_KEY:
            case RIGHT:
                if(posJ<(COLUMNS-1)) posJ++; 
                break;
            
        }
    }

    system("pause");

    return 0;
}