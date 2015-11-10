#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	void setVelocity(sf::Vector2f _velocity);
	sf::Vector2f getVelocity();

public:
	sf::Vector2f velocity;
};

#endif