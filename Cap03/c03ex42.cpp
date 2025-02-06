// c03ex42.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    const int16_t taxaImposto = 15;                     // Valor constante
    int16_t novaTaxa;
    const int16_t* const ptrTaxaImposto = &taxaImposto; // Ponteiro constante

    // Exibindo a taxa de imposto
    std::println("Taxa de imposto atual: {}%", *ptrTaxaImposto);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
