// c0Xex01.cpp

#include <iostream>
#include <print>

int main(void) {
    uint16_t valor = 1; // 0001

    uint16_t valor0 = valor << 0; // 0001: 2^0 = 1 -> sem desloc.
    uint16_t valor1 = valor << 1; // 0010: 2^1 = 2 –> com desloc. esq. de 1 bit.
    uint16_t valor2 = valor << 2; // 0100: 2^2 = 4 –> com desloc. esq. de 1 bit.
    uint16_t valor3 = valor << 3; // 1000: 2^3 = 8 –> com desloc. esq. de 1 bit.

    std::println("{} -> {:08b}", valor0, valor0);
    std::println("{} -> {:08b}", valor1, valor1);
    std::println("{} -> {:08b}", valor2, valor2);
    std::println("{} -> {:08b}", valor3, valor3);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
