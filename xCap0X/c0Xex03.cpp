// c0Xex03.cpp

#include <iostream>
#include <print>

int main(void) {
    unsigned char valor = 255; // 1111 1111

    unsigned char valor1 = valor << 0; // 1111 1111
    unsigned char valor2 = valor << 8; // 0000 0001 +
    // ----------------------------------------------
    //                                    0000 0000

    std::println("{:>3} -> {:08b}", valor1, valor1);
    std::println("{:>3} -> {:08b}", valor2, valor2);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
