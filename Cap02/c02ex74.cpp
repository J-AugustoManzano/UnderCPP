// c02ex74.cpp

#include <iostream>
#include <limits>
#include <print>

void fatorial(int16_t n, int64_t &fat) {
    for (int16_t i = 1; i <= n; ++i) {
       fat *= i;
    }
}

int main(void) {
    int16_t x;
    int64_t resultado = 1;

    std::println("CALCULO DE FATORIAL");
    std::println("-------------------");
    std::println("");

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fatorial(x, resultado);
    std::println("Fatorial de {} = {}", x, resultado);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
