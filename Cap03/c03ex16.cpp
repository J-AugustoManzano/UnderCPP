// c03ex16.cpp

#include <iostream>
#include <vector>
#include <print>

#include<iomanip>

int main(void) {
    std::vector<int16_t> dominio = {2, 4, 6, 8, 10};
    std::vector<int16_t> imagem;

    for (const int16_t valor : dominio) {
        imagem.push_back(valor * 3);
    }

    std::println("Dominio  Imagem");
    std::println("---------------");

    for (size_t i = 0; i < dominio.size(); ++i) {
        std::println("{:>7} {:>7}", dominio[i], imagem[i]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
