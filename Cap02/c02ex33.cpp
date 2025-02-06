// c02ex33.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t n;

    std::print("Entre um valor numerico inteiro (unidade): ");
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    switch (n) {
        case  1:
        case  3:
        case  5:
        case  7:
        case  9: std::println("Valor impar");    break;
        case  2:
        case  4:
        case  6:
        case  8: std::println("Valor par");      break;
        default: std::println("Valor invalido"); break;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
