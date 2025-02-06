// c03ex67.cpp

#include <iostream>
#include <string>
#include <print>
#include <limits>

// Definição da struct para armazenar série e sala
struct Posicao {
    char serie;        // Série do estudante (ex: 'A', 'B', etc.)
    size_t sala;       // Número da sala
};

// Definição da struct para armazenar informações de um estudante
struct Estudante {
    std::string nome;  // Nome do estudante
    int idade;         // Idade do estudante
    double notaFinal;  // Nota final do estudante
    Posicao posicao;   // Informações sobre série e sala
};

// Entrada dos dados
void entradaDados(Estudante& estudante) {
    std::print("Entre o nome ...: ");
    std::getline(std::cin, estudante.nome);

    std::print("Entre a idade ..: ");
    std::cin >> estudante.idade;

    std::print("Entre a media ..: ");
    std::cin >> estudante.notaFinal;

    std::print("Entre a serie ..: ");
    std::cin >> estudante.posicao.serie;

    std::print("Entre a sala ...: ");
    std::cin >> estudante.posicao.sala;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Saída dos dados
void exibirDados(const Estudante& estudante) {
    std::println("");
    std::println("=== Dados do Estudante ===");
    std::println("");
    std::println("Nome ...: {}", estudante.nome);
    std::println("Idade ..: {}", estudante.idade);
    std::println("Media ..: {:.2f}", estudante.notaFinal);
    std::println("Serie ..: {}", estudante.posicao.serie);
    std::println("Sala ...: {}", estudante.posicao.sala);
}

int main(void) {
    Estudante estudante;

    // Coleta de dados
    entradaDados(estudante);

    // Exibe os dados coletados
    exibirDados(estudante);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
