// c03ex62.cpp

#include <iostream>
#include <print>

int64_t somar(int32_t x, int32_t y) {
    return x + y;
}

int64_t multiplicar(int32_t x, int32_t y) {
    return x * y;
}

int main(void) {
    // Declaração do ponteiro de função
    int64_t (*operacao)(int32_t, int32_t);

    // Chamada da função somar usando o ponteiro "operacao"
    operacao = somar;
    std::println("Resultado da soma ...........: {}", operacao(5, 10));

    // Chamada da função multiplicar usando o ponteiro "operacao"
    operacao = multiplicar;
    std::println("Resultado da multiplicacao ..: {}", operacao(5, 10));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
