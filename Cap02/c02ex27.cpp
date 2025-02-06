// c02ex27.cpp

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

    // Usando o operador or para verificar se uma ou ambas as condi��es s�o verdadeiras
    if (a > 0 or b > 0) {
        std::println("Pelo menos um dos valores [A] ou [B] eh positivo.");
    } else {
        std::println("Nenhum dos valores [A] ou [B] eh positivo.");
    }

    std::println("Soma dos valores: {}", r);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
