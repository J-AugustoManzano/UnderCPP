// c08ex18.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>
#include <numeric> // Para std::accumulate

int main(void) {
    std::vector<int16_t> dominio = {1, 2, 3, 4, 5};

    // Soma dos elementos
    int16_t resultado = std::accumulate(dominio.begin(), dominio.end(), 0);

    std::println("Soma: {}", resultado);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
