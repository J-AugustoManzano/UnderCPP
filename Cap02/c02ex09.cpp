// c02ex09.cpp

#include <iostream>
#include <limits>

int main(void) {
    float valorFloat;
    double valorDouble;

    std::cout << "Entre o primeiro valor de ponto flutuante (float) ..: ";
    std::cin >> valorFloat;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Entre o segundo valor de ponto flutuante (double) ..: ";
    std::cin >> valorDouble;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Valores inseridos: " << valorFloat << " (float) e ";
    std::cout << valorDouble << " (double)" << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
