/**
 ADS Project 1
 exceptions.h
 Purpose: Exception classes for various error types.
 
 @author Terek Arce
 @version 2.0 1/7/16
 */

#pragma once

#include <string>
#include <iostream>

using namespace std;

// illegal parameter value
class illegalParameterValue {
    string message;
	public:
    illegalParameterValue(string error = "Illegal parameter value") {message = error;}
    void outputMessage() {cout << message << endl;}
};

// illegal input data
class illegalInputData {
    string message;
  public:
    illegalInputData(string error = "Illegal data input") {message = error;}
    void outputMessage() {cout << message << endl;}
};

// illegal index
class illegalIndex {
    string message;
	public:
    illegalIndex(string theMessage = "Illegal index") {message = theMessage;}
    void outputMessage() {cout << message << endl;}
};

// queue Empty
class queueEmpty {
    string message;
  public:
    queueEmpty(string theMessage = "Invalid operation on empty queue") {message = theMessage;}
    void outputMessage() {cout << message << endl;}
};