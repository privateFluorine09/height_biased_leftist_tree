#include <iostream>

#include "queue_tests.h"
#include "hblt_tests.h"

using namespace std;

int main (int argc, char *argv[]) {
    
    if (!test_1() &&
        !test_2() &&
        !test_3() &&
        !test_4() &&
        !test_5() &&
        !test_6() ) {
        cout << "Test Failed." << endl;
        return 1;
    }
    cout << "Tests passed." << endl;
    
    if (!MinHbltTest1()) {
        cout << "MinHblt tests failed." << endl;
        return 1;
    }
    cout << "MinHblt tests passed." << endl;
    
    return 0;

}