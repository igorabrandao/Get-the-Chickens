/*! \brief textDisplay.cpp.
 *
 *  Implements the screen text.
*/
#include "textDisplay.h"

textDisplay::textDisplay()
{
    text.setColor(sf::Color::Red);
    text.setCharacterSize(30);
    text.setString(myString);
}

void textDisplay::update()
{
    text.move(0,-movementSpeed);
    
    counter++;
    if (counter >= lifeTime)
    {
        destroy = true;
    }
}