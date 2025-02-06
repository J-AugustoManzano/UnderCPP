// c02ex26.cpp

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

    // Usando o operador and para verificar se os valores são ou não positivos
    if (a > 0 and b > 0) {
        std::println("Ambos os valores [A] e [B] sao positivos.");
    } else {
        std::println("Um ou ambos os valores [A] ou [B] sao negativos.");
    }

    std::println("Soma dos valores: {}", r);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
