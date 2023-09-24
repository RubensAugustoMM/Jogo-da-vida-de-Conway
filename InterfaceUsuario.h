//
// Created by rubens on 15/09/23.
//
#include <ncurses.h>
#include <stdio.h>
#ifndef JOGO_DA_VIDA_DE_CONWAY_GRADE_H
#define JOGO_DA_VIDA_DE_CONWAY_GRADE_H


//inicializa a grade do jogo
WINDOW *InitGrade(int maxY, int maxX);
//inicializa a barra de informações na parte inferior da tela
WINDOW *InitBarraDeInformacoes(int maxY, int maxX);
//inicializa a interface do jogo
void InitConwayGameOfLifeUI(WINDOW** grade, WINDOW** barra);
#endif //JOGO_DA_VIDA_DE_CONWAY_GRADE_H
