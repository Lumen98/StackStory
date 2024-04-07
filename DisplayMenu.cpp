//
// Created by Lumen on 3/21/24.
//

#include "DisplayMenu.h"
#include <iostream>
#include <cctype>

using namespace std;

//separated this for organization
void DisplayMenu::displayMenuFirstMsg() {
    cout << "**** Stack Menu ****" << endl;
    cout << "1.  Push (a word onto the stack) " << endl;
    cout << "2.  Pop (a word off the stack) " << endl;
    cout << "3.  Capitalize all of the words on the stack " << endl;
    cout << "4.  Display Stack " << endl;
    cout << "5.  Make a Story " << endl;
    cout << "6.  Exit" << endl;
    cout << endl;
    cout << "Please Enter Your Menu Choice: ";
    cout << endl;
}


