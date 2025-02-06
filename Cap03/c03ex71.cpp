// c03ex71.cpp

#include <iostream>
#include <print>
#include <vector>
#include <utility>  // Para std::move

int main(void) {
    int16_t x = 10, y = 0;
    std::vector<int16_t> vet1 = {1, 2, 3, 4, 5};
    std::vector<int16_t> vet2, vet3;

    std::println("Variavel simples: ");
    std::println("");
    std::println("x (antes da copia): {}", x);
    std::println("y (antes da copia): {}", y);

    // Copiando o dado de x para y
    y = std::move(x);

    std::println("");
    std::println("x (depois da copia): {}", x);
    std::println("y (depois da copia): {}", y);

    std::println("");
    std::println("Variavel composta: ");
    std::println("");

    // Copia os dados de vet1 para vet2
    vet2 = vet1;  // vet1 ainda possui os dados

    std::print("vet1 (antes da copia): ");
    for (int16_t n : vet1) std::print("{} ", n);
    std::println("");
    std::print("vec2 (antes da copia): ");
    for (int16_t n : vet2) std::print("{} ", n);

    // Movendo os dados de vet1 para vet3
    vet3 = std::move(vet1);  // Agora vet1 esta "vazio"

    std::println("\n");
    std::print("vet1 (depois de move): ");
    for (int16_t n : vet1) std::print("{} ", n);  // vet1 agora nao possui elementos
    std::println("");
    std::print("vet3 (depois de move): ");
    for (int16_t n : vet2) std::print("{} ", n);
    std::println("");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
