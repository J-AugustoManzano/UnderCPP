// c08ex19.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>
#include <numeric>

int main(void) {
    std::vector<int16_t> dominio = {1, 2, 3, 4, 5};

    // Soma dos elementos
    int16_t resultado = std::accumulate(dominio.begin(), dominio.end(), 1,
        [](int64_t a, int64_t b) { return a * b; } );

    std::println("Soma: {}", resultado);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
