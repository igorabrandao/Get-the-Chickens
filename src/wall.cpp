/*! \brief wall.cpp.
 *
 *  Implements the game wall.
*/
#include "wall.h"

wall::wall()
{
    rect.setSize(sf::Vector2f(50, 50));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::White);
}

void wall::update()
{
    sprite.setPosition(rect.getPosition());
}
