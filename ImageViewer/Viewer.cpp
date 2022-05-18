#include <iostream>
#include "Viewer.h"

using namespace std;

void buttonCallback(Fl_Widget* widget, void* viewerPtr) {
	cout << "Callback called" << endl;
	Viewer* viewer = static_cast<Viewer*>(viewerPtr);
	NavButton* b = dynamic_cast<NavButton*>(widget);
	viewer->navPressed(b); 
	/* you can name this whatever you want, the idea is to call a 
	     member function in the viewer class that does what is needed
	     to update the image. You'll pass in the widget (you can also
	     dynamic cast it to a NavButton before passing it). From the
	     widget the function can determine whether to move forward
	     or backward in the list.
	*/
}

void Viewer::navPressed(NavButton* cb) {
	bool forward;
	int nextIndex, prevIndex;
	if(cb->getLabel() == "Previous Button"){	// previous button
		forward = false;
	}else{
		forward = true;
	}
	
	if(!forward){
		if(currentIndex == 0){				// if index is 0 and we try to go back, current index goes to the end of the array
			this->currentIndex = imageFilenames.size() - 1;
		}else{		//else, it decrements
			this->currentIndex--;
		}
	}else{
		if(currentIndex == imageFilenames.size() - 1){	// if index is max and we try to go forward, current inde goes to start of array
			this->currentIndex = 0;
		}else{		// else, it increments
			this->currentIndex++;
		}
	}

	if(currentIndex == 0){
		prevIndex = imageFilenames.size() - 1;
	}else{
		prevIndex = currentIndex - 1;
	}
	
	if(currentIndex == imageFilenames.size() - 1){
		nextIndex = 0;
	}else{
		nextIndex = currentIndex + 1;
	}
	
	next->setImage(getPathFilename(imageFilenames[nextIndex], true));
	prev->setImage(getPathFilename(imageFilenames[prevIndex], true));

	next->redraw();
	prev->redraw();

	this->redraw();
	delete pic;
	pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str()); 
	imageBox->image(pic);
	imageBox->redraw();
}

Viewer::Viewer(string imageFolder, vector<string> imageFilenames, int width = 800, int height = 600) :
	Fl_Window(width, height, "Image Viewer"), imageFolder(imageFolder), imageFilenames(imageFilenames), currentIndex(0),
	prev(nullptr), next(nullptr), imageBox(nullptr), pic(nullptr) {
  	prev = new NavButton(getPathFilename(imageFilenames.at(imageFilenames.size()-1), true),
		"Previous Button",
		borderSize,
		this->h() - borderSize - thumbnailSize - borderSize,
		thumbnailSize, imageFilenames.size() - 1);
	next = new NavButton(getPathFilename(imageFilenames.at((imageFilenames.size()+1)%imageFilenames.size()), true),
		"Next Button", 
		this->w() - borderSize - thumbnailSize - borderSize,
		this->h() - borderSize - thumbnailSize - borderSize, 
		thumbnailSize, imageFilenames.size()-1);
	imageBox = new Fl_Box(borderSize, 
		borderSize, 
		this->w() - (2*borderSize), 
		this->h() - (2*borderSize) - thumbnailSize - 2*borderSize);
	//imageBox->box(FL_BORDER_BOX); // useful to see where the full size of the widget holding the images
	
	prev->callback(buttonCallback, static_cast<void*>(this));
	next->callback(buttonCallback, static_cast<void*>(this));
	
	pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
	
	imageBox->image(pic);
	
	this->end();
}

string Viewer::getPathFilename(string filename, bool thumb) {
	string thumbPart = "";
	if (thumb) thumbPart = "t_";
	return imageFolder + "/" + thumbPart+ filename;
}

