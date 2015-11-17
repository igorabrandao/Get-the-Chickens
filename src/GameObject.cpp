#include "GameObject.h"

void
GameObject::setVelocity( sf::Vector2f velocity )
{
	mVelocity = velocity;
}

void
GameObject::setVelocity( float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f
GameObject::getVelocity() const
{
	return mVelocity;
}

void
GameObject::updateCurrent( sf::Time dt )
{
	move( mVelocity * dt.asSeconds() );
}