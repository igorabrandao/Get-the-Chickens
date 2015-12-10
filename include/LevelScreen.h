/*! \brief Class LevelScreen.h.
 *
 *  Handle with the game's engine.
*/
#ifndef LevelSCREEN_H
#define LevelSCREEN_H

#include "GameScreen.h"
#include "ScreenManager.h"

#include "random.h"
#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "textDisplay.h"
#include "pickup.h"
#include "wall.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>

/*! LevelScreen class */
class LevelScreen : public GameScreen
{
    /*!
     * Public section
    */
    public:

        /*! Functions */
        LevelScreen();   /*!< Constructor */
        ~LevelScreen();  /*!< Destructor */

        /*! Screen methods */
        void LoadContent(); /*!< Load the content on the screen */
        void UnloadContent(); /*!< Unload the content on the screen */
        void Update(sf::RenderWindow& window, sf::Event event); /*!< Update the screen content */
        void Draw(sf::RenderWindow &Window); /*!< Print the content on the screen */

    /*!
     * Private section
    */
    private:

        /*! Attributes */
        sf::Clock clock;
        sf::Clock clock2;
        sf::Clock clock3;
        float playerMovementSpeed = 5;
        int counterWalking = 0;
        int counter = 0;
        int counter2 = 0;
        int counter3 = 0;
        int flagView = 0;

        /*! View Handle */
        sf::View    view1;

        /*! Textures */
        sf::Texture textureCoin;
        sf::Texture textureFireBall;
        sf::Texture textureBlood;
        sf::Texture textureCrate;
        sf::Texture textureWall;
        sf::Texture textureItems;
        sf::Texture textureEnemySprite;
        sf::Texture textureGround;
        sf::Texture texturePotion;
        sf::Texture textureFood;
        sf::Texture texturePlayer;

        /*! Sprites */
        sf::Sprite spritePlayer;

        /*! Fonts */
        sf::Font font;

        /*! Sounds */
        sf::SoundBuffer bufferCoin;
        sf::SoundBuffer bufferShot;
        sf::SoundBuffer bufferCollision;
        sf::SoundBuffer bufferPlayerDamaged;
        sf::Sound       soundCoin;
        sf::Sound       soundShot;
        sf::Sound       soundCollision;
        sf::Sound       soundPlayerDamaged;

        /*! Texts and messages */
        sf::Text text;
        sf::Text textHP;
        sf::Text textChicken;

        /*! Clock handle */
        static const sf::Time TimePerFrame;
        static const sf::Time TimePerFrameNormal;

        /*! Class object */
        player      Player1;
        projectile  projectile1;
        enemy       enemy1;
        enemy       blood1;
        textDisplay textDisplay1;
        wall        wall1;
        pickup      pickup1;
        wall        ground1;

        /*! Projectile Vector Array */
        vector<projectile>::const_iterator iter;
        vector<projectile> projectileArray;

        // Enemy Vector Array
        vector<enemy>::const_iterator iter4;
        vector<enemy> enemyArray;

        // Blood Vector Array
        vector<enemy>::const_iterator iter20;
        vector<enemy> bloodArray;

        // Text Vector Array
        vector<textDisplay>::const_iterator iter8;
        vector<textDisplay> textDisplayArray;

        // Wall Vector Array
        vector<wall>::const_iterator iter15;
        vector<wall> wallArray;

        // Pickup Vector Array
        vector<pickup>::const_iterator iter11;
        vector<pickup> pickupArray;

        // Ground Vector Array
        vector<wall>::const_iterator iter25;
        vector<wall> groundArray;
};

#endif // LevelSCREEN_H