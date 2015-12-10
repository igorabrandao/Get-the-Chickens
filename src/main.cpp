/*! \brief Class main.cpp.
 *
 *  Contains the menu function and starts the program.
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"

using namespace std;

/*! Constants */
const sf::Time TimePerFrame = sf::seconds( 1.f / 60.f );

/**
 * Starts the game
*/
int main()
{
	/*! Generate new windows */
	sf::RenderWindow Window( sf::VideoMode( screenWidth, screenHeight), "Get the Chickens");
    Window.setFramerateLimit(60);

    /*! Set the game icon */
    sf::Image icon;

    if ( !icon.loadFromFile("assets/images/icon/icon.png") )
        throw "Could not find icon.ogg";
    else
        Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	/*! Object to handle fade geometric */
	sf::RectangleShape Fade = sf::RectangleShape( sf::Vector2f(screenWidth, screenHeight) );
	Fade.setFillColor( sf::Color(255, 255, 255) );

	/*! ScreenManager instance */
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	Window.setKeyRepeatEnabled(false);
    Window.setFramerateLimit(60);
    sf::Clock   clock;
    sf::Time    timeSinceLastUpdate = sf::Time::Zero;

    /*! Infinite loop that keeps screen */
	while ( Window.isOpen() )
	{
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while ( timeSinceLastUpdate > TimePerFrame )
        {
            timeSinceLastUpdate -= TimePerFrame;
            /*! Catch the window events */
            /*! Event instance */
            sf::Event event;
            if ( Window.pollEvent(event) )
            {
                /*! Check if it's a close event */
                if ( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape )
                {
                    Window.close();
                }
            }

            /*! Clear screen before load a new content */
			Window.clear( sf::Color(0.0f, 0.0f, 0.0f, ScreenManager::GetInstance().GetAlpha()) );

			/*! Run SplashScreen */
			ScreenManager::GetInstance().Update(Window, event);
			Fade.setFillColor( sf::Color(0, 0, 0, 255 * ScreenManager::GetInstance().GetAlpha()) );

			ScreenManager::GetInstance().Draw(Window);
			Window.draw(Fade);

			/*! Keep the screen showing */
			Window.display();
        }
	}
	return 0;
}