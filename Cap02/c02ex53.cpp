// c02ex53.cpp

#include <iostream>
#include <print>

int main(void) {
    for (int16_t i = 1, j = 10; i <= j; ++i, --j) {
        std::println("i = {:>2} e j = {:>2}", i, j);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
