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