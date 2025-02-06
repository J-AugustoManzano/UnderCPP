// c03ex19.cpp

#include <iostream>
#include <vector>
#include <print>
#include <algorithm>

int main(void) {
    std::vector<int16_t> valores = {5, 2, 8, 1, 9};
    std::sort(valores.begin(), valores.end(), std::greater<int16_t>()); // ecrescente

    std::print("Ordem Decrescente: ");
    for (int16_t vlr : valores) {
        std::print("{} ", vlr);
    }

    std::println("\n");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
