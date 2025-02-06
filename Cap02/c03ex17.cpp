// c03ex17.cpp

#include <iostream>
#include <vector>
#include <print>

int main(void) {
    // Matriz de notas (5 alunos em 3 disciplinas)
    std::vector<std::vector<float>> notas = {
        { 8.5f, 10.0f,  9.0f}, // Notas do aluno 1
        { 6.0f,  8.5f,  7.5f}, // Notas do aluno 2
        { 9.0f,  9.5f, 10.0f}, // Notas do aluno 3
        { 7.0f,  6.5f,  8.0f}, // Notas do aluno 4
        {10.0f,  9.0f,  8.5f}  // Notas do aluno 5
    };

    // Títulos das disciplinas
    std::vector<std::string> disciplinas = {"Matematica", "Portugues", "Ingles"};

    std::println("Notas dos Alunos:");
    std::println("");
    std::println("-------------------------------------------");
std::println("{:<10} {:>10} {:>10} {:>10}",
             "Aluno", disciplinas[0], disciplinas[1], disciplinas[2]);
    std::println("-------------------------------------------");

    for (size_t i = 0; i < notas.size(); ++i) {
        float soma = 0.0f;
        std::print("{:<10} ", "Aluno " + std::to_string(i + 1));

        // Exibe as notas e calcula a soma
        for (const float nota : notas[i]) {
            soma += nota;
            std::print("{:>10.1f} ", nota);
        }
        std::println("");

        // Calcula e exibe a média
        float media = soma / disciplinas.size();
        std::println("Media: {:>14.1f}", media);
        std::println("-------------------------------------------");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
