// c02ex08.cpp

#include <iostream>
#include <cstdint>  // Para int16_t (opcional)
#include <limits>   // Para std::numeric_limits

int main(void) {
    int16_t valor1, valor2;

    std::cout << "Entre o primeiro valor ..: ";
    std::cin >> valor1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Entre o segundo valor ...: ";
    std::cin >> valor2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Valores inseridos: " << valor1 << " e " << valor2 << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();

    return 0;
}
