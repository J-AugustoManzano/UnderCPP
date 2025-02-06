// c02ex80.cpp

#include <iostream>
#include <limits>
#include <print>

// Função auxiliar que calcula o fatorial usando recursão de cauda
int64_t fatorialBase(int16_t n, int64_t p) {
    if (n == 0) {
        return p;
    } else {
        return fatorialBase(n - 1, n * p); // Chamada recursiva: cauda = n * p
    }
}

// Função principal que chama a função auxiliar com o parâmetro inicial p = 1
int64_t fatorial(int16_t n) {
    return fatorialBase(n, 1);
}

int main(void) {
    int16_t x;

    std::println("CALCULO DE FATORIAL");
    std::println("-------------------");
    std::println("");

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("Fatorial de {} = {}", x, fatorial(x));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
