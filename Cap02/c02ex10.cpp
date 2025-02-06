// c02ex10.cpp

#include <iostream>
#include <limits>

int main(void) {
    bool valor1, valor2;

    std::cout << "Entre o primeiro valor logico (0 para false, 1 para true) ..: ";
    std::cin >> valor1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Entre o segundo valor logico (0 para false, 1 para true) ...: ";
    std::cin >> valor2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << std::boolalpha;
    std::cout << "Valores inseridos: " << valor1 << " e " << valor2 << std::endl;
    std::cout << std::noboolalpha;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
