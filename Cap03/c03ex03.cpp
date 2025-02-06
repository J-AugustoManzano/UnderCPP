// c03ex03.cpp

#include <iostream>
#include <print>
#include <vector>

int main(void) {
    size_t quantidade;

    std::print("Entre a quantidade de elementos: ");
    std::cin >> quantidade;

    std::vector<int16_t> elementos(quantidade);

    std::println("");
    for (size_t i = 0; i < quantidade; ++i) {
        std::print("Elemento [{:>2}]: ", i + 1);
        std::cin >> elementos[i];
    }

    std::println("");
    std::println("\nValores inseridos:");
    for (size_t i = 0; i < quantidade; ++i) {
        std::println("Elemento [{:>2}] = {:>8}", i + 1, elementos[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    std::cin.get();

    return 0;
}
