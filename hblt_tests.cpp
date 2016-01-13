/**
 ADS Project 1
 hblt_tests.cpp
 Purpose: Implementation of test methods for a 
 Min Height-biased leftist tree.
 
 @author Terek Arce
 @version 2.0 1/13/16
 */

#include <iostream>

#include "min_hblt.h"
#include "exceptions.h"

bool MinHbltTest1() {
    bool passed = false;
    MinHblt<int> h;
    int a[6] = {0, 7, 9, 1, 8, 11};
    h.Initialize(a,5);
    return passed;
}
/**
bool MinHbltTest2() {
    
}

bool MinHbltTest3() {
    
}

bool MinHbltTest4() {
    
}

bool MinHbltTest5() {
    
}

bool MinHbltTest6() {
    
}

bool MinHbltTest7() {
    
}
*/