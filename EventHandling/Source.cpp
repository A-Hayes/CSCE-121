#include <ctime>
#include "ColorWindow.h"

using namespace std;

int getRandomColor() {
	return (rand() % 12) +1;
}

int main(int argc, char **argv) {
	srand(time(NULL));
	ColorWindow* win = new ColorWindow();

	win->show(argc, argv);
	return Fl::run();
}