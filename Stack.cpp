//
// Created by Kareem Nabulsi on 4/5/24.
//

#include "Stack.h"
#include <iostream>
#include "Operations.h"
using namespace std;

// constructor, added a length variable for ease of use
Stack::Stack() {
    top = nullptr;
    length = 0;
}

// deconstructor
Stack::~Stack() {
    // frees memory allocated by the constructor by deleting all nodes
    StackNode *nodePtr = top;
    StackNode *nextNode = nullptr;

    while(nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void Stack::push(string str) {
    // accepts and string argument which is pushed onto the top of the stack
    Operations o1;
    // check for blanks, low level validation
    while(o1.isBlank(str)) {
        cout << "Word cannot be blank. Try again." << endl;
        return;
    }
    while(str.length() > 10) {
        cout << "Word length cannot be greater than 10 characters. Try again." << endl;
        return;
    }
    if(isEmpty() == false) {
        // if stack is not empty, create a new node
        StackNode *newNode = new StackNode;
        // set the new node value to the string input from user
        newNode->value = str;
        // create a new nodeptr to point to the top
        StackNode *nodePtr = top;
        // set new node to point to the top aka the next one down the stack
        newNode->next = nodePtr;
        // reset top to the last node (newNode)
        top = newNode;
    }
    else {
        // if stack is not empty, create a new node and set the top to new node and set value to str
        StackNode *newNode = new StackNode;
        newNode->value = str;
        // change top from pointing to nullptr
        top = newNode;
    }
    length++;
}

// created another pop method here, one for storing what we are popping and one for not storing
void Stack::pop(string& str) {
    // uses a string reference parameter, value at the top of the stack is removed and copied into the reference parameter

    if(isEmpty() == false) {
        // call by reference will change str in main too
        // set str to the value of the top of the stack
        str = top->value;
        // create a ptr to point to top to store that value
        StackNode *nodePtr = top;
        // since we are tracing the top already, we can set top to be the next node
        top = nodePtr->next;
        // delete nodePtr aka the top of the stack
        delete nodePtr;
        length--;
    }
    else {
        // nothing to pop
        return;
    }

}

// method overloading here
void Stack::pop() {

    if(isEmpty() == false) {
        // same logic as above, just no str to mutate
        StackNode *nodePtr = top;
        top = nodePtr->next;
        delete nodePtr;
        length--;
    }
    else {
        return;
    }

}

bool Stack::isEmpty() {
    // returns true if empty, false if isnt
    if(top == nullptr) {
        return true;
    }
    return false;

}

void Stack::display() {
    // edge case
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    // set a ptr to the top
    StackNode *nodePtr = top;
    // iterate through the stack
    while(nodePtr->next != nullptr) {
        // print all nodes and iterate the ptr
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
    // catch the last node
    cout << nodePtr->value << endl;

}

void Stack::makeStory() {
    // edge case/low lvl validation
    if(getLength() < 5) {
        cout << "Stack needs at least 5 words stored to make a story. " << endl;
        return;
    }
    // instantiate string var
    string word;
    // word will get mutated here
    pop(word);
    // print with word being mutated
    cout << "In the heart of the " << word;
    pop(word);
    cout << " forest, a " << word << " was searching for the legendary ";
    pop(word);
    cout << word << ". After days of ";
    pop(word);
    cout << word << ", it stumbled upon a ";
    pop(word);
    cout << word << " clearing, where the mystery finally began.";
}

void Stack::capitalizeAll() {
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    StackNode *nodePtr = top;

    // iterate thru stack
    while(nodePtr != nullptr) {
        // grab value from stack
        string str = nodePtr->value;
        for(int i = 0; i < str.length(); i++) {
            // loop through string and set each char to uppercase
            str[i] = toupper(str[i]);
            // reset value to uppercase str
            nodePtr->value = str;
        }
        // iterate ptr
        nodePtr = nodePtr->next;
    }

}

// getter
int Stack::getLength() {
    return length;
}




