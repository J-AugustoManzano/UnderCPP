// c03ex47.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    size_t tamanho;

    // Solicita ao usuário o tamanho do arranjo
    std::print("Quantos elementos a inserir: ");
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Aloca dinamicamente o arranjo com o tamanho definido pelo usuário
    int16_t* arranjo = new int16_t[tamanho];

    // Entrada dos valores do usuário
    std::println("");
    std::println("Insira {} valores inteiros:\n", tamanho);
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("Valor {}: ", i + 1);
        std::cin >> arranjo[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Cálculo do somatório
    int16_t soma = 0;
    for (size_t i = 0; i < tamanho; ++i) {
        soma += arranjo[i];
    }

    // Exibição do somatório
    std::println("");
    std::println("Somatorio = {}", soma);

    // Libera a memória alocada
    delete[] arranjo;

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
