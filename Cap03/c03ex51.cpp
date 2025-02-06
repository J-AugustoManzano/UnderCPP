// c03ex51.cpp

#include <print>
#include <iostream>
#include <limits>
#include <cmath>

void operacao(float arranjo[], size_t tamanho) {
    for (size_t i = 0; i < tamanho; ++i) {
        arranjo[i] = pow(arranjo[i], 2);
    }
}

int main(void) {
    size_t tamanho;

    std::print("Entre o tamanho do arranjo:");
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    float* arranjo = new float[tamanho];

    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("Entre o elemento {}: ", i + 1);
        std::cin >> arranjo[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    operacao(arranjo, tamanho);

    std::println("");
    std::println("Elementos ao quadrado:");
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::println("Elemento {:>3}: {:>6.1f}", i + 1, arranjo[i]);
    }

    delete[] arranjo;

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
