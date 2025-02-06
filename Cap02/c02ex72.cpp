// c02ex72.cpp

#include <iostream>
#include <limits>
#include <print>

void incremento(void) {
    static int16_t r = 1;
    std::println("{:>2}", r);
    ++r;
}

int main(void) {
    for (int16_t i; i <= 10; ++i) {
        incremento();
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
