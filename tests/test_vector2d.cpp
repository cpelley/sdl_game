#include<iostream>

#include "test.h"
#include "../vector2d.h"


void test_length() {
    Vector2D vec {1., 2.};
    float result=vec.length();
    float target=2.23607;
    assert_almost_equal(result, target, 1e-5);
}


int main(int argc, char* args[]) {
    test_length();
}
