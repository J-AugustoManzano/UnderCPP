// c02ex66.cpp

#include <iostream>
#include <limits>
#include <sstream>
#include <print>

int16_t n;
int64_t fat;
std::string entraNumero;

// Função para validar a entrada do usuário
bool validarEntrada() {
    std::stringstream ss(entraNumero);

    if (not (ss >> n) or not ss.eof()) {
        std::println("Erro: Entre apenas numeros inteiros.\n");
        return false; // Entrada inválida
    }

    if (n < 0 or n > 20) {
        std::println("Erro: O valor deve estar entre 0 e 20.");
        std::println("");
        return false; // Entrada fora do intervalo
    }

    return true; // Entrada válida
}

void fatorial(void) {
    fat = 1;
    for (int16_t i = 1; i <= n; ++i) {
        fat *= i;
    }
    std::println("Fatorial de {} equivale a: {}.", n, fat);
}

int main(void) {
    do {
        std::print("Entre um numero inteiro (0-20): ");
        std::getline(std::cin, entraNumero);

        // Valida a entrada usando a função validarEntrada()
    } while (not validarEntrada()); // Repete enquanto a entrada não for válida

    fatorial();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
