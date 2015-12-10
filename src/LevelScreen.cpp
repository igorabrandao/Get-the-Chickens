/*! \brief LevelScreen.cpp.
 *
 *  Implements the game engine.
*/
#include "LevelScreen.h"

/*! Constants */
const sf::Time LevelScreen::TimePerFrame = sf::seconds(0.5f);
const sf::Time LevelScreen::TimePerFrameNormal = sf::seconds(1);

/****************************************************************************************//**
* SCREEN AND GAME METHODS
*******************************************************************************************/

/********************************************//**
* constructor
***********************************************/
LevelScreen::LevelScreen()
{
    /* Empty */
}

/********************************************//**
* destructor
***********************************************/
LevelScreen::~LevelScreen()
{
    /* Empty */
}

/********************************************//**
* content loader
***********************************************/
void
LevelScreen::LoadContent()
{
    /** Load game resources */
    //srand(time(NULL));

    /*! Initialize the view */
    view1.reset( sf::FloatRect(200, 200, 300, 200) );

    /*! Set the camera view */
    view1.setSize(sf::Vector2f(screenWidth, screenHeight));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));

    /*! Try to load the game media resource */
    if ( !textureCoin.loadFromFile("assets/images/game/coin.png" )) {
        throw "Could not find coin.png";
    }

    if ( !textureFireBall.loadFromFile("assets/images/game/fireball.png" )) {    
        throw "Could not find fireball.png";
    }
 
    if ( !textureBlood.loadFromFile("assets/images/game/blood.gif" )) {
        throw "Could not find blood.gif";
    }

    if ( !textureCrate.loadFromFile("assets/images/game/Crate_001.png" )) {
        throw "Could not find Crate_001.png";
    }

    if ( !textureWall.loadFromFile("assets/images/game/Back_002.png" )) {
        throw "Could not find Back_002.png";
    }

    if ( !textureItems.loadFromFile("assets/images/game/weapons.png" )) {
        throw "Could not find weapons.png";
    }

    if ( !textureEnemySprite.loadFromFile("assets/images/game/enemySpriteSheet.png" )) {
        throw "Could not find enemySpriteSheet.png";
    }

    if ( !textureGround.loadFromFile("assets/images/game/tile.png" )) {
        throw "Could not find title.png";
    }
    
    if ( !texturePotion.loadFromFile("assets/images/game/potion.png" )) {
        throw "Could not find potion.png";
    }
    
    if ( !textureFood.loadFromFile("assets/images/game/food.png" )) {
        throw "Could not find food.png";
    }

    /*! Load the player sprite */
    if ( !texturePlayer.loadFromFile("assets/images/game/spriteWalk.png" )) {
        throw "Could not find spriteWalk.png";
    }

    // Create a graphical text to display
    if ( !font.loadFromFile("assets/fonts/pixel.ttf" )) {
        throw "Could not find pixel.ttf";
    }

    // Load a music to play
    sf::Music music;
    if ( !music.openFromFile("assets/sounds/game/music.ogg" )) {
        throw "Could not find music.ogg";
    }

    // Play the music
    music.play();
    music.setLoop(true);

    // Sound effects
    if ( !bufferShot.loadFromFile("assets/sounds/game/shot.ogg" )) {
        throw "Could not find shot.ogg";
    }
    
    if ( !bufferCollision.loadFromFile("assets/sounds/game/collision.ogg" )) {
        throw "Could not find collision.ogg";
    }
    
    if ( !bufferPlayerDamaged.loadFromFile("assets/sounds/game/playerhit.ogg" )) {
        throw "Could not find playerhit.ogg";
    }
    
    if ( !bufferCoin.loadFromFile("assets/sounds/game/coin.wav" )) {
        if ( !bufferCoin.loadFromFile("assets/sounds/game/coin.mp3" )) {
            throw "Could not find coin.wav";
        }
    }

    spritePlayer.setPosition(screenWidth/2, screenHeight/2);
    spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));

    // Player texture
    spritePlayer.setTexture(texturePlayer);

    // Coins text
    text.setString("Moedas: ");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setColor(sf::Color::Yellow);
    text.setPosition(0, 0);
    
    // Chicken catched
    textChicken.setString("Galinhas resantes: ");
    textChicken.setFont(font);
    textChicken.setCharacterSize(25);
    textChicken.setColor(sf::Color::Blue);
    textChicken.setPosition(0, 0);
     
    // Player HP Text
    textHP.setString("Vida: ");
    textHP.setFont(font);
    textHP.setCharacterSize(25);
    textHP.setColor(sf::Color::Green);
    textHP.setPosition(0, 0);

    
    
    // Class Object
    Player1.sprite.setTexture(texturePlayer);
    
    // Projectile Object
    projectile1.sprite.setTexture(textureFireBall);
    
    
    // Enemy Object
    enemy1.sprite.setTexture(textureEnemySprite);
    enemy1.text.setFont(font);
    enemy1.text.setCharacterSize(17);
    enemy1.text.setColor(sf::Color::Red);
    //enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    enemy1.rect.setPosition(600, 200);
    //enemyArray.push_back(enemy1);
    
    
    // Blood Object
    blood1.isBlood = true;
    blood1.sprite.setTexture(textureBlood);
    blood1.sprite.setTextureRect(sf::IntRect(32 * 5, 0, 32, 32));
    blood1.rect.setPosition(300, 300);
    //bloodArray.push_back(blood1);
    
    
    // Text Display Object
    textDisplay1.text.setFont(font);
    
    wall1.rect.setPosition(100, 100);
    wall1.sprite.setScale(0.2,0.2);
    //wallArray.push_back(wall1);
    
    int roomSize = generateRandom(10) + 3;
    int verticalDoorLocationRight = 0;
    int verticalDoorLocationLeft = 0;
    int horizontalDoorLocationUp = 0;
    int horizontalDoorLocationDown = 0;
    int roomStartX = 0;
    int roomStartY = 0;
    

    // Coin Object
    pickup1.sprite.setTexture(textureCoin);
    pickup1.text.setFont(font);
    pickup1.text.setCharacterSize(17);
    pickup1.text.setColor(sf::Color::Green);
    pickup1.rect.setPosition(500, 500);
    pickup1.rect.setSize(sf::Vector2f(32, 32));
    //pickupArray.push_back(pickup1);
    
    
    ground1.sprite.setTexture(textureGround);
    ground1.sprite.setTextureRect(sf::IntRect(25,25,50,50));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // Custom Room 1st
    roomSize = 5;
    verticalDoorLocationRight = 3;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 100;
    roomStartX = 0;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    
    
    // Custom Room 2nd
    roomSize = 10;
    verticalDoorLocationRight = 3;
    verticalDoorLocationLeft = 3;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    // Custom Room 3rd
    roomSize = 6;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 100;
    roomStartX = 5 * 50;
    roomStartY = 10 * 50;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    // Custom Room 4th
    roomSize = 10;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 5;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = -1 * (10 * 50);
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(40);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            if (tempRandom == 2)
            {
                // Mummy Enemy
                enemy1.isUnwrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 3)
            {
                // Goblin Enemy
                enemy1.isGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 4)
            {
                // Armoured Goblin Enemy
                enemy1.isArmouredGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 5)
            {
                // Robed Goblin Enemy
                enemy1.isRobedGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 6)
            {
                // Leader Goblin Enemy
                enemy1.isLeaderGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }
            if (tempRandom == 7)
            {
                // Wrapped Mummy Goblin Enemy
                enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                enemyArray.push_back(enemy1);
            }

            
            counter2++;
        }
        
        counter++;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    // Custom Room 5th
    roomSize = 30;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 100;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 5;
    roomStartX = 5 * 50;
    roomStartY = -1 * (45 * 50);
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(425,100,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Random Stuff in Room
    wall1.sprite.setTexture(textureCrate);
    counter = 0;
    while (counter < (roomSize - 1))
    {
        counter2 = 0;
        while (counter2 < (roomSize - 1))
        {
            int tempRandom = generateRandom(3);
            if (tempRandom == 1)
            {
                // Destructable Boxes
                wall1.destructable = true; // Can be destroyed
                wall1.rect.setFillColor(sf::Color::Yellow);
                wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
                wallArray.push_back(wall1);
                wall1.destructable = false;
                wall1.rect.setFillColor(sf::Color::White);
            }
            
            if (tempRandom == 3)
            {
                if (generateRandom(5) == 1)
                {
                    // Wrapped Mummy Goblin Enemy
                    enemy1.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
                    enemyArray.push_back(enemy1);
                }
            }
            
            
            
            counter2++;
        }
        
        counter++;
    }

    // Wrapped Mummy Goblin BOSS Enemy
    class enemy enemyBoss;
    enemyBoss.isWrappedMummyGoblin(counter, counter2, roomStartX, roomStartY);
    enemyBoss.sprite.setTexture(textureEnemySprite);
    enemyBoss.boss = true;
    enemyBoss.text.setFont(font);
    enemyBoss.text.setCharacterSize(17);
    enemyBoss.text.setColor(sf::Color::Red);
    enemyBoss.attackDamage = 15;
    enemyBoss.aggroed = true;
    enemyBoss.hp = 150;
    enemyBoss.maxhp = 150;
    enemyBoss.sprite.setColor(sf::Color::Red);
    enemyBoss.rect.setPosition((10 * 50) + 50 + roomStartX, (10 * 50) + 50 + roomStartY);
    enemyArray.push_back(enemyBoss);
    
    
    
    
    
    
    
    
    // Room (Item Shop)
    roomSize = 8;
    verticalDoorLocationRight = 100;
    verticalDoorLocationLeft = 3;
    horizontalDoorLocationUp = 100;
    horizontalDoorLocationDown = 100;
    roomStartX = 15 * 50;
    roomStartY = 0;
    wall1.destructable = false; // Can be destroyed
    wall1.sprite.setTexture(textureWall);
    
    // Lay Floor Tiles
    ground1.sprite.setTextureRect(sf::IntRect(25,25,50,50));
    counter = 0;
    while (counter <= roomSize)
    {
        counter2 = 0;
        while (counter2 <= roomSize)
        {
            ground1.sprite.setPosition(50 * counter + roomStartX, 50 * counter2 + roomStartY);
            groundArray.push_back(ground1);
            
            counter2++;
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationUp)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Horizontal Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != horizontalDoorLocationDown)
        {
            wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize)
    {
        if (counter != verticalDoorLocationLeft)
        {
            wall1.rect.setPosition(0 + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    // Create Vertical Wall
    counter = 0;
    while (counter < roomSize+1)
    {
        if (counter != verticalDoorLocationRight)
        {
            wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
            wallArray.push_back(wall1);
        }
        
        counter++;
    }
    
    
        // Regular Power Up
        pickup1.cost = 15;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = true;
        pickup1.isNovaPowerup = false;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (2 * 50), (4 * 50));
        pickupArray.push_back(pickup1);

        // Nova Power Up
        pickup1.cost = 30;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = true;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (4 * 50), (4 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
    
    
        // HP Up Shield
        pickup1.cost = 100;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = true;
        pickup1.sprite.setTexture(textureItems);
        pickup1.sprite.setTextureRect(sf::IntRect(34 * 11, 34 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (6 * 50), (4 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isHPShield = false;
    

        // HP Potion
        pickup1.cost = 5;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(texturePotion);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (4 * 50), (2 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
    

        // French Fries Food
        pickup1.cost = 25;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(textureFood);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 14, 32 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (3 * 50), (6 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
    
        // Hamburger Food
        pickup1.cost = 50;
        pickup1.text.setString("Costs " + to_string(pickup1.cost));
        pickup1.inShop = true;
        pickup1.isCoin = false;
        pickup1.isPowerup = false;
        pickup1.isNovaPowerup = false;
        pickup1.isHPShield = false;
        pickup1.isPotion = true;
        pickup1.sprite.setTexture(textureFood);
        pickup1.sprite.setTextureRect(sf::IntRect(32 * 13, 32 * 0, 32, 32));
        pickup1.rect.setPosition((15 * 50) + (5 * 50), (6 * 50));
        pickupArray.push_back(pickup1);
        pickup1.inShop = false;
        pickup1.isPotion = false;
}

/********************************************//**
* content unloader
***********************************************/
void
LevelScreen::UnloadContent()
{
    /* Empty */
}

/********************************************//**
* update animation
***********************************************/
void
LevelScreen::Update(sf::RenderWindow& window, sf::Event event)
{
    // Clock
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock2.getElapsedTime();
    sf::Time elapsed3 = clock3.getElapsedTime();

    if ( window.pollEvent(event) )
    {
        /*! Check if it's a close event */
        if ( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape )
        {
            window.close();
        }
    }
        
    // Enemy Collides with Wall
    counter = 0;
    for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
    {
        counter2 = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            
            if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
            {
                // Hit Wall
                if (enemyArray[counter].direction == 1) // Up
                {
                    enemyArray[counter].canMoveUp = false;
                    enemyArray[counter].rect.move(0,1);
                }
                else if (enemyArray[counter].direction == 2) // Down
                {
                    enemyArray[counter].canMoveDown = false;
                    enemyArray[counter].rect.move(0,-1);
                }
                else if (enemyArray[counter].direction == 3) // Left
                {
                    enemyArray[counter].canMoveLeft = false;
                    enemyArray[counter].rect.move(1,0);
                }
                else if (enemyArray[counter].direction == 4) // Right
                {
                    enemyArray[counter].canMoveRight = false;
                    enemyArray[counter].rect.move(-1,0);
                }
                else
                {
                    
                }
            }
            
            counter2++;
        }
        
        
        counter++;
    }
        
        
        
        
        
        
        // Player Collides with Wall
        counter = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if (Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
            {
                // Hit Wall
                if (Player1.direction == 1) // Up
                {
                    Player1.canMoveUp = false;
                    Player1.rect.move(0,1);
                }
                else if (Player1.direction == 2) // Down
                {
                    Player1.canMoveDown = false;
                    Player1.rect.move(0,-1);
                }
                else if (Player1.direction == 3) // Left
                {
                    Player1.canMoveLeft = false;
                    Player1.rect.move(1,0);
                }
                else if (Player1.direction == 4) // Right
                {
                    Player1.canMoveRight = false;
                    Player1.rect.move(-1,0);
                }
                else
                {
                    
                }
            }
            
            counter++;
        }
        
        
        

        // Player collides with Pickup Item
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if (pickupArray[counter].inShop == true)
                {
                    if (Player1.gil >= pickupArray[counter].cost)
                    {
                        Player1.gil -= pickupArray[counter].cost;
                        
                        if (pickupArray[counter].isPowerup == true)
                        {
                            Player1.powerup = true;
                            Player1.novaAttack = false;
                            pickupArray[counter].destroy = true;
                        }
                        
                        if (pickupArray[counter].isNovaPowerup == true)
                        {
                            Player1.powerup = false;
                            Player1.novaAttack = true;
                            pickupArray[counter].destroy = true;
                        }
                        
                        if (pickupArray[counter].isHPShield == true)
                        {
                            Player1.hp += 10;
                            Player1.maxhp += 10;
                            pickupArray[counter].destroy = true;
                        }
                        if (pickupArray[counter].isPotion == true)
                        {
                            Player1.hp += 5;
                            if (Player1.hp >= Player1.maxhp)
                            {
                                Player1.hp = Player1.maxhp;
                            }
                            pickupArray[counter].destroy = true;
                        }
                    }
                }
                
                if (pickupArray[counter].inShop == false)
                {
                    if (pickupArray[counter].isCoin == true)
                    {
                        /*soundCoin.setBuffer(bufferCoin);
                        soundCoin.setVolume(30000);
                        soundCoin.play();*/
                        Player1.gil += pickupArray[counter].coinValue;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isPowerup == true)
                    {
                        Player1.powerup = true;
                        Player1.novaAttack = false;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isNovaPowerup == true)
                    {
                        Player1.powerup = false;
                        Player1.novaAttack = true;
                        pickupArray[counter].destroy = true;
                    }
                    if (pickupArray[counter].isPotion == true)
                    {
                        Player1.hp += 5;
                        if (Player1.hp >= Player1.maxhp)
                        {
                            Player1.hp = Player1.maxhp;
                        }
                        pickupArray[counter].destroy = true;
                    }
                }

                
            }
            
            counter++;
        }
        
        
        
        
        
        if (elapsed2.asSeconds() >= 0.5)
        {
            clock2.restart();
            
            // Enemy Collides with Player (Player takes damage)
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                {
                    soundPlayerDamaged.setBuffer(bufferPlayerDamaged);
                    soundPlayerDamaged.play();
                    
                    // Text Display
                    textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2, Player1.rect.getPosition().y - Player1.rect.getSize().y/2);
                    textDisplayArray.push_back(textDisplay1);
                    
                    Player1.hp -= enemyArray[counter].attackDamage;
                    Player1.powerup = false;
                    Player1.novaAttack = false;
                }
                
                counter++;
            }
        }
        
        //cout << Player1.hp << endl;
        
        
        
        
        // Projectile Collides with Wall
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
                {
                    projectileArray[counter].destroy = true;
                    
                    if (wallArray[counter2].destructable == true)
                    {
                        wallArray[counter2].hp -= Player1.attackDamage;
                        
                        if (wallArray[counter2].hp <= 0)
                        {
                            wallArray[counter2].destroy = true;
                        }
                    }
                }

                counter2++;
            }

            counter++;
        }
        
        
        
        // Enemy Aggro (AI)
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].aggroed == true)
            {
                if (elapsed3.asSeconds() >= 1)
                {
                    clock3.restart();
                    
                    int tempRand = generateRandom(3);
                    
                    if (tempRand == 1) // Enemy Fires Projectile at Player & Chases Player
                    {
                        projectile1.attackDamage = enemyArray[counter].attackDamage;
                        soundShot.setBuffer(bufferShot);
                        
                        // Player to Right
                        if ((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                             soundShot.play();
                             projectile1.enemyProjectile = true;
                             projectile1.direction = 3;
                             projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                             projectileArray.push_back(projectile1);
                             projectile1.enemyProjectile = false;
                            
                             enemyArray[counter].direction = 3;
                        }
                        
                        // Player to Left
                        if ((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 4;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 4;
                        }
                        
                        // Player to Top
                        if ((Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 1;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 1;
                        }
                        
                        // Player to Bottom
                        if ((Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
                        {
                            soundShot.play();
                            projectile1.enemyProjectile = true;
                            projectile1.direction = 2;
                            projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 - projectile1.rect.getSize().x/2,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                            projectileArray.push_back(projectile1);
                            projectile1.enemyProjectile = false;
                            
                            enemyArray[counter].direction = 2;
                            }
                    }
                    else if (tempRand == 2) // Enemy Chases Player
                    {
                        if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                        else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                    }
                    else // Enemy Chases Player
                    {
                        if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 3;
                        }
                        else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                        {
                            enemyArray[counter].direction = 4;
                        }
                        else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 1;
                        }
                        else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                        {
                            enemyArray[counter].direction = 2;
                        }
                    }
                    
                }
            }
            
            counter++;
        }
        
        
        
        
        
        // Projectile Collides with Enemy
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    if (projectileArray[counter].enemyProjectile == false)
                    {
                        soundCollision.setBuffer(bufferCollision);
                        soundCollision.play();
                        
                        projectileArray[counter].destroy = true;
                        
                        // Text Display
                        textDisplay1.text.setString(to_string(Player1.attackDamage));
                        textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x/2, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2);
                        textDisplayArray.push_back(textDisplay1);
                        
                        enemyArray[counter2].hp -= Player1.attackDamage;
                        if (enemyArray[counter2].hp <= 0)
                        {
                            enemyArray[counter2].alive = false;
                        }
                        
                        // Aggro
                        enemyArray[counter2].aggroed = true;
                    }
                }
                
                counter2++;
            }
            
            counter++;
        }
        
        
        // Enemy Projectile Collides with Player
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].enemyProjectile == true)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
                {
                    Player1.hp -= projectileArray[counter].attackDamage;
                    
                    // Text Display
                    textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2, Player1.rect.getPosition().y - Player1.rect.getSize().y/2);
                    textDisplayArray.push_back(textDisplay1);
                    
                    projectileArray[counter].destroy = true;
                }
            }
            
            counter++;
        }
        
        
        
        // Delete Dead Enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].alive == false)
            {
                int tempRandom = generateRandom(20);
                
                // Drop Coin
                if ((tempRandom >= 1) && (tempRandom <= 3))
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                // Drop Powerup
                if (tempRandom == 4)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = true;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop nova Powerup
                if (tempRandom == 5)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = true;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop Regular HP Potion
                if (tempRandom == 6)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Drop Uncommon HP Potion
                if (tempRandom == 7)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 2, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Killed Boss (Drops)
                if (enemyArray[counter].boss == true)
                {
                    pickup1.isCoin = true;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    
                    counter3 = 0;
                    while (counter3 <= 20)
                    {
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30),enemyArray[counter].rect.getPosition().y + generateRandom(30));
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30),enemyArray[counter].rect.getPosition().y - generateRandom(30));
                        pickupArray.push_back(pickup1);
                    
                        counter3++;
                    }
                }
                
                
                // Create Enemy Blood Stain
                blood1.rect.setPosition(enemyArray[counter].rect.getPosition());
                bloodArray.push_back(blood1);
                
                
                enemyArray.erase(enemyArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        // Delete Projectile
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].destroy == true)
            {
                projectileArray.erase(projectileArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        // Delete Text Display
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                textDisplayArray.erase(textDisplayArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        // Delete Pickup Items
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].destroy == true)
            {
                pickupArray.erase(pickupArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        // Delete Wall
        counter = 0;
        for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if (wallArray[counter].destroy == true)
            {
                int tempRandom = generateRandom(15);
                
                // Drop Coin
                if ((tempRandom >= 1) && (tempRandom <= 3))
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                // Drop Multiple Coins
                if (tempRandom >= 4)
                {
                    pickup1.isCoin = true;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureCoin);
                    pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-5,wallArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+5);
                    pickupArray.push_back(pickup1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+5,wallArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                    
                    if (generateRandom(5) == 1)
                    {
                        pickup1.isCoin = true;
                        pickup1.sprite.setTexture(textureCoin);
                        pickup1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                        pickup1.sprite.setScale(1, 1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-5,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+5);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+5,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-10,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+10);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+10,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x-15,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x,wallArray[counter].rect.getPosition().y+15);
                        pickupArray.push_back(pickup1);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition().x+15,wallArray[counter].rect.getPosition().y);
                        pickupArray.push_back(pickup1);
                    }
                }
                // Drop Powerup
                if (tempRandom == 5)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = true;
                    pickup1.isNovaPowerup = false;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
                    pickup1.sprite.setScale(1, 1);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop nova Powerup
                if (tempRandom == 6)
                {
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = true;
                    pickup1.sprite.setTexture(textureItems);
                    pickup1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                
                // Drop Regular HP Potion
                if (tempRandom == 7)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Drop Uncommon HP Potion
                if (tempRandom == 8)
                {
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(texturePotion);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 2, 32 * 3, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }

                // French Fries Food
                if (tempRandom == 9)
                {
                    pickup1.cost = 25;
                    pickup1.text.setString("Costs " + to_string(pickup1.cost));
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(textureFood);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 14, 32 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                // Hamburger Food
                if (tempRandom == 10)
                {
                    pickup1.cost = 50;
                    pickup1.text.setString("Costs " + to_string(pickup1.cost));
                    pickup1.inShop = false;
                    pickup1.isCoin = false;
                    pickup1.isPowerup = false;
                    pickup1.isNovaPowerup = false;
                    pickup1.isHPShield = false;
                    pickup1.isPotion = true;
                    pickup1.sprite.setTexture(textureFood);
                    pickup1.sprite.setTextureRect(sf::IntRect(32 * 13, 32 * 0, 32, 32));
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                    pickup1.inShop = false;
                    pickup1.isPotion = false;
                }
                
                
                
                
                
                
                wallArray.erase(wallArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        // Delete Enemy Blood Stain
        counter = 0;
        for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            if (bloodArray[counter].alive == false)
            {
                bloodArray.erase(bloodArray.begin() + counter);
                break;
            }
            
            counter++;
        }
        
        
        
        
        
        
        
        // Spawn Enemies (Y-Key)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(screenWidth), generateRandom(screenHeight));
            enemyArray.push_back(enemy1);
        }

        // Fires Missle (Space bar)
        if (elapsed1.asSeconds() >= Player1.attackSpeed)
        {
            clock.restart();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                soundShot.play();
                
                if (Player1.powerup == true) // Powerup Attack
                {
                    if (Player1.direction == 1) // UP
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 2) // Down
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 0);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 3) // Left
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 - 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    
                    if (Player1.direction == 4) // Right
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2 + 15,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 - 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                        
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2 + 15);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                }
                else if (Player1.novaAttack == true)
                {
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 1;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 2;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 3;
                    projectileArray.push_back(projectile1);
                    
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = 4;
                    projectileArray.push_back(projectile1);
                }
                else // Normal Attack
                {
                    projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                    projectile1.direction = Player1.direction;
                    projectileArray.push_back(projectile1);
                }
            }
        }
        
        // Update Player
        Player1.update();
        Player1.updateMovement();
        
        // Player View
        window.setView(view1);
        view1.setCenter(Player1.rect.getPosition());
        
        // Player Chicken catched text
        textChicken.setString("Galinhas restamtes : " + to_string(enemyArray.size()));
        window.draw(textChicken);
        textChicken.setPosition(Player1.rect.getPosition().x - screenWidth/2, Player1.rect.getPosition().y - screenHeight/2);

        // Player HP TEXT
        textHP.setString("Vida : " + to_string(Player1.hp) + "/" + to_string(Player1.maxhp));
        window.draw(textHP);
        textHP.setPosition(Player1.rect.getPosition().x - screenWidth/2, Player1.rect.getPosition().y - screenHeight/2 + 25);
        
        // Gil TEXT
        //text.setString("Moedas : " + to_string(Player1.gil) + "\nAttack Damage : " + to_string(Player1.attackDamage) + "\nAttack Speed : " + to_string(Player1.attackSpeed));
        text.setString("Moedas : " + to_string(Player1.gil));
        window.draw(text);
        text.setPosition(Player1.rect.getPosition().x - screenWidth/2, Player1.rect.getPosition().y - screenHeight/2 + 50);
}

