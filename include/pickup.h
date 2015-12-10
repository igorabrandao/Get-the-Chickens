/*! \brief Class pickup.h.
 *
 *  Handle the fade animation.
*/
#ifndef PICKUP_H
#define PICKUP_H

#include "entity.h"

/*! pickup class */
class pickup: public entity
{
    /*!
     * Public section
    */
    public:

        bool isCoin = false;
        bool isPowerup = false;
        bool isNovaPowerup = false;
        bool isHPShield = false;
        bool isPotion = false;
        int coinValue = 5;
        bool destroy = false;
        bool inShop = false;
        int cost = 30;
        
        pickup();
        void update();
};

#endif // PICKUP_H