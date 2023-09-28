//
// Created by rubens on 26/09/23.
//

#include "Celulas.h"

 struct celula
 {
    int x, y;
    int id;

    ponteiroCelula filhoEsquerda;
    ponteiroCelula filhoDireita;
 };


//Inicializa a arvore de celulas
ponteiroCelula InitArvoreCelula()
{
    ponteiroCelula arvore = NULL;

    return arvore;
}

//cria uma nova celula
ponteiroCelula CriaCelula(int y, int x)
{
    ponteiroCelula celula = NULL;

    celula = malloc(sizeof(celula));

    if(celula != NULL)
    {
        celula->id = GeraId(y, x);
        celula->y = y;
        celula->x = x;
        celula->filhoDireita = NULL;
        celula->filhoEsquerda = NULL;
    }

    return celula;
}

//insere uma celula na arvore, retorna 1 caso sucesso, -1 caso falha
int InsereCelula(int y, int x, ponteiroCelula* arvore)
{
    if(arvore == NULL)
    {
        ponteiroCelula celula = NULL;

        celula = CriaCelula(y, x);

        if(celula == NULL)
            return -1;
        else
        {
            *arvore = celula;
            return 1;
        }
    }
    else
    {
        int id = GeraId(y, x);

        ponteiroCelula celulaAtual = NULL;
        celulaAtual = *arvore;

        if(celulaAtual->id > id )
            return InsereCelula(y, x, &celulaAtual->filhoEsquerda);
        else
            return InsereCelula(y, x, &celulaAtual->filhoDireita);
    }
}
//procura uma celula na arvore e retorna um ponteiro
ponteiroCelula ProcuraCelulaNaArvore(int id, ponteiroCelula arvore)
{
    if(arvore == NULL)
        return NULL;
    if(arvore->id == id)
        return arvore;
    if(arvore->id > id)
        return ProcuraCelulaNaArvore(id, arvore->filhoEsquerda);
    else
        return ProcuraCelulaNaArvore(id, arvore->filhoEsquerda);
}
//procura celulas ao redor de uma celula específica, retorna retorna o número de células
//adjacentes
int ProcuraCelulasProximidade(ponteiroCelula celula, ponteiroCelula arvore)
{
    if(celula == NULL)
        return -1;
    int x = celula->x - 1;
    int y = celula->y + 1;
    int numCelulasAdjacentes = 0;

    for(int yLocal = 0;yLocal < 3;yLocal++)
    {
        for(int xLocal = 0; xLocal < 3; xLocal++)
        {
            if(ProcuraCelulaNaArvore(GeraId((y + yLocal), (x + xLocal)), arvore) != NULL)
                if(yLocal != xLocal)
                    numCelulasAdjacentes++;
        }
    }

    return numCelulasAdjacentes;
}
//deleta uma celula da arvore e altera o seu estado na grade, retorna sucesso ou falha
int DeletaCelula(int id, ponteiroCelula arvore)
{
    ponteiroCelula ptr1 = NULL;
    ponteiroCelula ptr2 = NULL;
    ponteiroCelula ptr3 = NULL;


    ptr1 = ProcuraCelulaNaArvore(id, arvore);
    if(ptr1 == NULL)
        return -1;

    ptr2 = ptr1;
    ptr1 = ptr2->filhoDireita;

    if(ptr1 !=NULL)
        if(ptr2->filhoEsquerda != NULL)
            InsereCelula(ptr2->filhoEsquerda->y, ptr2->filhoEsquerda->x,
                         &ptr1);

    free(ptr2);
    ptr2 = NULL;

    return 1;
}

//gera o id de uma celula. Retorna o id
/*
 * o id de uma célula irá seguir o seguinte padrão:
 *  - 1 para o sinal negativo
 *  - 0 para o sinal positivo
 *  - (sinal de x)(valor de x)(sinal de y)(valor de y)
 */
int GeraId(int y, int x)
{
    int yTemp = Modulo(y);
    int xTemp = Modulo(x);

    int status1, status2;
    int n1, n2; //numeros utilizados para manipulação de algarismos
    int id;


    status1 = 0;
    status2 = 0;
    n1  = 10;
    n2 = 10;
    //começamos formando a parte do y
    while(1)
    {
        if(yTemp > 9)
        {
            yTemp /= 10;
            n1 *= 10;
        }
        else
            status1 = 1;

        if(xTemp > 9)
        {
            xTemp /= 10;
            n2 *= 10;
        }
        else
            status2 = 1;

        if(status1 && status2)
            break;

    }
    if(y < 0)
        id = Modulo(y) + n1;
    else
        id = Modulo(y);

    if(x < 0)
        id = id*10 + 1;
    else
        id *= 10;

    id = id*n2 + Modulo(x);

    return id;
}