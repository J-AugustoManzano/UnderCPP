// c03ex58.cpp

#include <iostream>
#include <vector>
#include <print>

void operacao(const std::vector<int32_t>& arranjo) {
    std::print("Tamanho do arranjo: {} ->", arranjo.size());
    for (const auto& elemento : arranjo) {
        std::print(" {}", elemento);
    }
    std::println("");
}

int main(void) {
    std::vector<int32_t> listaNumeros = {1, 2, 3, 4, 5};
    operacao(listaNumeros);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
