// c03ex52.cpp

#include <print>
#include <iostream>
#include <limits>

void operacao(int32_t matriz[][4], size_t linhas) {
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j <= 3; ++j) {
            matriz[i][j] *= 2;
        }
    }
}

int main(void) {
    const size_t linhas = 3;
    const size_t colunas = 4;
    int32_t matriz[linhas][colunas];

    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("Entre o elemento [{},{}]: ", i + 1, j + 1);
            std::cin >> matriz[i][j];
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    operacao(matriz, linhas);

    std::println("");
    std::println("Matriz com valores dobrados:");
    std::println("");
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("{:>5} ", matriz[i][j]);
        }
        std::println("");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
