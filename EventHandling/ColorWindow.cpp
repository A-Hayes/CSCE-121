#include <iostream>
#include "ColorWindow.h"

using namespace std;

int getRandomColor();

/*
  CALLBACK FIXME 1: Complete the buttonCallback() function.
    Don't forget to add the parameters.
	
	Parameters:
		Recall that in FLTK the callback parameters datatypes are always 
	      exactly the same.
	
		First parameter:
		  a pointer that can be dynamic_cast to a ColorButton
		Second parameter:
		  a pointer that can be static_cast to a ColorWindow
	  
	Body:
		Can be done in 3 lines of code.
	
		1. Cast parameters to pointers of their derived types.
		   (2 lines of code)
	
		2. Call processClick on the window since private data members
			need to be changed, but are not accessible in this function.
			Since processClick is in the ColorWindow class, it will
			have access to any private data members that need to be updated.
			You'll need to pass in the pointer to the ColorButton.
*/

void buttonCallback() {
	
}

/*
	CALLBACK FIXME 2: Complete the processClick function.
	Do the expected updates.
	
	1. Set the window's background color to a randomly generated 
        color obtained by calling getRandomColor()
	    (Look in the constructor for an example of how to do this.)
	   
	2. Call updateLabelClickCount to update the label for 
	    the number of times the button has been clicked. Pass in 
		the pointer to the instance of the ColorButton being used.
		
	3. Call updateLabelCountAll to update the shared variable that
	    holds the number of times all buttons of the ColorButton
		class have been clicked.
		
	4. Output to the console which button has been pressed. You can 
	    get the specific button by accessing its label. See the
		updateLabelClickCount function for an example of how.
	
	5. Inform FLTK that this widget has changed and needs to be
	    drawn again when drawing occurs.
*/

void ColorWindow::processClick(ColorButton* cb) {
}

ColorWindow::ColorWindow() :
	Fl_Window(350, 350) {
	this->color(getRandomColor());

	buttonOne = new ColorButton(50, 50, 100, 50, "One");
	this->countOne = new Fl_Box(225, 50, 50, 50);
	this->labelOne = "0";
	countOne->label(labelOne.c_str());
	countOne->labelfont(FL_BOLD);
    countOne->labelsize(36);

	buttonTwo = new ColorButton(50, 150, 100, 50, "Two");
	this->countTwo = new Fl_Box(225, 150, 50, 50);
	this->labelTwo = "0";
	countTwo->label(labelTwo.c_str());
	countTwo->labelfont(FL_BOLD);
    countTwo->labelsize(36);

	this->countAllButtons = new Fl_Box(225, 250, 50, 50);
	this->labelCountAll = "0";
	countAllButtons->label(labelCountAll.c_str());
	countAllButtons->labelfont(FL_BOLD);
    countAllButtons->labelsize(36);
	
	/*
	  CALLBACK FIXME 3
	  Register a callback with buttonOne and buttonTwo
	    with buttonCallback (from FIXME 1a) as the first parameter 
		and this instance of ColorWindow as the second parameter
		  (What is the implicit parameter called for _this_ instance?)
	*/
         

	this->end();
}

void ColorWindow::updateLabelClickCount(ColorButton* cb) { 
	// pass in the label from the button
	if (cb->label() == "One") {
		labelOne = to_string(cb->getClickCount());
		cout << "One pressed" << endl;
		countOne->label(labelOne.c_str());
		countOne->redraw();
	}
	if (cb->label() == "Two") {
		labelTwo = to_string(cb->getClickCount());
		cout << "Two pressed" << endl;
		countTwo->label(labelTwo.c_str());
		countTwo->redraw();
	}
}

void ColorWindow::updateLabelCountAll() {
	labelCountAll = to_string(ColorButton::getClickCountAll());
	countAllButtons->label(labelCountAll.c_str());
	countAllButtons->redraw();
}