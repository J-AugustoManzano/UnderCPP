// c02ex59.cpp

#include <iostream>
#include <print>

int main(void) {
    int16_t i = 1; // Inicializa��o de i fora do la�o

    for (; i <= 5;) { // Omitindo a terceira express�o
        std::println("i = {:>2}", i);
        ++i; // Incremento manualmente dentro do la�o
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
