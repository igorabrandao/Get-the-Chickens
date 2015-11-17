#include <Hero.h>
#include <ResourceHolder.h>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID( Hero::Type type )
{
	switch (type)
	{
		case Hero::HeroType1:
			return Textures::Hero1;

		case Hero::HeroType2:
			return Textures::Hero2;
	}
	return Textures::Hero1;
}

Hero::Hero( Type type, const TextureHolder& textures )
: mType( type )
, mSprite( textures.get( toTextureID( type ) ) )
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}