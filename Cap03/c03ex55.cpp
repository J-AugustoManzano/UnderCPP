// c03ex55.cpp

#include <print>
#include <iostream>
#include <vector>

// Função template para encontrar o maior valor em um vetor de qualquer tipo
template <typename T>
T encontrarMaximo(const std::vector<T>& v) {
    T max_val = v[0]; // Inicializa o valor máximo com o primeiro elemento
    for (const T& elemento : v) {
        if (elemento > max_val) {
            max_val = elemento; // Atualiza o valor máximo
        }
    }
    return max_val;
}

int main(void) {
    // Exemplo com números inteiros (int32_t)
    std::vector<int32_t> numeros_int = {1, 5, 3, 9, 2};
    std::println("Maior valor dos inteiros ..: {}", encontrarMaximo(numeros_int));

    // Exemplo com números de ponto flutuante (float)
    std::vector<float> numeros_float = {3.14f, 2.71f, 1.61f, 4.56f};
    std::println("Maior valor dos floats ....: {}", encontrarMaximo(numeros_float));

    // Exemplo com números de ponto flutuante (double)
    std::vector<double> numeros_double = {3.14159, 2.71828, 1.61803, 4.56789};
    std::println("Maior valor dos doubles ...: {}", encontrarMaximo(numeros_double));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
