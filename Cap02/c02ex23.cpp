// c02ex23.cpp

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

    r = a + b;

    if (r > 10) {
        std::println("Resultado = {}", r);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

