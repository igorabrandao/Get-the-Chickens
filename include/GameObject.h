#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

// Entity.hpp

#include "SceneNode.h"


class GameObject : public SceneNode
{
public:
	void 			setVelocity( sf::Vector2f velocity );
	void 			setVelocity( float vx, float vy );
	sf::Vector2f 	getVelocity() const;

private:
	virtual void 	updateCurrent( sf::Time dt );

private:
	sf::Vector2f 	mVelocity;
};

#endif // GAME_OBJECT_H