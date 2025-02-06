// c04ex01.cpp

#include <iostream>
#include <print>

int main(void) {
    char letra = 'a';
    char numeral = '5';
    char simbolo = '$';

    std::println("Caractere letra ....: {}", letra);
    std::println("Caractere numeral ..: {}", numeral);
    std::println("Caractere simbolo ..: {}", simbolo);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
