// c03ex43.cpp

#include <iostream>
#include <print>
#include <memory>
#include <limits>

int main(void) {
    int16_t tamanho;

    // Pedir ao usuário para definir o tamanho do arranjo
    std::print("Entre o tamanho do arranjo: ");
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Cria um ponteiro inteligente para um arranjo de inteiros
    std::unique_ptr<int16_t[]> ptrArranjo = std::make_unique<int16_t[]>(tamanho);

    // Preencher o arranjo com valores inseridos pelo usuário
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("Entre o valor para o elemento com indice [{:>3}]: ", i);
        std::cin >> ptrArranjo[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Exibir os valores armazenados no arranjo
    std::println("");
    std::println("Valores no arranjo:");
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::println("Elemento [{:>3}]: {:>5}", i, ptrArranjo[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
