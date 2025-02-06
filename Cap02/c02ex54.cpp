// c02ex54.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t j = 10;

    for (int16_t i = 1; i <= 5; ++i) {
        std::println("I = {:>2} e j = {:>2}", i, j);
        --j; // Decrementa j para acompanhar o valor equivalente
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
