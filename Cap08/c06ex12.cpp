// c08ex12.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int16_t> dominio = {1, 2, 3, 4, 5};
    std::vector<int16_t> contradominio(dominio.size());

    // Função lambda para multiplicar por 3
    std::transform(dominio.begin(), dominio.end(), contradominio.begin(),
        [](int16_t x) { return x * 3; });

    // Exibindo o resultado
    for (size_t i = 0; i < dominio.size(); ++i) {
        std::println("{:>2} - {:>2}", dominio[i], contradominio[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
