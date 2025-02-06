// c02ex47.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    float n;
    int16_t conta = 1;

    do {
        std::print("Entre um numero (0 para sair): ");
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (n == 0) {
            break;
        }

        std::println("Voce informou o numero: {}", n);
        std::println("Ate aqui voce entrou {} {}\n", conta, conta < 2 ? "numero" : "numeros");
        ++conta;
    } while (true);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
