// c03ex40.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t valor1, valor2, novoValor;
    int16_t* ptrConvencional;          // Ponteiro convencional
    const int16_t* ptrConstante;       // Ponteiro constante

    // Entrada do primeiro valor
    std::print("Entre o 1o. valor inteiro (valor1): ");
    std::cin >> valor1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Entrada do segundo valor
    std::print("Entre o 2o. valor inteiro (valor2): ");
    std::cin >> valor2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ponteiro convencional
    ptrConvencional = &valor1; // Ponteiro aponta para valor1

    std::println("");
    std::println("ptrConvencional aponta para valor1 com o valor: {}", *ptrConvencional);

    // Tentativa de modificar o valor apontado pelo ponteiro convencional
    std::print("Tente modificar o valor apontado por ptrConvencional (entre um novo valor): ");
    std::cin >> novoValor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    *ptrConvencional = novoValor; // Modifica o valor apontado

    std::println("");
    std::println("Valor de valor1 foi modificado: {}", valor1);

    // Agora, utilizando um ponteiro constante
    ptrConstante = &valor2; // Ponteiro constante aponta para valor2

    std::println("");
    std::println("ptrConstante aponta para valor2 com o valor: {}", *ptrConstante);

    // Tentativa de modificar o valor apontado pelo ponteiro constante
    std::print("Tente modificar o valor apontadopor ptrConstante (entre um novo valor): ");
    std::cin >> novoValor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer

    // O valor apontado não pode ser modificado
    // Aqui tentamos modificar o valor e explicamos o que acontece
    std::println("");
    std::println("Erro: Nao foi possivel modificar o valor de ptrConstante.");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
