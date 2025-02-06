// c03ex31.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t valor, *ptrValor = &valor;

    std::print("Entre um valor inteiro: ");
    std::cin >> *ptrValor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("\nValor informado = {}", valor);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
