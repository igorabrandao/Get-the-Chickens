#include "Game.h"

//#include "StringHelpers.h"


const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);



Game::Game()
: mWindow( sf::VideoMode(960,640), "SFML app", sf::Style::Close)
, mTexture()
, mPlayer()
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
, mIsMovingUp( false )
, mIsMovingDown( false )
, mIsMovingRight( false )
, mIsMovingLeft( false )
, mMap()
//, textures()
{
	// define the level with an array of tile indices
    const int level[] =
    {
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,
    };

    

    // Tenta carregar as texturas
    /*
    try
    {
    	textures.load( Textures::TileMap, 	"assets/textures/newtileset.png" );
    	textures.load( Textures::Hero, 		"assets/textures/player.png" );
    }
    catch ( std::runtime_error& e )
    {
    	std::cout << "Excepion: " << e.what() << std::endl;
    	//return 1;
    }
*/
	// Le a textura do tiledmap.
	if ( !mMap.load( "assets/textures/newtileset.png", sf::Vector2u( 32, 32 ), level, 30, 20 ) )
	{
		std::cout << "Erro ao carregar a textura do tilemap" << std::endl;
	}	
		
	if ( !mTexture.loadFromFile( "assets/textures/player.png" ) )
	{
		std::cout << "Erro ao carregar a textura do jogador" << std::endl;
	}

	mPlayer.setTexture( mTexture /*textures.get(Textures::Hero)*/ );
	mPlayer.setTextureRect( sf::IntRect( 0, 0, 32, 32 ) );
	mPlayer.setPosition( 100.f, 100.f );

	mFont.loadFromFile( "assets/fonts/Sansation.ttf" );
	mStatisticsText.setFont( mFont );
	mStatisticsText.setPosition( 5.f, 5.f );
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock; // Inicializa um relogio.
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while ( mWindow.isOpen() )
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame )
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update( TimePerFrame );
		}

		updateStatistics( elapsedTime );
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while ( mWindow.pollEvent( event ) )
	{
		switch ( event.type )
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	} 
}

void Game::update( sf::Time elapsedTime )
{
	sf::Vector2f movement(0.f, 0.f);
	if ( mIsMovingUp )
		movement.y -= PlayerSpeed;
	if ( mIsMovingDown )
		movement.y += PlayerSpeed;
	if ( mIsMovingLeft )
		movement.x -= PlayerSpeed;
	if ( mIsMovingRight )
		movement.x += PlayerSpeed;

	mPlayer.move( movement * elapsedTime.asSeconds() );	
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mMap);
	mWindow.draw(mPlayer);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics( sf::Time elapsedTime )
{
	/*
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if ( mStatisticsUpdateTime >= sf::seconds(1.0f ) )
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames + "us" );
	
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
	*/
}

void Game::handlePlayerInput( sf::Keyboard::Key key, bool isPressed )
{
	if ( key == sf::Keyboard::W )
		mIsMovingUp = isPressed;
	if ( key == sf::Keyboard::S )
		mIsMovingDown = isPressed;
	if ( key == sf::Keyboard::A )
		mIsMovingLeft = isPressed;
	if ( key == sf::Keyboard::D )
		mIsMovingRight = isPressed;

}