// c03ex56.cpp

#include <iostream>
#include <array>
#include <print>

template <typename T, size_t N>
void operacao(const std::array<T, N>& arranjo) {
    std::print("Tamanho do arranjo: {} ->", N);
    for (const auto& elemento : arranjo) {
        std::print(" {}", elemento);
    }
    std::println("");
}

int main(void) {
    std::array<int16_t, 5> arranjo = {1, 2, 3, 4, 5};
    operacao(arranjo);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
