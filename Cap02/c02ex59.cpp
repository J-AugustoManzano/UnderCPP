// c02ex59.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t i = 1; // Inicialização de i fora do laço

    for (; i <= 5;) { // Omitindo a terceira expressão
        std::println("i = {:>2}", i);
        ++i; // Incremento manualmente dentro do laço
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
