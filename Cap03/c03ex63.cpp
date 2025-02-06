// c03ex63.cpp

#include <iostream>
#include <print>

void saudacao(void) {
    std::println("Ola, Mundo!");
}

void executarCallback(void (*callback)()) {
    callback();
}

int main(void) {
    executarCallback(saudacao);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
