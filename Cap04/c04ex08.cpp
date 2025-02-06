// c04ex08.cpp

#include <iostream>
#include <print>
#include <string>

int main(void) {
    int16_t numero = 123;
    std::string cadeiaNumerica = std::to_string(numero);

    std::println("Numero informado ............: {:>4}", numero);
    std::println("Cadeia numerica convertida ..: {:>4}", cadeiaNumerica);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
