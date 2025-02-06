// c02ex58.cpp

#include <iostream>
#include <print>

int main(void) {
    for (int16_t i = 1; i <= 5;) { // Omitindo a terceira expressão
        std::println("i = {:>2}", i);
        ++i; // Incremento manualmente dentro do laço
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
