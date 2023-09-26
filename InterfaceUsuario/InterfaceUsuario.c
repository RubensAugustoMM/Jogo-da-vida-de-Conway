//
// Created by rubens on 15/09/23.
//
#include "InterfaceUsuario.h"

WINDOW *InitGrade(int maxY, int maxX)
{
    int alt = maxY - 6;
    int comp = maxX/2;

    WINDOW *grade;

    grade = newwin(alt, comp, 3, (maxX/2) - (comp/2));
    keypad(grade, true);

    for(int i = 0; i <= maxY;i++)
        mvwhline(grade, i, 0, '+', maxX);

    refresh();
    wrefresh(grade);

    return  grade;
}

//inicializa a barra de informações na parte inferior da tela
WINDOW *InitBarraDeInformacoesInferior(int maxY, int maxX)
{
    int comp = maxX - (maxX/2);

    WINDOW *barraDeInformacoes;

    barraDeInformacoes = newwin(3,comp, maxY-3, (maxX/2) - (comp/2) );

    mvwhline(barraDeInformacoes, 0, 0,'=', maxX);

    refresh();
    wrefresh(barraDeInformacoes);

    return barraDeInformacoes;
}

WINDOW *InitBarraDeInformacoesEsquerda(int maxY, int maxX)
{
    int comp = maxX/4;

    WINDOW *barraEsquerda = newwin(maxY, comp, 0, 0);

    mvwvline(barraEsquerda, 0, comp -1,'|', maxY );

    wrefresh(barraEsquerda);

    return barraEsquerda;
}

//inicializa a interface do jogo
void InitConwayGameOfLifeUI(WINDOW** grade, WINDOW** barraInferior, WINDOW** barraEsquerda)
{
    int maxY, maxX;

    initscr();
    noecho();
    raw();

    getmaxyx(stdscr, maxY, maxX);

    if(maxY < 36 || maxX < 36)
        printw("!!TERMINAL PEQUENO DEMAIS!!");
    else
    {
        *grade = InitGrade(maxY, maxX);
        *barraInferior = InitBarraDeInformacoesInferior(maxY, maxX);
        *barraEsquerda = InitBarraDeInformacoesEsquerda(maxY, maxX);

    }
}


int main()
{
    WINDOW *grade;
    WINDOW *barraInferior;
    WINDOW *barraEsquerda;

    InitConwayGameOfLifeUI(&grade, &barraInferior, &barraEsquerda);

    getch();

    endwin();

    return 0;
}


