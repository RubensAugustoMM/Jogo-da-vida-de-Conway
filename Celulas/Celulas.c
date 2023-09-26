//
// Created by rubens on 26/09/23.
//

#include "Celulas.h"

 struct celula
 {
    int x, y;
    /*
     * o id de uma célula irá seguir o seguinte padrão:
     *  - 1 para o sinal negativo
     *  - 0 para o sinal positivo
     *  - (sinal de x)(valor de x)(sinal de y)(valor de y)
     */
    int id;

    ponteiroCelula filhoEsquerda;
    ponteiroCelula filhoDireita;
 };


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