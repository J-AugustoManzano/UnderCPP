// c02ex57.cpp

#include <iostream>
#include <print>

int main(void) {
    for (int16_t i = 1; ; ++i) { // Omitindo a segunda express�o
        if (i > 5) break; // Verificando a condi��o manualmente
        std::println("i = {:>2}", i);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
