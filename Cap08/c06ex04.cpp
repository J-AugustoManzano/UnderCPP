// c08ex04.cpp

#include <iostream>
#include <print>
#include <functional>

// Função que aceita outra função como parâmetro
int16_t calc(const int16_t a, const int16_t b,
    std::function<int16_t(const int16_t, const int16_t)> opera) {
    return opera(a, b);
}

int main(void) {
    std::println("Soma .....: {:>2}", calc(5, 3,
        [](const int16_t a, const int16_t b) { return a + b; }));  // Saída:  8
    std::println("Produto ..: {:>2}", calc(5, 3,
        [](const int16_t a, const int16_t b) { return a * b; }));  // Saída: 15

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
