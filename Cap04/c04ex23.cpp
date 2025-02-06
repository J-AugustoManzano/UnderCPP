// c04ex23.cpp

#include <iostream>
#include <print>
#include <cmath>

int main(void) {
    bool encontrado = false; // Flag para controlar a interrupção dos laços

    // Laço aninhado para encontrar um triplo pitagórico
    for (int16_t z = 1; z <= 10 and encontrado == false; ++z) {
        for (int16_t y = 1; y <= 10 and encontrado == false; ++y) {
            for (int16_t x = 1; x <= 10; ++x) {
                // Verifica se (x, y, z) formam um triplo pitagórico
                if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
                    std::println("Encontrado um triplo pitagorico: {}, {} e {}.", x, y, z);
                    encontrado = true; // Seta a flag para interromper os laços externos
                    break; // Sai do laço mais interno
                }
            }
        }
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
