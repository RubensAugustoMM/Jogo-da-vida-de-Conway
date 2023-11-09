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
    keypad(grade, TRUE);
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
    int winMaxY, winMaxX;

    WINDOW *barraEsquerda = newwin(maxY, comp, 0, 0);
    getmaxyx(barraEsquerda, winMaxY, winMaxX);

    mvwvline(barraEsquerda, 0, comp -1,'|', maxY );

    mvwprintw(barraEsquerda, 0, winMaxX/2, "Tela atual:");
    mvwprintw(barraEsquerda, 1, (winMaxX/2) + 3, "Y:");
    mvwprintw(barraEsquerda,2, (winMaxX/2) + 3, "x:");

    mvwprintw(barraEsquerda, 4, winMaxX/2, "Posicao plano:");
    mvwprintw(barraEsquerda, 5, (winMaxX/2) + 3, "Y:");
    mvwprintw(barraEsquerda,6, (winMaxX/2) + 3, "x:");

    mvwprintw(barraEsquerda, 8, winMaxX/2, "Posicao grade:");
    mvwprintw(barraEsquerda, 9, (winMaxX/2) + 3, "Y:");
    mvwprintw(barraEsquerda,10, (winMaxX/2) + 3, "x:");

    wrefresh(barraEsquerda);

    return barraEsquerda;
}

//inicializa a interface do jogo
void InitConwayGameOfLifeUI(WINDOW** grade, WINDOW** barraInferior, WINDOW** barraEsquerda)
{
    const int DELAY = 1000;
    int maxY, maxX;

    initscr();
    raw();
    noecho();
    timeout(DELAY);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, maxY, maxX);

    if(maxY < 36 || maxX < 36)
        printw("!!TERMINAL PEQUENO DEMAIS!!");
    else
    {
        *grade = InitGrade(maxY, maxX);
        *barraInferior = InitBarraDeInformacoesInferior(maxY, maxX);
        *barraEsquerda = InitBarraDeInformacoesEsquerda(maxY, maxX);

        getmaxyx(*grade, maxY, maxX);
        wmove(*grade, maxY/2, maxX/2);
    }
}

void MoveCursor(WINDOW* barraEsquerda,WINDOW* grade,ponteiroCelula* arvore,int dir,int* telaY, int* telaX, int* y, int* x)
{
    int virtY, virtX;
    int maxY, maxX;

    getyx(grade, virtY, virtX);
    getmaxyx(grade, maxY, maxX);

    switch (dir)
    {
        case KEY_UP:
            if(virtY - 1 < 0)
                ScrollWindow(barraEsquerda, grade,arvore, KEY_UP,telaY,telaX);
            else {
                wmove(grade, virtY - 1, virtX);
                (*y)++;
            }
            break;

        case KEY_DOWN:
            if(virtY + 2 > maxY)
                ScrollWindow(barraEsquerda, grade,arvore,KEY_DOWN,telaY,telaX);
            else {
                wmove(grade, virtY + 1, virtX);
                (*y)--;
            }
            break;

        case KEY_LEFT:
            if(virtX - 1 < 0)
                ScrollWindow(barraEsquerda, grade,arvore,KEY_LEFT, telaY, telaX);
            else {
                wmove(grade, virtY, virtX - 1);
                (*x)--;
            }
            break;

        case KEY_RIGHT:
            if(virtX + 2 > maxX)
                ScrollWindow(barraEsquerda, grade,arvore,KEY_RIGHT, telaY,telaX);
            else {
                wmove(grade, virtY, virtX + 1);
                (*x)++;
            }
            break;
    }
}


