// c08ex08.cpp

#include <iostream>
#include <print>
#include <functional>

// Define funções simples
double multiplicarPor2(const double x) { return x * 2; }
double adicionar3(const double x) { return x + 3; }

// Função para compor duas funções
auto compor = [](auto f, auto g) {
    return [=](auto x) {
        return f(g(x));
    };
};

int main(void) {
    auto f = compor(multiplicarPor2, adicionar3);
    std::println("{}", f(5)); // Saída: (5 + 3) * 2 = 16

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
