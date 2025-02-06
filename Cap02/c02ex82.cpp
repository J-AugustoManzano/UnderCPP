// c02ex82.cpp

#include <iostream>
#include <limits>
#include <print>

void inline fatorial(int16_t n) {
    int64_t fat = 1;

    for (int16_t i = 1; i <= n; ++i) {
       fat *= i;
    }

    std::println("Fatorial de {} = {}", n, fat);
}

int main(void) {
    int16_t x, y;

    std::println("CALCULO DE FATORIAL");
    std::println("-------------------");
    std::println("");

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fatorial(x);

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> y;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fatorial(y);

    fatorial(9);

    fatorial(6);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
