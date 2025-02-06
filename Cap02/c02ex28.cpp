// c02ex28.cpp

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

    // Usando o operador XOR para verificar se apenas um dos valores é positivo
    if ((a > 0) xor (b > 0)) {
        std::println("Apenas um dos valores [A] ou [B] eh positivo.");
    } else {
        std::println("Ambos os valores sao positivos ou anegativos.");
    }

    std::println("Soma dos valores: {}", r);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
