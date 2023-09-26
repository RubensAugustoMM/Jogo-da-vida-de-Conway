//
// Created by rubens on 26/09/23.
//

#ifndef JOGO_DA_VIDA_DE_CONWAY_CELULAS_H

#define JOGO_DA_VIDA_DE_CONWAY_CELULAS_H

typedef struct celula celula;
typedef celula* ponteiroCelula;

//cria uma nova celula
ponteiroCelula CriaCelula();
//Inicializa a arvore de celulas
ponteiroCelula InitArvoreCelula();
//procura uma celula na arvore e retorna um ponteiro
ponteiroCelula ProcuraCelulaNaArvore(int id);
//procura celulas ao redor de uma celula específica, retorna um array com as celulas
//adjacentes
ponteiroCelula* ProcuraCelulasProximidade(int id);
//deleta uma celula da arvore e altera o seu estado na grade, retorna sucesso ou falha
int DeletaCelula(int id);
//gera o id de uma celula. Retorna o id
int GeraId(int y, int x);


#endif //JOGO_DA_VIDA_DE_CONWAY_CELULAS_H
