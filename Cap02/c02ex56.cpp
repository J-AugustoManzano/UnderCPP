// c02ex56.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t i = 1; // Inicialização de i fora do laço

    for (; i <= 5; ++i) { // Omitindo a primeira expressão
        std::println("i = {:>2}", i);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
