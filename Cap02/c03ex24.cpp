// c03ex24.cpp

#include <iostream>
#include <algorithm>
#include <print>
#include <vector>
#include <limits>

int main(void) {
    std::vector<int16_t> numeros = {15, 25, 35, 45, 55};
    int16_t pesq;

    std::println("Valores no vetor:");
    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Posicao {}: {}", i, numeros[i]);
    }

    std::println("");
    std::cout << "Entre numero para pesquisar: ";
    std::cin >> pesq;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<int16_t>::iterator it = std::find(numeros.begin(), numeros.end(), pesq);

    std::println("");
    if (it != numeros.end()) {
        std::println("Numero {} esta na posicao {}.", pesq, std::distance(numeros.begin(), it));
    } else {
        std::println("Numero {} nao encontrado.", pesq);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
