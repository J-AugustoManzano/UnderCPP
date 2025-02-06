// c04ex19.cpp

#include <iostream>
#include <print>
#include <limits>
#include <vector>
#include <stdexcept>

int main(void) {
    // Inicializando um vetor com alguns valores
    std::vector<int16_t> numeros = {10, 20, 30, 40, 50};

    // Exibindo os elementos do vetor antes de pedir o �ndice
    std::println("Elementos do vetor:");
    std::println("");
    for (size_t i = 0; i < numeros.size(); ++i) {
        std::println("Indice [{}]: {}", i, numeros[i]);
    }

    size_t indice;
    std::print("\nEntre o indice do elemento que deseja acessar (0 a {}): ", numeros.size() - 1);
    std::cin >> indice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        // Tentando acessar o elemento no �ndice fornecido
        int16_t valor = numeros.at(indice);  // .at() lan�a std::out_of_range se �ndice inv�lido
        std::println("\nValor no indice {}: {}", indice, valor);
    } catch (const std::out_of_range& e) {
        // Tratando a exce��o caso o �ndice esteja fora dos limites
        std::println("");
        std::cerr << "Erro: indice fora dos limites! Ocorrencia em: " << e.what() << std::endl;
        std::cerr << "Informe um indice entre 0 e " << numeros.size() - 1 << "." << std::endl;
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
