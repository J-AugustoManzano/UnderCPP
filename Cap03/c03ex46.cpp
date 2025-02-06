// c03ex46.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    constexpr size_t tamanho = 5;

    // Declara��o de um arranjo est�tico de inteiros
    int16_t arranjo[tamanho];

    // Entrada de valores do usu�rio
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

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
