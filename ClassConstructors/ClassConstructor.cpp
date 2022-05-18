//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                        CLASS CONSTRUCTORS LAB                            //
//                               MAIN.CPP                                   //
//                                                                          //
//  Date ...: 18/MAR/2017                                                   //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                  Includes                                //
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <limits>
#include "Color.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////////
//                                      main                                //
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    string prompt = "Please enter the r, g, and b integer values of a color, with each separated by a space (e.x., \"255 255 255\")(CTRL-D to exit) : ";
    // Part 1
    Color color;
    cout << "Color values after declaration : " << color.to_str() << endl;
    cout << prompt;
    for (int r, g, b ; ; ) {
        while (!(cin >> r >> g >> b)) {
            if (cin.bad() || cin.eof()) {
                return 1;
            } else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Invalid input." << endl << endl << prompt;
            cin >> r >> g >> b;
        }
        color.set_R(r); color.set_G(g); color.set_B(b);
        cout << "Color : " << color.to_str() << endl << endl;
        cout << prompt;
    }
    /*
    // Part 2
    cout << prompt;
    for (int r, g, b ;  ; ) {
        while (!(cin >> r >> g >> b)) {
            if (cin.bad() || cin.eof()) {
                return 1;
            } else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Invalid input." << endl << endl << prompt;
            cin >> r >> g >> b;
        }
        Color color(r, g, b);
        cout << "Color : " << color.to_str() << endl << endl;
        cout << prompt;
    }
    */
    return 0;
}