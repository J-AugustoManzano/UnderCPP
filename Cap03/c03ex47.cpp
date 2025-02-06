// c03ex47.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    size_t tamanho;

    // Solicita ao usu�rio o tamanho do arranjo
    std::print("Quantos elementos a inserir: ");
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Aloca dinamicamente o arranjo com o tamanho definido pelo usu�rio
    int16_t* arranjo = new int16_t[tamanho];

    // Entrada dos valores do usu�rio
    std::println("");
    std::println("Insira {} valores inteiros:\n", tamanho);
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("Valor {}: ", i + 1);
        std::cin >> arranjo[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // C�lculo do somat�rio
    int16_t soma = 0;
    for (size_t i = 0; i < tamanho; ++i) {
        soma += arranjo[i];
    }

    // Exibi��o do somat�rio
    std::println("");
    std::println("Somatorio = {}", soma);

    // Libera a mem�ria alocada
    delete[] arranjo;

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
