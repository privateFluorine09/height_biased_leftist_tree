/**
 ADS Project 1
 queue.cpp
 Purpose: Provides method definitions for queue.
 
 @author Terek Arce
 @version 2.0 1/7/16
 */

#include <sstream>

#include "queue.h"
#include "exceptions.h"

using namespace std;

/**
 Initializes this queue.
 
 @param size The initial size of the queue
 */
template <class T>
Queue <T>::Queue(int size) {
    if (size < 1) {
        ostringstream s;
        s << "Initial capacity = " << size << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    size_ = size;
    arr_ = new T[size_];
    head_ = 0;
    tail_ = 0;
}

/**
 Destroys this queue.
 */
template <class T>
Queue <T>::~Queue() {
    delete [] arr_;
}
/**
 Returns true if this queue contains no elements.
 
 @return True if this queue contains no elements
 */
template <class T>
bool Queue <T>::Empty() const {
    return head_ == tail_;
}

/**
 Inserts the specified element into this queue.  Doubles the queue size if it violates capacity restrictions and adds the element.
 
 @param element The element to be pushed into the tail_ of the queue
 */
template <class T>
void Queue <T>::Add(const T& element) {
    // if the queue is full, double its size_
    if ((tail_ + 1) % size_ == head_) {
        T* newArr = new T[2 * size_];
        int start = (head_ + 1) % size_;
        if (start < 2) {
            copy(arr_ + start, arr_ + start + size_ - 1, newArr);
        }
        else {
            copy(arr_ + start, arr_ + size_, newArr);
            copy(arr_, arr_ + tail_ + 1, newArr + size_ - start);
        }
        head_ = 2 * size_ - 1;
        tail_ = size_ - 2;
        size_ *= 2;
        arr_ = newArr;
    }
    tail_ = (tail_ + 1) % size_;
    arr_[tail_] = element;
}

/**
 Retrieves, but does not remove, the head of this queue. Throws an exception if this queue is empty.
 
 @return Element at the head of the queue
 */
template <class T>
T& Queue <T>::Peek() const{
    if (head_ == tail_)
      throw queueEmpty();
    return arr_[(head_ + 1) % size_];
}

/**
 Retrieves and removes the head of this queue. Throws an exception if this queue is empty.
 */
template <class T>
T& Queue <T>::Remove() {
    if (head_ == tail_)
        throw queueEmpty();
    head_ = (head_ + 1) % size_;
    T& element = arr_[head_];
    arr_[head_].~T();
    return element;
}