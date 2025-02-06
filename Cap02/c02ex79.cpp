// c02ex79.cpp

#include <iostream>
#include <limits>
#include <print>

int64_t fibonacci(int32_t n) {
    if (n == 0) {
       return 0;
    }
    if (n == 1) {
       return 1;
    }
    if (n >= 2) {
       return fibonacci(n - 1) + fibonacci(n - 2);
    }
    return 0; // Se n for negativo.
}

int main(void) {
    int16_t x;

    std::println("CALCULO DO TERMO DE FIBONACCI");
    std::println("-----------------------------");
    std::println("");

    std::print("Entre um valor numerico inteiro: ");
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::println("O termo {} = {}", x, fibonacci(x));

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
