// c03ex57.cpp

#include <iostream>
#include <print>

template <typename T, size_t linhas, size_t colunas>
void operacao(const T (&matriz)[linhas][colunas]) {
    std::println("Tamanho da matriz: {}x{}:", linhas, colunas);
    std::println("");
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("{:>2}", matriz[i][j]);
        }
        std::println("");
    }
}

int main(void) {
    int32_t matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    operacao(matriz);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
