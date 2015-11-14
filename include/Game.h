#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "ResourceHolder.h"

// Resource ID for sf::Texture ( sera usado para determinar qual texura usar pela classe resourceholder )
namespace Textures
{
	enum ID
	{
		TileMap,
		Hero,
	};
}

using namespace std;
class Game : private sf::NonCopyable
{
public:
	Game(); // Construtor
	void run(); // Roda o jogo.


private:
	void processEvents(); // Processa todos os eventos do jogo
	void update( sf::Time elapsedTime ); // Atualiza o jogo.
	void render(); // Renderiza o jogo.

	void updateStatistics( sf::Time elapsedTime );
	void handlePlayerInput( sf::Keyboard::Key key, bool isPressed );


private:
	static const float PlayerSpeed;
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	sf::Texture			mTexture;
	sf::Sprite			mPlayer;
	sf::Font			mFont;
	sf::Text   			mStatisticsText;
	sf::Time 			mStatisticsUpdateTime;

	std::size_t 		mStatisticsNumFrames;
	bool				mIsMovingUp;
	bool 				mIsMovingDown;
	bool				mIsMovingRight;
	bool				mIsMovingLeft;
	TileMap				mMap;
	// Cria um conteiner de texturas chamado textures.
    //ResourceHolder< sf::Texture, Textures::ID> textures;
};

#endif // GAME_H