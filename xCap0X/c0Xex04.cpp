// c0Xex04.cpp

#include <iostream>
#include <print>

int main(void) {

    uint8_t valor1 = 10;     // 10 em decimal
    uint8_t valor2 = 0xa;    // 10 em hexadecimal
    uint8_t valor3 = 012;    // 10 em octal
    uint8_t valor4 = 0b1010; // 10 em binario

    std::println("{} em decimal -----> {:04}", valor1, valor1);
    std::println("{} em hexadecimal -> {:04x}", valor1, valor1);
    std::println("{} em binario -----> {:04b}", valor1, valor1);
    std::println("{} em octal -------> {:04o}", valor1, valor1);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
