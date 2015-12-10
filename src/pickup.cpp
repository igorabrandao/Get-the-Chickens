/*! \brief pickup.cpp.
 *
 *  Implements the game items.
*/
#include "pickup.h"

pickup::pickup()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Yellow);
}

void pickup::update()
{
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - 25, rect.getPosition().y - 30);
}