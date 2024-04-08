#include <iostream>
#include <string>
#include "DisplayMenu.h"
#include "Stack.h"
#include <iomanip>
#include <limits>
#include <string.h>
#include "Operations.h"
using namespace std;


int main() {
    int menuChoice; // make a menuchoice var
    DisplayMenu m1; // create new objects
    Stack s1;
    Operations o1;

    do {
        m1.displayMenuFirstMsg();
        // get the user's menu choice
        while (!(cin >> menuChoice)) {
            // validate that the input is a number
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a number only please. " << endl;
        }

        // switch to handle the user's choice.
        string input;
        switch (menuChoice) {
            case 1: {
                // ws --> clears leading white space chars
                cout << "Please enter the word you want to push: " << endl;
                getline(cin >> ws, input); // use getline here because words can have spaces

                // high level validation
                while(o1.isBlank(input)) {
                    cout << "Word cannot be blank. Try again." << endl;
                    getline(cin >> ws, input);
                }
//                while(o1.allLetters(input)) {
//                    cout << "Word cannot have numbers. Try again." << endl;
//                    getline(cin >> ws, input);
//                }
                // high level validation again, separated input fail statements for user
                while(input.length() > 10) {
                    cout << "Word length cannot be greater than 10 characters. Try again." << endl;
                    getline(cin >> ws, input);
                }
                cout << endl;

                // once input is validated, call method
                cout << "Pushing..." << endl;
                s1.push(input);
                cout << "**Push Complete**." << endl;
                break;
            }
            case 2: {
                // check if stack is empty
                if(!s1.isEmpty()) {
                    // if not, pop
                    s1.pop();
                }
                else {
                    cout << "Stack is empty. " << endl;
                }
                break;
            }

            case 3: {
                if(!s1.isEmpty()) {
                    s1.capitalizeAll();
                }
                else {
                    cout << "Stack is empty. " << endl;
                }
                break;
            }
            case 4: {
                s1.display();
                break;
            }
            case 5: {
                if(s1.getLength() >= 5) {
                    s1.makeStory();
                }
                else {
                    cout << "Stack needs at least 5 words stored to make a story. " << endl;
                }
                break;
            }
            case 6: {
                // print exit statement
                cout << "Exiting..." << endl;
                cout << "Thanks for using the menu system and have a nice day." << endl;
                exit(0);
            }
            default: {
                // handle invalid menu option entries
                cout << "That Is Not A Valid Option, Please Choose An Option From The Numbered Menu Below: "
                     << endl;
                cout << endl;
                break;
            }
        }

    } while (menuChoice != 6); // continue presenting the menu until the user chooses to exit
    return 0;
}