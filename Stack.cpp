//
// Created by Kareem Nabulsi on 4/5/24.
//

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
    length = 0;
}

Stack::~Stack() {
    // frees memory allocated by the constructor
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

    if(isEmpty() == false) {
        StackNode *newNode = new StackNode;
        newNode->value = str;
        StackNode *nodePtr = top;
        newNode->next = nodePtr;
        top = newNode;
    }
    else {
        StackNode *newNode = new StackNode;
        newNode->value = str;
        top = newNode;
    }
    length++;

}


void Stack::pop() {
    // uses a string reference parameter, value at the top of the stack is removed and copied into the reference parameter

    if(isEmpty() == false) {
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
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    StackNode *nodePtr = top;
    while(nodePtr->next != nullptr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
    cout << nodePtr->value << endl;

}

void Stack::makeStory() {
    if(getLength() < 5) {
        cout << "Stack needs at least 5 words stored to make a story. " << endl;
        return;
    }
    string word = top->value;
    pop();
    cout << "In the heart of the " << word;
    word = top->value;
    pop();
    cout << " forest, a " << word << " was searching for the legendary ";
    word = top->value;
    pop();
    cout << word << ". After days of ";
    word = top->value;
    pop();
    cout << word << ", it stumbled upon a ";
    word = top->value;
    pop();
    cout << word << " clearing, where the mystery finally began.";
}

void Stack::capitalizeAll() {
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    StackNode *nodePtr = top;

    while(nodePtr != nullptr) {
        string str = nodePtr->value;
        for(int i = 0; i < str.length(); i++) {
            str[i] = toupper(str[i]);
            nodePtr->value = str;
        }
        nodePtr = nodePtr->next;
    }

}

int Stack::getLength() {
    return length;
}




