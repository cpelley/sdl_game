#include<iostream>
#include <stdexcept>
#include <cmath>


template <typename T>
T assert_equal(const T& var_a, const T& var_b) {
    if (var_a != var_b) {
        std::cout << var_a << " != " << var_b << std::endl;
        throw std::domain_error("Variables are not equal");
    }
}


template <typename T>
T assert_almost_equal(const T& var_a, const T& var_b, const float tolerance=1e-4) {
    T var_c;
    var_c = std::abs(var_a - var_b);
    if (var_c > tolerance) {
        std::cout << var_a << " != " << var_b << " (abs. diff. " << var_c <<
            " > " << tolerance << ")" << std::endl;
        throw std::domain_error("Variables are not equal");
    }
}
