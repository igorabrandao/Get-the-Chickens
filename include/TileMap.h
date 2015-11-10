#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>

class TileMap : public sf::Drawable, public sf::Transformable
{
/*
 * Public section
 */
public:

	/*!
	 * @param tileset o caminho da textura ex: "asset/textura/nomedatextura.extensao"
	 * @param tilesize o tamanho de cada quadrado do tilemap exemplo 32x32 pixels,
	 * @param tiles um ponteiro para o array que indica quais os quadrados devem ser imprimidos na fase.
	 * @param width o numero de quadrados que serao imprimidos na horizontal ( largura )
	 * @param height o numero de quadrados que serao imprimidos na vertical  ( altura )
	*/
	bool load( const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height );
	
private:

	// Subescreve o metodo draw para usar window.draw(entity) inves de entity.draw() 
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const
	{
		states.transform *= getTransform();
		states.texture = &m_tileset;
		target.draw( m_vertices, states );
	}

	// O vetor de vertex que gardará os ladrilhos que serao impressos na tela.
	sf::VertexArray m_vertices;
	// A textura que contem os recursos do tilemap
	sf::Texture m_tileset;
};


#endif // TILE_MAP_H