// c02ex44.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t numero = 1;

    while (numero <= 10) {
        if (numero % 5 == 0) {
            std::println("Primeiro multiplo de 5 encontrado: {}", numero);
            break;  // Interrompe o laço após encontrar o primeiro múltiplo de 5
        }
        ++numero;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