/********************************************//**
* render the elements
***********************************************/
void
LevelScreen::Draw(sf::RenderWindow& window)
{
    /** Print the elements on the screen */

    // Set the view
    window.setView(view1);

    // Draw Ground
    counter = 0;
    for (iter25 = groundArray.begin(); iter25 != groundArray.end(); iter25++)
    {
        window.draw(groundArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Wall
    counter = 0;
    for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
    {
        wallArray[counter].update();
        
        window.draw(wallArray[counter].rect);
        window.draw(wallArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Enemy Dead Blood
    counter = 0;
    for (iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
    {
        bloodArray[counter].update();
        window.draw(bloodArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Pickup Items
    counter = 0;
    for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
    {
        if (pickupArray[counter].inShop == true)
        {
            window.draw(pickupArray[counter].text);
        }
        
        pickupArray[counter].update();
        //window.draw(pickupArray[counter].rect);
        window.draw(pickupArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Projectiles
    counter = 0;
    for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
    {
        projectileArray[counter].update(); // Update Projectile
        //window.draw(projectileArray[counter].rect);
        window.draw(projectileArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Enemies
    counter = 0;
    for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
    {
        enemyArray[counter].update();
        enemyArray[counter].updateMovement();
        //window.draw(enemyArray[counter].rect);
        window.draw(enemyArray[counter].sprite);
        
        counter++;
    }
    
    // Draw Enemies
    counter = 0;
    for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
    {
        enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].hp) + "/" + to_string(enemyArray[counter].maxhp));
        window.draw(enemyArray[counter].text);
        
        counter++;
    }

    // Draw Player
    window.draw(Player1.sprite);
    //window.draw(Player1.rect);
    
    // Draw Text
    counter = 0;
    for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
    {
        textDisplayArray[counter].update();
        window.draw(textDisplayArray[counter].text);
        
        counter++;
    }

    // Update the window
    //window.display();
}