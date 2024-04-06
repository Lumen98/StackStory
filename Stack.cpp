//
// Created by Kareem Nabulsi on 4/5/24.
//

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
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

}


void Stack::pop(string &str) {
    // uses a string reference parameter, value at the top of the stack is removed and copied into the reference parameter

    if(isEmpty() == false) {
        StackNode *nodePtr = top;
        top = nodePtr->next;
        delete nodePtr;
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


