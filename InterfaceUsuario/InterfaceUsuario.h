//
// Created by rubens on 15/09/23.
//
#include <ncurses.h>
#include <stdio.h>
#include "Celulas/Celulas.h"
#include "Utilitarios/Utilitarios.h"
#ifndef JOGO_DA_VIDA_DE_CONWAY_GRADE_H
#define JOGO_DA_VIDA_DE_CONWAY_GRADE_H


//inicializa a grade do jogo
WINDOW *InitGrade(int maxY, int maxX);
//inicializa a barra de informações na parte inferior da tela
WINDOW *InitBarraDeInformacoesInferior(int maxY, int maxX);
//função para gerar a barra de informação à esquerda
WINDOW *InitBarraDeInformacoesEsquerda(int maxY, int maxX);
//atualiza grade
void AtualizaGrade(WINDOW* grade,ponteiroCelula* arvore, int* telaY, int* telaX );
//Atualiza barra de informações esquerda
void AtualizaBarraEsquerda(WINDOW* barra, WINDOW* grade, int winY, int winX, int curPosY, int curPosX);
//inicializa a interface do jogo
void InitConwayGameOfLifeUI(WINDOW** grade, WINDOW** barraInferior, WINDOW** barraEsquerda);
//Move a tela principal

void DesenhaCelula(WINDOW* grade, int telaY, int telaX, int y, int x);

void ScrollWindow(WINDOW* barraEsquerda, WINDOW* grade,ponteiroCelula* arvore, int dir, int* telaY, int* telaX);

//move cursor
void MoveCursor(WINDOW* barraEsquerda,WINDOW* grade,ponteiroCelula* arvore,int dir,int* telaY, int* telaX, int* y, int* x);


void RefreshTodasasTelas(WINDOW* grade, WINDOW* barraInferior, WINDOW* barraEsquerda);

#endif //JOGO_DA_VIDA_DE_CONWAY_GRADE_H

