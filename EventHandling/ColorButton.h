#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <FL/Fl.H>
#include <FL/Fl_Button.H>

class ColorButton : public Fl_Button {
	int clickCount;
	static int clickCountAllButtons;
	// shared click count for all instances of this button

public:
	ColorButton(int x, int y, int width, int height, const char *L);
	
	int getClickCount();
	static int getClickCountAll();
	
/*
	HANDLE FIXME 1:
	Declare the handle function.
	Refer to slides and example for more information.
	Recall that FLTK event handle declarations are all exactly the same.
*/
	
};


#endif