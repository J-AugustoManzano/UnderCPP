// c03ex21.cpp

#include <iostream>
#include <set>
#include <print>

int main(void) {
    std::set<int16_t, std::greater<int16_t>> meuSet = {1, 2, 3, 4, 5};

    for (const int16_t valor : meuSet) {
        std::print("{} ", valor);
    }

    std::println("\n");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
