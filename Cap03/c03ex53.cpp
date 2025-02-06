// c03ex53.cpp

#include <print>
#include <iostream>
#include <limits>

void operacao(int16_t** matriz, size_t linhas, size_t colunas) {
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            matriz[i][j] += 5;  // Adiciona 5 a cada elemento
        }
    }
}

int main(void) {
    size_t linhas, colunas;

    std::print("Entre a quantidade de linhas ...:");
    std::cin >> linhas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::print("Entre a quantidade de colunas ..:");
    std::cin >> colunas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Alocação dinâmica da matriz
    int16_t** matriz = new int16_t*[linhas];
    for (size_t i = 0; i < linhas; ++i) {
        matriz[i] = new int16_t[colunas];
    }

    std::println("");
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("Entre o elemento [{},{}]: ", i + 1, j + 1);
            std::cin >> matriz[i][j];
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    operacao(matriz, linhas, colunas);

    std::println("");
    std::println("Matriz com valores incrementados por 5:");
     std::println("");
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("{:>5} ", matriz[i][j]);
        }
        std::println("");
    }

    // Liberação da memória
    for (size_t i = 0; i < linhas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

