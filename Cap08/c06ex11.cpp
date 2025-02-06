// c08ex11.cpp

#include <iostream>
#include <print>
#include <functional>

// Função que efetua a multiplicação
auto multiplicar = [](int16_t x, int16_t y) {
    return x * y;
};

// Função simulada para multiplicação
auto multiplicarPor = [](int16_t x) {
    return [x](int16_t y) { return multiplicar(x, y); };
};

int main(void) {
    // Função currficada específica para multiplicar por 10
    auto multiplicarPorDez = multiplicarPor(10);

    // Usando a função multiplicarPorDez
    std::println("Resultado: {}", multiplicarPorDez(5)); // Saída: 50

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
