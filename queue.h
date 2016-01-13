/**
 ADS Project 1
 queue.h
 Purpose: Provides an interface for a circular queue based on an array.
 
 @author Terek Arce
 @version 2.0 1/7/16
 */

#pragma once

using namespace std;

template <class T>
class Queue {
    int head_;
    int tail_;
    int size_;
    T *arr_;
	public:
    Queue(int theSize = 10);
    ~Queue();
    bool Empty() const;
    void Add(const T& element);
    T& Peek() const;
    T& Remove();
};

#include "queue.cpp"