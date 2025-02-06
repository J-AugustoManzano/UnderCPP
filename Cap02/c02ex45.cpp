// c02ex45.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t numero = 1;

    while (numero <= 10) {
        if (numero % 2 != 0) {
            ++numero;
            continue;  // Pula os números ímpares
        }
        std::println("Numero par: {:>2}", numero);
        ++numero;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