void AtualizaBarraEsquerda(WINDOW* barraEsquerda, WINDOW* grade, int winY, int winX, int curPosY, int curPosX)
{
    int virtX, virtY;
    int winMaxX, winMaxY;

    getyx(grade, virtY, virtX);
    getmaxyx(barraEsquerda, winMaxY, winMaxX);

    wclear(barraEsquerda);

    mvwvline(barraEsquerda, 0, winMaxX- 1,'|', winMaxY );

    mvwprintw(barraEsquerda, 0, winMaxX/2, "Tela atual:");
    mvwprintw(barraEsquerda, 1, (winMaxX/2) + 3, "Y:%d", winY);
    mvwprintw(barraEsquerda,2, (winMaxX/2) + 3, "x:%d", winX);

    mvwprintw(barraEsquerda, 4, winMaxX/2, "Posicao plano:");
    mvwprintw(barraEsquerda, 5, (winMaxX/2) + 3, "Y:%d", curPosY);
    mvwprintw(barraEsquerda,6, (winMaxX/2) + 3, "x:%d", curPosX);

    mvwprintw(barraEsquerda, 8, winMaxX/2, "Posicao grade:");
    mvwprintw(barraEsquerda, 9, (winMaxX/2) + 3, "Y:%d", virtY);
    mvwprintw(barraEsquerda,10, (winMaxX/2) + 3, "x:%d", virtX);
}



void ScrollWindow(WINDOW* barraEsquerda, WINDOW* grade,ponteiroCelula* arvore, int dir, int* telaY, int* telaX)
{
    int virtY, virtX;
    int maxY, maxX;

    getmaxyx(grade, maxY, maxX);
    getyx(grade, virtY, virtX);

    switch (dir) {
        case KEY_UP:
            (*telaY)++;
            wmove(grade, maxY, virtX);
            break;

        case KEY_DOWN:
            (*telaY)--;
            wmove(grade, 0, virtX);
            break;

        case KEY_LEFT:
            (*telaX)--;
            wmove(grade,virtY, maxX);
            break;

        case KEY_RIGHT:
            (*telaX)++;
            wmove(grade, virtY, 0);
            break;
    }
    AtualizaGrade(grade, arvore, telaY, telaX);
}


void AtualizaGrade(WINDOW* grade,ponteiroCelula* arvore, int* telaY, int* telaX )
{
    int maxY, maxX;

    getmaxyx(grade, maxY, maxX);//deve limpar a tela, desenhar os simbolos vazios e depois as celulas
}

void DesenhaCelula(WINDOW* grade, int telaY, int telaX, int y, int x)
{
    int maxY, maxX;
    int virtY, virtX; //variaveis de posição da celula na grade

    getmaxyx(grade, maxY, maxX);

    virtY = Modulo( y) - Modulo(maxY*telaY);
    virtY = Modulo( x) - Modulo(maxX*telaX);
}

void RefreshTodasasTelas(WINDOW* grade, WINDOW* barraInferior, WINDOW* barraEsquerda)
{
    wrefresh(barraEsquerda);
    wrefresh(barraInferior);
    wrefresh(grade);
}

//teste de interface
/*
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
*/

//teste de geração de id
/*
int main()
{
    int x, y;
    int id;

    printf("Insira o x e o y:\n");
    scanf("%d %d", &x, &y);

    id = GeraId(y, x);

    printf("id: %d\n", id);

    return 0;

}
 */

//teste da arvore
/*
int main()
{
    int x, y, num;

    ponteiroCelula* arvore = NULL;
    ponteiroCelula * ptr;

    arvore = InitArvoreCelula();

    while(1)
    {
        printf("Entre 1 para adicionar uma celula, 2 para deletar uma celula,"
               " 3 para mostrar a arvore, 4 para mostrar celulas na proximidade"
               " e 0 para sair do programa\n");
        scanf("%d", &num);

        if(num == 0)
            break;

        switch(num)
        {
            case 1:
                printf("entre os valores de x e y:\n");
                scanf("%d %d", &x, &y);

                InsereCelula(y, x, arvore);

                break;
            case 2:
               printf("entre os valores de x e y:\n");
               scanf("%d %d", &x, &y);

               x = GeraId(y, x);
               x = DeletaCelula(x, arvore);
               if(x == 1)
                   printf("Celula deletada com sucesso!\n");
               else
                   printf("Falha ao deletar celula!\n");
               break;
            case 3:
                MostraArvore(arvore);
            break;
            case 4:
                printf("entre os valores de x e y:\n");
                scanf("%d %d", &x, &y);
                ptr = ProcuraCelulaNaArvore(GeraId(y, x), arvore);
                x = ProcuraCelulasProximidade( *ptr, arvore);
                printf("Celulas na proximidade: %d\n", x);
                break;
        }
    }
    return 0;
}
*/