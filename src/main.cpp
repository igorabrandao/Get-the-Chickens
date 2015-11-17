#include <iostream>
#include <stdexcept>
#include "Game.h"

int main(void)
{
    // Tenta rodar o jogo
    try
    {
        // instancia a classe Game
        Game game;
        // roda o jogo
        game.run();
    }
    catch ( std::exception& e ) // Captura o erro
    {
        // Imprime o erro.
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}