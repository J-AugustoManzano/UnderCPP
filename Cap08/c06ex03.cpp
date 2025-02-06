// c08ex03.cpp

#include <iostream>
#include <print>

// Operações matemáticas
int16_t soma(const int16_t a, const int16_t b) { return a + b; }
int16_t produto(const int16_t a, const int16_t b) { return a * b; }

// Função que aceita outra função como parâmetro
int16_t calc(const int16_t a, const int16_t b, int16_t (*opera)(const int16_t, const int16_t)) {
    return opera(a, b);
}

int main(void) {
    std::println("Soma .....: {:>2}", calc(5, 3, soma));    // Saída:  8
    std::println("Produto ..: {:>2}", calc(5, 3, produto)); // Saída: 15

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
