// c04ex13.cpp

#include <iostream>
#include <print>
#include <regex>
#include <string>

// Função para calcular o fatorial
uint64_t fatorial(uint16_t n) {
    uint64_t fat = 1;
    for (size_t i = 2; i <= n; ++i) {
        fat *= i;
    }
    return fat;
}

int main(void) {
    std::string entrada;
    std::regex regex_inteiro(R"(\d+)");
    uint16_t numero;

    do {
        std::print("Entre numero inteiro entre 0 e 20 para calcular o fatorial: ");
        getline(std::cin, entrada);

        // Verifica se a entrada corresponde à expressão regular para um número inteiro
        if (regex_match(entrada, regex_inteiro)) {
            numero = stoi(entrada);

            // Verifica se o número está dentro da faixa permitida
            if (numero >= 0 and numero <= 20) {
                break;
            } else {
                std::println("Erro: o numero deve estar entre 0 e 20.");
            }
        } else {
            std::println("Erro: entrada invalida. Entre um numero inteiro.");
        }

    } while (true);

    // Calcula e exibe o fatorial
    std::println("");
    std::println("Fatorial de {} = {}", numero, fatorial(numero));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
