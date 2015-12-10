/*! \brief Class textDisplay.h.
 *
 *  Handle the screen texts issues.
*/
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "entity.h"

/*! textDisplay class */
class textDisplay : public entity
{
	/*!
     * Public section
	*/
	public:

	    float movementSpeed = 2;
	    string myString = "Default";
	    int counter = 0;
	    int lifeTime = 100;
	    bool destroy = false;
	    
	    textDisplay();
	    void update();
};

#endif // TEXTDISPLAY_H