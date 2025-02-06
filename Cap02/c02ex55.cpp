// c02ex55.cpp

#include <iostream>
#include <print>

int main(void) {
    for (int16_t i = 1; i <= 10; std::println("i = {:>2}", i++)) {}

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

