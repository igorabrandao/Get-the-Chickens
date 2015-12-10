

# README #

**Visão Geral**

O ‘Get the Chickens’ é jogo em duas dimensões que tem como objetivo eliminar um determinado número de
galinhas que são controladas por inteligência artificial dentro de um tempo limite, além disso serão colocadas para o jogador situações diversas no cenário tais como obstáculos e outros elementos que possam facilitar ou dificultar a captura das galinhas.


**Membros da equipe**

Igor A. Brandão e Leandro Antonio F. da Silva


**Como compilar**

Use o makefile digitando o comando **'make'** pelo terminal, após ter navegado para a pasta do projeto.

**Como gerar a documentação**

Utilize o arquivo **'documentation.html'** para acessar diretamente a documentação.

Caso a pasta doc não estiver presente na raíz do projeto, use o comando **'doxygen Doxyfile'** pelo terminal, após ter navegado para a pasta do projeto.

**Informações adicionais**

Buscamos utilizar uma estrutura mais rebuscada para o jogo como um todo, realizando o gerenciamento da plataforma em classes responsáveis por gerenciar elementos distintos do jogo, separadas da seguinte maneira:

**Animation.h** => Gerencia os efeitos de transição entre tela (fade, scroll, zoom).

**ConfigScreen.h** => Trata os elementos visuais do jogo, assim como a atualização destes.

**FadeAnimation.h** => Classe responsável pelo efeito fade.

**FileManager.h** => Gerencia a manipulação de arquivos (leitura das configurações).

**GameScreen.h** => Lida com instâncias genéricas e reutilizáveis do projeto.

**InputManager.h** => Gerencia eventos de entrada de teclado e outros periféricos.

**LevelScreen.h (Principal)** => Constrói o cenário e implementa a jogabilidade

**MenuManager.h** => Gera o menu do jogo de acordo com o arquivo de configuração.

**ScreenManager.h** => Gerencia a criação de todas as telas através do método AddScreen com GetInstance.

**SplashScreen.h** => Cria a apresentação inicial do jogo.

**TitleScreen.h** => Tela base que através do MenuManager faz a geração do menu inicial.

Porém a lógica em si do jogo está contida nas seguintes classes:

**enemy.h** => Controla a inteligência artificial das galinhas inimigas.

**entity.h** => Serve como base para a geração de novos elementos para o jogo.

**pickup.h** => Gerencia os itens que aparecem durante o jogo.

**player.h** => Gerencia as ações que o jogador pode realizar.

**projectile.h** => Gera objetos que representam um projétil

**random.h** => Tela base que através do MenuManager faz a geração do menu inicial.

**textDisplay.h** => Controla os textos que aparecem durante a partida.

**wall.h** => Gera os objetos do tipo muro.