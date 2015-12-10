/*! \brief Class Enemy.h.
 *
 *  Handle enemy screen issues.
*/
#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "random.h"

/*! enemy class */
class enemy : public entity
{
    public:

        int movementSpeed = 3;
        int movementLength = 100;
        int attackDamage = 2;
        int counterWalking = 0;
        int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
        int counter = 0;
        int hp = 3;
        int maxhp = 3;
        bool alive = true;
        bool canMoveUp = true;
        bool canMoveDown = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;
        bool isBlood = false;
        int bloodCounter = 0;
        int bloodLifetime = 400;
        int spritex = 32;
        int spritey = 32;
        int spritexStart = 32 * 0;
        int spriteyStart = 32 * 0;
        bool aggroed = false;
        bool boss = false;

        enemy();
        void update();
        void updateMovement();
        void isUnwrappedMummyGoblin(int counter, int counter2, float x, float y);
        void isGoblin(int counter, int counter2, float x, float y);
        void isArmouredGoblin(int counter, int counter2, float x, float y);
        void isRobedGoblin(int counter, int counter2, float x, float y);
        void isLeaderGoblin(int counter, int counter2, float x, float y);
        void isWrappedMummyGoblin(int counter, int counter2, float x, float y);
};

#endif // ENEMY_H