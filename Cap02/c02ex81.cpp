// c02ex81.cpp

#include <iostream>
#include <limits>
#include <print>

// Função auxiliar que calcula o termo de Fibonacci usando recursão de cauda
int64_t fibonacciBase(int16_t n, int64_t x, int64_t y) {
    if (n == 0) {
        return x; // Retorna o primeiro termo (0)
    }
    if (n == 1) {
        return y; // Retorna o segundo termo (1)
    }
    return fibonacciBase(n - 1, y, x + y); // Chamada recursiva com cauda x + y
}

// Função principal que chama a função auxiliar com os parâmetros iniciais
int64_t fibonacci(int16_t n) {
    return fibonacciBase(n, 0, 1); // Inicia com 0 e 1
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
