// c02ex62.cpp

#include <iostream>
#include <limits>
#include <print>

int main(void) {
    float numero;

   do {
        std::print("Entre um numero: ");
        std::cin >> numero;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail()) {
            std::println("Entrada invalida. Por favor, entre apenas numero.");
            std::println("");
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Se a entrada for válida, sair do laço
        }
    } while (true);

    std::println("");
    std::println("Valor numerico informado = {}", numero);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
