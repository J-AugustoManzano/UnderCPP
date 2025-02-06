// c03ex01.cpp

#include <iostream>
#include <print>
#include <array>
#include <limits>

int main(void) {
    std::array<int32_t, 5> numeros;

    for (size_t i = 0; i < numeros.size(); ++i) {
        std::print("Entre o {}o. elemento: ", i + 1);
        std::cin >> numeros[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Elemento {} = {:>8}", i + 1, numeros[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
