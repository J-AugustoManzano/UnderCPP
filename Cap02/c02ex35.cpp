// c02ex35.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    int16_t a, b, r;

    std::print("Entre o valor <A>: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor <B>: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    r = (a > b) ? a : b;

    std::println("\nO maior valor informado e: {}", r);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
