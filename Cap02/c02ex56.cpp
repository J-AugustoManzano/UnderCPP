// c02ex56.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t i = 1; // Inicializa��o de i fora do la�o

    for (; i <= 5; ++i) { // Omitindo a primeira express�o
        std::println("i = {:>2}", i);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
