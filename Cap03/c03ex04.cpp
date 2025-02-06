// c03ex04.cpp

#include <iostream>
#include <print>
#include <array>

int main(void) {
    std::array<std::array<float, 4>, 8> notas;

    for (size_t aluno = 0; aluno < notas.size(); ++aluno) {
        std::println("Entre as notas do aluno {}", aluno + 1);
        for (size_t nota = 0; nota < notas[aluno].size(); ++nota) {
            std::print("Nota {}: ", nota + 1);
            std::cin >> notas[aluno][nota];
        }
        std::println("");
    }

    std::println("------------------------------------------------------");
    std::println("|                  Tabela de Notas                   |");
    std::println("|  Aluno |   Nota 1 |   Nota 2 |   Nota 3 |   Nota 4 |");
    std::println("------------------------------------------------------");

    for (size_t aluno = 0; aluno < notas.size(); ++aluno) {
        std::print("| {:>6} |", aluno + 1);
        for (size_t nota = 0; nota < notas[aluno].size(); ++nota) {
            std::print("{:>9.2f} |", notas[aluno][nota]);
        }
        std::println("");
    }
    std::println("------------------------------------------------------");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
    std::cin.get();

    return 0;
}
