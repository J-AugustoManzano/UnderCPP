// c02ex69.cpp

#include <iostream>
#include <limits>
#include <print>

double a, b;

void soma(void) {
    double r;

    r = a + b;
    std::println("Resultado = {}.", r);
}

int main(void) {
    std::print("Entre o 1o. Valor numerico: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. Valor numerico: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    soma();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
