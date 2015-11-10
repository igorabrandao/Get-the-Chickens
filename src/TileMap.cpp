#include "TileMap.h"


bool 
TileMap::load( const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height )
{
	// le a textura ( spritesheet ) do tilemap
	if ( !m_tileset.loadFromFile( tileset ) )
	{
		std::cout << "A textura nao foi lida" << std::endl;
		return false;
	}

	// Redimensiona o array de vertex para caber o tamanho do mapa.
	m_vertices.setPrimitiveType( sf::Quads );
	m_vertices.resize( width * height * 4 );

	// Popula o vertex array, com um quadrado por ladrilho.
	for ( unsigned int i(0); i < width; ++i )
	{
		for ( unsigned int j(0); j < height; ++j )
		{
			// pega o numero do ladrilho atual
			int tileNumber = tiles[ i + j  * width ];

			// Encontra sua posicao na textura do tileset
			int tu = tileNumber % ( m_tileset.getSize().x / tileSize.x );
			int tv = tileNumber / ( m_tileset.getSize().x / tileSize.x );

			// Um ponteiro que recebe o ladrilho atual.
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define a posição dos 4 canto
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
           	quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
          	quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
           	quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

		}
	}
	return true;
}