// c0Yex05 - src/main.cpp

#include <iostream>
#include <print>
#include "utils.h"

int main(void) {
    std::println("A soma de 3 e 4 equivale a: {}", soma(3, 4));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
