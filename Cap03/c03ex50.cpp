// c03ex50.cpp

#include <print>
#include <iostream>
#include <limits>

// Procedimento de troca com passagem de parâmetro por ponteiro
void troca(int64_t* x, int64_t* y) {
    int64_t temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    // Declaração de variáveis para os valores de entrada
    int64_t a, b;

    // Leitura de valores
    std::print("Entre o 1o. valor: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::print("Entre o 2o. valor: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Exibindo os valores antes da troca
    std::println("Valores antes da troca ...: a: {}, b: {}", a, b);

    // Chamada da função para trocar os valores
    troca(&a, &b);

    // Exibindo os valores após a troca
    std::println("Valores depois da troca ..: a: {}, b: {}", a, b);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
