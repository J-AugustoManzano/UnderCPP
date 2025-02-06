// c02ex60.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t i = 1; // Inicialização de i fora do laço

    for (; ;) { // Omitindo a terceira expressão
        std::println("i = {:>2}", i);
        ++i; // Incremento manualmente dentro do laço
        if (i > 5) break; // Verificando a condição manualmente
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
