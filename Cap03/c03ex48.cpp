// c03ex48.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t matriz[3][4];
    int16_t pares = 0;
    int16_t impares = 0;

    // Entrada dos valores na matriz
    std::println("Entre 12 valores inteiros para a matriz de 3x4:\n");
    for (size_t i = 0; i <= 2; ++i) {
        for (size_t j = 0; j <= 3; ++j) {
            std::print("Elemento [{},{}]: ", i + 1, j + 1);
            std::cin >> matriz[i][j];
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Contagem de pares e ímpares
            if (matriz[i][j] % 2 == 0) {
                ++pares;
            } else {
                ++impares;
            }
        }
    }

    // Exibindo os resultados
    std::println("");
    std::println("Quantidade de numeros pares ....: {}", pares);
    std::println("Quantidade de numeros impares ..: {}", impares);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
