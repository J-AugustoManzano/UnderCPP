// c03ex37.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    double arranjo[5];
    double* ptrArranjo = arranjo;

    // Leitura dos valores via ponteiros
    for (size_t i = 0; i <= 4; ++i) {
        std::print("Entre o valor {} no indice [{}]: ", i + 1, i);
        std::cin >> *(ptrArranjo + i);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Exibição dos valores via ponteiros
    std::println("");
    std::println("Valores inseridos no arranjo:");
    std::println("");
    for (size_t i = 0; i <= 4; ++i) {
        std::println("Valor no indice [{}]: {}", i, *(ptrArranjo + i));
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    return 0;
}
