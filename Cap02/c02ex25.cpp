// c02ex25.cpp

#include <iostream>
#include <limits>
#include <print>

int main(void) {
    int32_t a, b, r;

    std::print("Entre o valor [A]: ");
    std::cin >> a;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::print("Entre o valor [B]: ");
    std::cin >> b;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (int32_t r = a + b; r >= 10) {
        std::println("Resultado = {}", r + 5);
    } else {
        std::println("Resultado = {}", r - 7);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

