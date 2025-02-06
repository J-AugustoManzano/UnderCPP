// c08ex09.cpp

#include <iostream>
#include <print>
#include <functional>

// Função para compor usando std::function
std::function<double(double)> comporStd(std::function<double(double)> f, std::function<double(double)> g) {
    return [=](double x) {
        return f(g(x));
    };
}

int main(void) {
    std::function<double(double)> multiplicarPor2 = [](double x) { return x * 2; };
    std::function<double(double)> adicionar3 = [](double x) { return x + 3; };

    auto f = comporStd(multiplicarPor2, adicionar3);
    std::println("{}", f(5)); // Saída: (5 + 3) * 2 = 16

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
