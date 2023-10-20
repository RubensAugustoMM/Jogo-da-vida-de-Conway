//
// Created by rubens on 07/10/23.
//

#include "Celulas/Celulas.h"
#include "InterfaceUsuario/InterfaceUsuario.h"

int main()
{
    int entrada;
    int fase = 0;
    int x, y;

    WINDOW* grade;
    WINDOW* barraEsquerda;
    WINDOW * barraInferior;

    ponteiroCelula* arvore = InitArvoreCelula();

    InitConwayGameOfLifeUI(&grade, &barraInferior, &barraEsquerda);

    while(1)
    {
        RefreshTodasasTelas(grade, barraInferior, barraEsquerda);

        if(fase == 0)
        {
            //fase do programa no qual a primeira geração pode ser colocada na grade
            entrada = (int)getch();
            if(entrada != ERR)
            {
                if(entrada == KEY_LEFT || entrada == KEY_RIGHT ||
                    entrada == KEY_UP || entrada == KEY_DOWN)
                    MoveCursor(barraEsquerda, grade, entrada);

                else if(entrada == ' ')
                {
                    entrada = winch(grade);
                    getyx(grade, y, x);

                    if(entrada == '+')
                    {
                        InsereCelula(y, x, arvore);
                        wprintw(grade, "#");
                        wmove(grade, x-1, y);
                    }
                    else
                    {
                        DeletaCelula(GeraId(y, x), arvore);
                        wprintw(grade, "+");
                        wmove(grade, x-1, y);
                    }

                }
                else if(entrada == 's')
                    fase = 1;
            }
        }
        else
        {
            //fase do programa no qual novas gerações são criadas
            break; // para teste
        }

    }

    endwin();
    return 0;
}
