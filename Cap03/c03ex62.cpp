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
    // Declara��o do ponteiro de fun��o
    int64_t (*operacao)(int32_t, int32_t);

    // Chamada da fun��o somar usando o ponteiro "operacao"
    operacao = somar;
    std::println("Resultado da soma ...........: {}", operacao(5, 10));

    // Chamada da fun��o multiplicar usando o ponteiro "operacao"
    operacao = multiplicar;
    std::println("Resultado da multiplicacao ..: {}", operacao(5, 10));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
