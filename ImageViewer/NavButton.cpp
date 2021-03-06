#include <iostream>
#include "NavButton.h"
#include "Viewer.h"
using namespace std;

NavButton::NavButton(string imageFilename, string label, int x, int y, int thumbnailsize, int imageIndex, const char *L) :
	Fl_Button(x, y, 1, 1, L), clickCount(0), label(label), thumbnailsize(thumbnailsize), imageLabel(nullptr) {
	setImage(imageFilename);
}

string NavButton::getLabel() const {
	return label;
}

void NavButton::setImage(string filename) {
	delete imageLabel;
	imageLabel = new Fl_JPEG_Image(filename.c_str());
	imageLabel->copy(thumbnailsize, thumbnailsize);
	image(imageLabel);
	this->resize(this->x(), this->y(), thumbnailsize + Viewer::borderSize, thumbnailsize + Viewer::borderSize);
}

int NavButton::totalClicks = 0;

int NavButton::handle(int event) {
	switch (event) {
		case FL_RELEASE:
			this->clickCount++;
			this->totalClicks++;
			this->redraw();
			
			cout << this->getLabel() << " has been pressed " << this->clickCount << " times." << endl;
			
			cout << "All buttons have been pressed " << this->totalClicks << " times." << endl;
			return Fl_Button::handle(event);
		default:
			return Fl_Button::handle(event);
	}
}