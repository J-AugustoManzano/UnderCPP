// c03ex54.cpp

#include <print>
#include <iostream>
#include <limits>

// Função genérica para troca de valores
template <typename T>
void troca(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

int main(void) {
    int16_t a1, b1;
    double  a2, b2;

    // Entrada de valores inteiros
    std::print("Entre o 1o. valor inteiro: ");
    std::cin >> a1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. valor inteiro: ");
    std::cin >> b1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");
    std::println("Valores antes da troca  - a: {}, b: {}", a1, b1);
    troca(a1, b1);
    std::println("Valores depois da troca - a: {}, b: {}", a1, b1);
    std::println("");

    // Entrada de valores de ponto flutuante
    std::print("Entre o 1o. valor de ponto flutuante: ");
    std::cin >> a2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. valor de ponto flutuante: ");
    std::cin >> b2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("");
    std::println("Valores antes da troca  - a: {}, b: {}", a2, b2);
    troca(a2, b2);
    std::println("Valores depois da troca - a: {}, b: {}", a2, b2);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

