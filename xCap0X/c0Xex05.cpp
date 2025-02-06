// c0Xex05.cpp

#include <iostream>
#include <print>

int main(void) {
    uint8_t reg = 0b00000000;  // Registrador inicializado com bits em 0
    uint8_t masc = 0b00000100; // Máscara para o terceiro bit (LED)

    // Liga o LED (usa OR para definir o bit correspondente)
    reg |= masc; // reg = reg | masc
    std::println("LED ligado .....: {:08b}", reg);

    // Desliga o LED (usa AND com NOT para limpar o bit correspondente)
    reg &= ~masc; // reg = reg & masc
    std::println("LED desligado ..: {:08b}", reg);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
