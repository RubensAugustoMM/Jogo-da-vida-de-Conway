<hl>Jogo da vida de Conway</hl>
-
O jogo da vida, criado pelo matemático britanico John Horton Conway,
consiste em uma grade 2D infinita onde são definidas celulas quadradas.
Neste plano, as celular podem ser definidas como vivas ou mortas, seguindo
as seguintes regras:

+ 1 . Uma célula morta vem a vida caso houver três células adjacentes, na vertical, horizontal ou diagonal, viva.

+ 2 . Uma célula morrerá se tiver menos de dois vizinhos (isolamento) ou mais de três vizinhos (superpopulação).

<hl>Este Programa </hl>
-
Este programa será uma implementação do jogo da vida de Conway utilizando C e NCURSES.
Ao inicio do programa, será gerado um plano 2D onde o usuário poderá navegar e tornar células vivas.
Após selecionar as celular vivas, o usuário poderá dar inicio à simulação e 
poderá parar ela quando quiser.

Este objetivo será atingindo utilizando arvores balanceadas para armazenar o grande
número de células vivas que o programa irá simular.

<hl>Dependências</hl>
-
+ NCURSES
