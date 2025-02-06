// c04ex24.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>

int main(void) {
    // Definição de um vetor com alguns valores
    std::vector<int16_t> a = {10, 20, 30, 40, 50};

    // Definição de um segundo vetor com o mesmo tamanho que o primeiro
    std::vector<int16_t> b(a.size());

    // Cópia dos dados de 'a' para 'b'
    std::copy(a.begin(), a.end(), b.begin());

    // Exibindo os dados de ambos os vetores
    std::print("Vetor [A]: ");
    for (int16_t val : a) {
        std::print("{} ", val);
    }
    std::println("");

    std::print("Vetor [B]: ");
    for (int16_t val : b) {
        std::print("{} ", val);
    }
    std::println(" - copia do vetor [A].");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
