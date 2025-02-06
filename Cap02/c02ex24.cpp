// c02ex24.cpp

#include <iostream>
#include <limits>
#include <print>

int main(void) {
    int16_t a, b;

    std::print("Entre o valor [A]: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor [B]: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (a > b) {
        int16_t x = a;
        a = b;
        b = x;
    }

    std::println("Os valores ordenados sao: {} e {}", a, b);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

