//
// Created by rubens on 07/10/23.
//

#include "Celulas/Celulas.h"
#include "InterfaceUsuario/InterfaceUsuario.h"

int main()
{
    int entrada;
    int fase = 0;
    int telaX, telaY; // coordenadas da tela atual
    int x, y; // coordenadas do plano cartesiano infinito do cursor
    int virtX, virtY; // variáveis cartesianas para a tela

    WINDOW* grade;
    WINDOW* barraEsquerda;
    WINDOW * barraInferior;

    ponteiroCelula* arvore = InitArvoreCelula();

    InitConwayGameOfLifeUI(&grade, &barraInferior, &barraEsquerda);

    getyx(grade, virtX, virtY); //coordenadas iniciais do cursor
    x = 0;
    y = 0;
    telaX = 0;
    telaY = 0;

    while(1)
    {
        AtualizaBarraEsquerda(barraEsquerda, grade, telaY, telaX, y, x);
        RefreshTodasasTelas(grade, barraInferior, barraEsquerda);

        if(fase == 0)
        {
            //fase do programa no qual a primeira geração pode ser colocada na grade
            entrada = (int)getch();
            if(entrada != ERR)
            {
                if(entrada == KEY_LEFT || entrada == KEY_RIGHT ||
                    entrada == KEY_UP || entrada == KEY_DOWN)
                    MoveCursor(barraEsquerda, grade, entrada, &y, &x);

                else if(entrada == ' ')
                {
                    entrada = winch(grade);
                    getyx(grade, virtY, virtX);

                    if(entrada == '+')
                    {
                        InsereCelula_Id(y, x, arvore);
                        mvwprintw(grade,virtY, virtX, "#");
                        wmove(grade, virtY, virtX);
                    }
                    else
                    {
                        DeletaCelula(GeraId(y, x), arvore);
                        mvwprintw(grade,virtY, virtX, "+");
                        wmove(grade, virtY, virtX);
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
