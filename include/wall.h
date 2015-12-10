/*! \brief Class wall.h.
 *
 *  Handle walls issues.
*/
#ifndef WALL_H
#define WALL_H

#include "entity.h"

/*! wall class */
class wall: public entity
{
	/*!
     * Public section
	*/
	public:

	    bool destructable = false;
	    int hp = 50;
	    bool destroy = false;

	    wall();
	    void update();
};


#endif // WALL_H
