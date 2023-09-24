//
// Created by rubens on 15/09/23.
//
#include "InterfaceUsuario.h"

WINDOW *InitGrade(int maxY, int maxX)
{
    int alt = maxY - 2;
    WINDOW *grade;

    grade = newwin(alt, maxX, 0, 0);

    for(int i = 0; i <= maxY;i++)
    {
        wmove(grade,i, 0);
        whline(grade, '+', maxX);
    }
    refresh();
    wrefresh(grade);

    return  grade;
}

//inicializa a barra de informações na parte inferior da tela
WINDOW *InitBarraDeInformacoes(int maxY, int maxX)
{
    WINDOW *barraDeInformacoes;

    barraDeInformacoes = newwin(2, maxX, maxY-2, 0);
    wmove(barraDeInformacoes, 0, 0);
    whline(barraDeInformacoes,'=', maxX);

    refresh();
    wrefresh(barraDeInformacoes);

    return barraDeInformacoes;
}
//inicializa a interface do jogo
void InitConwayGameOfLifeUI(WINDOW** grade, WINDOW** barra)
{
    int maxY, maxX;

    initscr();
    noecho();
    raw();

    getmaxyx(stdscr, maxY, maxX);

    mvprintw( maxY/2, maxX/2,"!!REFRESH DADO NA STDSCR!!");

    *grade = InitGrade(maxY, maxX);
    *barra = InitBarraDeInformacoes(maxY, maxX);


}

int main()
{
    WINDOW *grade;
    WINDOW *barra;

    InitConwayGameOfLifeUI(&grade, &barra);

    getch();

    endwin();

    return 0;
}


/*
int main()
{
    int x, y;

    initscr();
    noecho();
    getmaxyx(stdscr, y, x);
    move(y/2, 0);
    hline('-', x);
    getch();

    endwin();

    return 0;
}
*/