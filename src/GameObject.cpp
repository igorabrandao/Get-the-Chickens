#include "GameObject.h"

GameObject::GameObject()
{
	/* Empty for while */
}

void
GameObject::setVelocity( sf::Vector2f _velocity )
{
	velocity.x = _velocity.x;
	velocity.y = _velocity.y;
}

sf::Vector2f
GameObject::getVelocity()
{
	return velocity;
}