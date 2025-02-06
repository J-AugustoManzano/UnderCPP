// c02ex65.cpp

#include <iostream>
#include <limits>
#include <sstream> // Para std::stringstream
#include <print>

int16_t n;
int64_t fat;
std::string entraNumero;

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

        std::stringstream ss(entraNumero); // Cria um stringstream a partir da entrada

        // Verifica se a conversão falhou ou se não se chegou ao final do fluxo
        if (not (ss >> n) or not ss.eof()) {
            std::println("Erro: Entre apenas numeros inteiros.\n");
            continue; // Volta para pedir a entrada novamente
        }

        // Verifica se o valor de "n" está no intervalo permitido
        if (n >= 0 and n <= 20) {
            break;
        } else {
            std::println("Erro: O valor deve estar entre 0 e 20.");
            std::println("");
        }
    } while (true);

    fatorial();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
