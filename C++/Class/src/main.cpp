#include <iostream>
#include "test.h"

using namespace std;

int main(int, char**) {
    VESC_PACKET vp;

    vesc.amp_hours = 10.01;

    cout << vesc.duty <<vesc.amp_hours;

    return 0;
}
