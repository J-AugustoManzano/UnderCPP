// c04ex21.cpp

#include <iostream>
#include <print>
#include <cmath>

int main(void) {
    // Laço aninhado para encontrar um triplo pitagórico
    for (int16_t z = 1; z <= 10; ++z) {
        for (int16_t y = 1; y <= 10; ++y) {
            for (int16_t x = 1; x <= 10; ++x) {
                // Verifica se (x, y, z) formam um triplo pitagórico
                if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
                    std::println("Encontrado um triplo pitagorico: {}, {} e {}.", x, y, z);
                    goto done; // Usa o goto para sair de todos os loops
                }
            }
        }
    }

done:
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
