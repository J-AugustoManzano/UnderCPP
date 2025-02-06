// c03ex25.cpp

#include <iostream>
#include <print>
#include <set>
#include <limits>

int main(void) {
    std::set<int16_t> numeros = {12, 22, 32, 42, 52};
    int16_t pesq;

    std::println("Valores no conjunto:");
    std::println("");
    for (const int16_t& numero : numeros) {
        std::println("{}", numero);
    }

    std::println("");
    std::cout << "Entre numero para pesquisar: ";
    std::cin >> pesq;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::set<int16_t>::iterator it = numeros.find(pesq);

    std::println("");
    if (it != numeros.end()) {
        std::println("Numero {} encontrado no conjunto.", pesq);
    } else {
        std::println("Numero {} nao encontrado.", pesq);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
