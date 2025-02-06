// c03ex72.cpp

#include <iostream>
#include <print>
#include <limits>

#define MENOR_VALOR(v1, v2) ((v1 < v2) ? (v1) : (v2))

int main(void)
{

    int16_t a, b;

    std::print("Entre o 1o. valor: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 1o. valor: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("Menor valor: {}", MENOR_VALOR(a, b));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
