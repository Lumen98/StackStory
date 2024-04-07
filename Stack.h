//
// Created by Kareem Nabulsi on 4/5/24.
//

#ifndef STACKSTORY_STACK_H
#define STACKSTORY_STACK_H
#include <iostream>
using namespace std;


class Stack {

private:
    struct StackNode
    {
        string value; // value in node
        StackNode *next; // pointer to next node
    };
    StackNode *top; // pointer to stack top
    int length;
public:
    // constuctor
    Stack();
    // destructor
    ~Stack();

    // stack operations
    void push(string str);
    void pop();
    bool isEmpty();
    void display();
    void makeStory();
    void capitalizeAll();
    int getLength();

};


#endif //STACKSTORY_STACK_H
