// c02ex51.cpp

#include <iostream>
#include <print>

int main(void) {
    for (int16_t i = 10; i >= 1; --i) {
        std::println("{:>2}", i);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
