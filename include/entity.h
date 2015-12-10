/*! \brief Class Enemy.h.
 *
 *  Handle enemy screen issues.
*/
#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>		
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>

using namespace std;

/*! entity class */
class entity
{
	/*!
     * Public section
	*/
	public:

	    sf::RectangleShape rect;
	    sf::Sprite sprite;
	    sf::Text text;

	/*!
     * Private section
	*/
	private:

	/*!
     * Protected section
	*/
	protected:

};

#endif // ENTITY_H