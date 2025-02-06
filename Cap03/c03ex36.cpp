// c03ex36.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    double vlr1 = 0;
    double vlr2 = 0;
    double soma = 0;

    double* ptrVlr1 = &vlr1;
    double* ptrVlr2 = &vlr2;
    double* ptrSoma = &soma;

    // Leitura dos valores via ponteiros
    std::print("Entre o 1o. valor: ");
    std::cin >> *ptrVlr1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. valor: ");
    std::cin >> *ptrVlr2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Cálculo da soma via ponteiros
    *ptrSoma = *ptrVlr1 + *ptrVlr2;

    // Exibição do resultado via ponteiro
    std::println("Resultado = {}", *ptrSoma);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    return 0;
}
