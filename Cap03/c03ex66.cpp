// c03ex66.cpp

#include <iostream>
#include <print>
#include <vector>
#include <cmath>
#include <limits>

// Alias para simplificar o uso de std::vector com templates
template <typename T>
using Vetor = std::vector<T>;

int main(void) {
    // Definição da quantidade de elementos
    std::print("Entre a quantidade de elementos: ");
    size_t tamanho;
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Dimensionamento do vetor "a"
    Vetor<int64_t> a(tamanho);
    std::println("");
    std::println("Entre os elementos do vetor (int64_t):");
    std::println("");

    // Leitura dos elementos do vetor "a"
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("a[{:>3}] = ", i + 1);
        std::cin >> a[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Dimensionamento do vetor "b"
    Vetor<double> b(tamanho);
    for (size_t i = 0; i < tamanho; ++i) {
        b[i] = std::sqrt(static_cast<double>(a[i]));
    }

    // Mostrar os resultados das matrizes "a" e "b"
    std::println("");
    std::println("Resultados:");
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::println("a[{:>3}] = {:>3} -> b[{:>3}] = {:>6.2f}", i + 1, a[i], i + 1, b[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
