#ifndef COLORWINDOW_H
#define COLORWINDOW_H

#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "ColorButton.h"

class ColorWindow : public Fl_Window {
	ColorButton* buttonOne;
	ColorButton* buttonTwo;
	Fl_Box* countOne;
	std::string labelOne;
	Fl_Box* countTwo;
	std::string labelTwo;
	Fl_Box* countAllButtons;
	std::string labelCountAll;

public:
	ColorWindow();
	void updateLabelClickCount(ColorButton* which); // pass in the label from the button
	void updateLabelCountAll();
	void processClick(ColorButton*);
};

#endif