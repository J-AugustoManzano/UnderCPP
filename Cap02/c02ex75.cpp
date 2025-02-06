// c02ex75.cpp

#include <iostream>
#include <limits>
#include <print>

int64_t fatorial(int16_t n) {
    int64_t fat = 1;

    for (int16_t i = 1; i <= n; ++i) {
       fat *= i;
    }
    return fat;
}

int main(void) {
    int16_t x;

    std::println("CALCULO DE FATORIAL");
    std::println("-------------------");
    std::println("");

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("Fatorial de {} = {}", x, fatorial(x));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
