#ifndef GAME_H
#define GAME_H

#include <World.h>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>
#include "TileMap.h"
#include "ResourceHolder.h"

using namespace std;

class Game : private sf::NonCopyable
{
public:
							Game(); // Construtor
	void 					run(); // Roda o jogo.


private:
	void 					processEvents(); // Processa todos os eventos do jogo
	void 					update( sf::Time elapsedTime ); // Atualiza o jogo.
	void 					render(); // Renderiza o jogo.

	void 					updateStatistics( sf::Time elapsedTime );
	void 					handlePlayerInput( sf::Keyboard::Key key, bool isPressed );


private:
	static const sf::Time 	TimePerFrame;

	sf::RenderWindow 		mWindow;
	World					mWorld;

	sf::Font				mFont;
	sf::Text   				mStatisticsText;
	sf::Time 				mStatisticsUpdateTime;
	std::size_t 			mStatisticsNumFrames;

	//TileMap				mMap;
};

#endif // GAME_H