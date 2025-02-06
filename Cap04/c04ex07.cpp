// c04ex07.cpp

#include <iostream>
#include <print>
#include <string>
#include <cctype>
#include <limits>

int main(void) {
    std::string cadeiaNumerica = "123";
    int16_t numero = std::stoi(cadeiaNumerica);

    std::println("Cadeia numerica ........: {:>4}", cadeiaNumerica);
    std::println("Numero convertido ......: {:>4}", numero);
    std::println("Numero convertido + 5 ..: {:>4}", numero + 5);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
