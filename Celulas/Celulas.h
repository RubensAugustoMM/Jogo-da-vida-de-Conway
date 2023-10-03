//
// Created by rubens on 26/09/23.
//

#ifndef JOGO_DA_VIDA_DE_CONWAY_CELULAS_H
#include <stdlib.h>
#include "Utilitarios/Utilitarios.h"
#include <stdio.h>
#define JOGO_DA_VIDA_DE_CONWAY_CELULAS_H

typedef struct celula celula;
typedef celula* ponteiroCelula;


//Inicializa a arvore de celulas
ponteiroCelula* InitArvoreCelula();
//cria uma nova celula
ponteiroCelula CriaCelula(int y, int x);
//insere uma celula na arvore, retorna 1 caso sucesso, -1 caso falha
int InsereCelula(int y, int x, ponteiroCelula* arvore);
//procura uma celula na arvore e retorna um ponteiro
ponteiroCelula* ProcuraCelulaNaArvore(int id, ponteiroCelula* arvore);
//procura celulas ao redor de uma celula específica, retorna um array com as celulas
//adjacentes
int ProcuraCelulasProximidade(ponteiroCelula celula, ponteiroCelula* arvore);
//deleta uma celula da arvore e altera o seu estado na grade, retorna sucesso ou falha
int DeletaCelula(int id, ponteiroCelula* arvore);
//gera o id de uma celula. Retorna o id
int GeraId(int y, int x);
//mostra arvore. para testes
void MostraArvore(ponteiroCelula* arvore);


#endif //JOGO_DA_VIDA_DE_CONWAY_CELULAS_H
