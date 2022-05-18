#include <iostream>
#include "ColorButton.h"

using namespace std;

int getRandomColor();

int ColorButton::clickCountAllButtons = 0; //initialize 

ColorButton::ColorButton(int x, int y, int width, int height, 
    const char *L = 0) : Fl_Button(x, y, width, height, L), clickCount(0) {
	this->color(getRandomColor());
	this->labelsize(36);
	this->labelfont(FL_HELVETICA_BOLD);
}

int ColorButton::getClickCount() { return clickCount; }

int ColorButton::getClickCountAll() { return clickCountAllButtons; }

/*
	HANDLE FIXME 2:
	Write the handle function.
	See slides, example, and FLTK documentation for the structure.
	
	1. When the event is FL_RELEASE
	    a. Increment all click counts (i.e. the one for this instance,
		    and the shared one.)
			
		b. Set the button's background color to a randomly generated 
            color obtained by calling getRandomColor()
	        (Look in the constructor for an example of how to do this.)
		
		c. Inform FLTK that this widget has changed and needs to be
	        drawn again when drawing occurs.
			
		d. In the console, output which button is being pressed 
		    and the number of times the button has been pressed. 
			 - You can use this->label() 
			    to get the button text "One" or "Two".
			 - Your console message should be similar to: 
			    "Button One pressed 4 times!"
			
		e. Return the value obtained by calling the parent's handle.
		    This will allow the parent to complete animations and call
			any callbacks if needed.
	
	2. For any other event type (i.e. default), return the value obtained by
	    calling the parent's handle.
		  - You can call the parent's handle using scope resolution 
		    with the parent class. E.g. Fl_Button::handle(event).
*/
	


 
 