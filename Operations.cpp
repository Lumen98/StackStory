//
// Created by Kareem Nabulsi on 4/6/24.
//

#include "Operations.h"
#include <iostream>
using namespace std;



//bool Operations::allLetters(string str) {
//    //loop thru each character in the string
//    for (char c : str) {
//        //use a static cast to an unsigned char to avoid errs and see if it is numeric or alphabetic using isalpha
//        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
//            return false;
//        }
//    }
//    return true;
//}

// check for input blanks
bool Operations::isBlank(string str) {
    if(str == "") {
        return true;
    }
    bool blank = false;
// if first char is a space then its blank
        if(str[0] == ' ') {
            blank = true;
        }
        else {
            blank = false;
        }

    return blank;
}