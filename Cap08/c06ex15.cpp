// c08ex15.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int16_t> dominio = {1, 2, 3, 4, 5};
    std::vector<int16_t> contradominio;

    // Filtrando números ímpares
    std::copy_if(dominio.begin(), dominio.end(), std::back_inserter(contradominio),
                 [](int16_t x) { return x % 2 != 0; });

    // Exibindo o resultado
    for (int16_t x : contradominio) {
        std::println("{:>2}", x);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
