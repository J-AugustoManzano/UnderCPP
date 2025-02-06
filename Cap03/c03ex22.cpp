// c03ex22.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <print>

int main(void) {
    // Definindo a matriz bidimensional com nome e profissão
    std::vector<std::vector<std::string>> matriz = {
        {"Alice",    "Engenheira"},
        {"Carlos",   "Professor"},
        {"Bruna",    "Advogada"},
        {"Eduardo",  "Medico"},
        {"Fernanda", "Arquiteta"}
    };

    // Ordenação pelo nome (primeira coluna)
    std::sort(matriz.begin(), matriz.end(), [](
        const std::vector<std::string> &a, const std::vector<std::string> &b) {
        return a[0] < b[0];  // Comparação baseada na primeira coluna (nome)
    });

    std::println("Classificacao por Nome:");
    for (const std::vector<std::string> &linha : matriz) {
        std::println("Nome: {:<10} | Profissao: {:<10}", linha[0], linha[1]);
    }

    std::println("");

    // Ordenação pela profissão (segunda coluna)
    std::sort(matriz.begin(), matriz.end(), [](
        const std::vector<std::string> &a, const std::vector<std::string> &b) {
        return a[1] < b[1];  // Comparação baseada na segunda coluna (profissão)
    });

    std::println("Classificacao por Profissao:");
    for (const std::vector<std::string> &linha : matriz) {
        std::println("Profissao: {:<10} | Nome: {:<10}", linha[1], linha[0]);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
