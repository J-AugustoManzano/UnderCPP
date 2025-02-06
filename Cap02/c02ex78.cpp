// c02ex78.cpp

#include <iostream>
#include <limits>
#include <print>

int64_t fatorial(int16_t n) {
    if (n == 0) {
       return 1;
    } else {
       return n * fatorial(n - 1);
    }
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
