/*! \brief Class player.h.
 *
 *  Handle the player issues.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

/*! player class */
class player : public entity
{
    /*!
     * Public section
    */
    public:

        int movementSpeed = 5;
        float attackSpeed = 0.3;
        int attackDamage = 5;
        bool powerup = false;
        bool novaAttack = false;
        int counterWalking = 0;
        int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
        bool canMoveUp = true;
        bool canMoveDown = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;
        int hp = 10;
        int maxhp = 10;
        int gil = 100;
        
        player();
        void update();
        void updateMovement();
};

#endif // PLAYER_H
