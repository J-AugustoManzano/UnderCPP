// c08ex10.cpp

#include <iostream>
#include <print>
#include <functional>

// Exemplo usando std::bind
double multiplicarPor2(double x) { return x * 2; }
double adicionar3(double x) { return x + 3; }

int main(void) {
    using namespace std::placeholders;
    auto adicionarDepoisMultiplicar = std::bind(multiplicarPor2, std::bind(adicionar3, _1));
    std::println("{}",adicionarDepoisMultiplicar(5)); // Saída: 16

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
