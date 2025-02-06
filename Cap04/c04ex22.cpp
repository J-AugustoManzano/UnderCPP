// c04ex22.cpp

#include <iostream>
#include <cmath>
#include <print>

int main(void) {
    int16_t x, y, z;

    // La�o aninhado para encontrar um triplo pitag�rico
    for (z = 1; z <= 10; ++z) {
        for (y = 1; y <= 10; ++y) {
            for (x = 1; x <= 10; ++x) {
                // Verifica se (x, y, z) formam um triplo pitag�rico
                if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
                    std::println("Encontrado um triplo pitagorico: {}, {} e {}.", x, y, z);
                    // Usa break para sair do la�o mais interno
                    break;
                }
            }
            // Quando o break no la�o de x � acionado, verificamos se encontramos o triplo
            if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
                break; // Sair do la�o de y
            }
        }
        // Quando o break no la�o de y � acionado, verificamos se encontramos o triplo
        if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
            break; // Sair do la�o de z
        }
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
