// c03ex05.cpp

#include <iostream>
#include <print>
#include <vector>

int main(void) {
    size_t linhas, colunas;

    std::print("Entre o numero de linhas ...: ");
    std::cin >> linhas;
    std::print("Entre o numero de colunas ..: ");
    std::cin >> colunas;
    std::println("");

    std::vector<std::vector<float>> matriz(linhas, std::vector<float>(colunas));

    for (size_t i = 0; i < linhas; ++i) {
        std::println("Entre os dados da linha {}", i + 1);
        for (size_t j = 0; j < colunas; ++j) {
            std::print("Elemento [{}][{}]: ", i + 1, j + 1);
            std::cin >> matriz[i][j];
        }
        std::println("");
    }

    std::println("---------------");
    std::println("Tabela de Dados");
    std::println("---------------");
    std::println("");
    std::print("|  Itens |");
    for (size_t j = 0; j < colunas; ++j) {
        std::print(" Coluna {:>2} |", j + 1);
    }
    std::println("");
    std::print("----------");
    for (size_t j = 0; j < (colunas - 1); ++j) {
        std::print("---------------");
    }
    std::println("");

    for (size_t i = 0; i < linhas; ++i) {
        std::print("|{:>7} |", i + 1);
        for (size_t j = 0; j < colunas; ++j) {
            std::print("{:>10.2f} |", matriz[i][j]);
        }
        std::println("");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    std::cin.get();

    return 0;
}
