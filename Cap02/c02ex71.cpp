// c02ex71.cpp

#include <iostream>
#include <limits>
#include <print>

extern double a, b;
extern void adicao(void);

int main(void) {
    std::print("Entre o 1o. valor numerico: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o 2o. valor numerico: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    adicao();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
