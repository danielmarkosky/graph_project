#include <iostream>

#include "../src/utils.h"

int main() {
    std::cout << "Duck Hello :> SANDBOX" << std::endl;

    int duck = 0;
    for (int ii = 0; ii < 1000; ii++) {
        if (duck::chance_with_probability(0.5)) {
            duck++;
        }
    }
    std::cout << "Duck: " << duck << std::endl;
}