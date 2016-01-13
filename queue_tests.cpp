/**
 ADS Project 1
 queue_tests.cpp
 Purpose: Implementation of test methods for the queue classes.
 
 @author Terek Arce
 @version 2.0 1/7/16
 */

#include <iostream>

#include "queue.h"
#include "exceptions.h"

using namespace std;

/**
 Returns true if a illegalParameterValue exception is successfully thrown for the queue.
 
 @return True if this test passed
 */
bool test_1() {
    bool passed = false;
    try {
        Queue<int> q (0);
    }
    catch (illegalParameterValue& e){
        passed = true;
    }
    if (!passed)
    	cout << "Test 1: failed" << endl;
    return passed;
}

/**
 Returns true if queue of size one with one element is successfully created.
 
 @return True if this test passed
 */
bool test_2() {
    bool passed = false;
    Queue<int> q (1);
    q.Add(1);
    if ( q.Peek() == 1) {
        passed = true;
    }
    if (!passed)
        cout << "Test 2: failed" << endl;
    return passed;
}

/**
 Returns true if queue size dobules successfully.
 
 @return True if this test passed
 */
bool test_3() {
    bool passed = false;
    Queue<int> q (1);
    q.Add(1);
    q.Add(2);
    if ( q.Peek() == 1) {
        passed = true;
    }
    if (!passed)
        cout << "Test 3: failed" << endl;
    return passed;
}

/**
 Returns true if queue size doubles successfully.
 
 @return True if this test passed
 */
bool test_4() {
    bool passed = false;
    Queue<int> q (1);
    q.Add(1);
    q.Add(2);
    q.Remove();
    if ( q.Remove() == 2) {
        passed = true;
    }
    if (!passed)
        cout << "Test 4: failed" << endl;
    return passed;
}

/**
 Returns true if queue is empty.
 
 @return True if this test passed
 */
bool test_5() {
    bool passed = false;
    Queue<int> q;
    if (q.Empty()) {
        passed = true;
    }
    if (!passed)
        cout << "Test 5: failed" << endl;
    return passed;
}

/**
 Returns true if a queueEmpty exception is successfully thrown for the queue.
 
 @return True if this test passed
 */
bool test_6() {
    bool passed = false;
    Queue<int> q;
    try {
        q.Peek();
    }
    catch (queueEmpty& e){
        passed = true;
    }
    if (!passed)
        cout << "Test 6: failed" << endl;
    return passed;
}
