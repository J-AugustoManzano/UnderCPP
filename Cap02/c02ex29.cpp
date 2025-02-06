// c02ex29.cpp

#include <iostream>
#include <limits>
#include <print>

int main(void) {
    int32_t valor;

    std::print("Entre um valor inteiro positivo ");
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Usando o operador NOT para verificar se valor é ou não positivo
    if (not (valor >= 0)) {
        std::println("valor invalido, valor informado positivo.");
    } else {
        std::println("valor valido informado = {}.", valor);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
