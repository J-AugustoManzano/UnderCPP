// c08ex01.cpp

#include <iostream>
#include <print>
#include <limits>

// Função pura com parâmetros imutáveis
int16_t somar(const int16_t a, const int16_t b) {
    return a + b;
}

int main(void) {
    int16_t aMut, bMut;

    std::print("Entre valor <A>: ");
    std::cin >> aMut;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre valor <B>: ");
    std::cin >> bMut;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Definição de variáveis de esatdo imutável
    const int16_t a = aMut, b = bMut;

    // Mostrar o valor da variável
    std::println("Soma = {}", somar(a, b));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

