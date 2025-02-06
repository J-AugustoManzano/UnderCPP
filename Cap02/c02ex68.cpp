// c02ex68.cpp

#include <iostream>
#include <limits>
#include <print>

double a, b, r;

void soma(void) {
    std::print("Entre o 1o. Valor numerico: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. Valor numerico: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    r = a + b;
}

int main(void) {
    soma();
    std::println("Resultado = {}.", r);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
