/*! \brief Class projectile.h.
 *
 *  Handle the projectile issues.
*/
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

/*! projectile class */
class projectile : public entity
{
    /*!
     * Public section
    */
    public:

        int movementSpeed = 4;
        int attackDamage = 1;
        int lifeTime = 150;

        int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
        bool destroy = false;
        int counterLifetime = 0;
        int counterAnimation = 0;
        bool enemyProjectile = false;
        bool randomDirection = false;
        float randomx = 0;
        float randomy = 0;

        projectile();
        void update();
};

#endif // PROJECTILE_H