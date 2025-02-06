// c02ex48.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    float n;
    int16_t conta = 1;

    meu_laco:
        std::print("Entre um numero (0 para sair): ");
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (n == 0) {
            goto fim_meu_laco;
        }

        std::println("Voce informou o numero: {}", n);
        std::println("Ate aqui voce entrou {} {}\n", conta, conta < 2 ? "numero" : "numeros");
        ++conta;
        goto meu_laco;
    fim_meu_laco:

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
