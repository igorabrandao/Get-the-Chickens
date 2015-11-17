#ifndef HERO_H
#define HERO_H

#include <GameObject.h>
#include <ResourceIdentifiers.h>

#include <SFML/Graphics/Sprite.hpp>


class Hero : public GameObject
{
	public:
		enum Type
		{
			HeroType1,
			HeroType2,
		};


	public:
							Hero(Type type, const TextureHolder& textures);


	private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		Type				mType;
		sf::Sprite			mSprite;
};

#endif // HERO_H