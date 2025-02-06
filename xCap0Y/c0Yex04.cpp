// c0Yex04.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t v1, v2, soma;

    std::print("Entre o 1o. valor: ");
    std::cin >> v1;
    std::print("Entre o 2o. valor: ");
    std::cin >> v2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    soma = v1 + v2;

    if (soma > v2 * 10) {
        std::println("Soma = {}", soma);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
