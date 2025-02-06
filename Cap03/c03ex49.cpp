// c03ex49.cpp

#include <iostream>
#include <print>
#include <limits>

int main(void) {
    size_t linhas, colunas, totalElementos;
    int16_t pares = 0, impares = 0;
    double percentualPares, percentualImpares;

    // Entrada da quantidade de linhas e colunas
    std::print("Entre o numero de linhas da matriz ...: ");
    std::cin >> linhas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::print("Entre o numero de colunas da matriz ..: ");
    std::cin >> colunas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Alocação dinâmica da matriz
    int16_t** matriz = new int16_t*[linhas];  // Criação de um ponteiro para ponteiros
    for (size_t i = 0; i < linhas; ++i) {
        matriz[i] = new int16_t[colunas];     // Alocação de cada linha
    }

    // Entrada dos valores na matriz
    std::println("");
    std::println("Entre os valores inteiros para a matriz de {}x{}:", linhas, colunas);
    std::println("");
    for (size_t i = 0; i < linhas; ++i) {
        for (size_t j = 0; j < colunas; ++j) {
            std::print("Elemento [{},{}]: ", i + 1, j + 1);
            std::cin >> matriz[i][j];
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Contagem de pares e ímpares
            if (matriz[i][j] % 2 == 0) {
                ++pares;
            } else {
                ++impares;
            }
        }
    }

    // Exibindo os resultados
    totalElementos = linhas * colunas;
    percentualPares = (static_cast<double>(pares) / totalElementos) * 100;
    percentualImpares = (static_cast<double>(impares) / totalElementos) * 100;

    std::println("");
    std::println("Quantidade de numeros pares .....: {}", pares);
    std::println("Quantidade de numeros impares ...: {}", impares);
    std::println("Percentual de pares .............: {:.2f}%", percentualPares);
    std::println("Percentual de impares ...........: {:.2f}%", percentualImpares);

    // Liberação de memória alocada dinamicamente
    for (size_t i = 0; i < linhas; ++i) {
        delete[] matriz[i];  // Deleta cada linha da matriz
    }
    delete[] matriz;         // Deleta o ponteiro principal

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
