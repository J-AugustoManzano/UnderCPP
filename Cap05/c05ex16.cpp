// c05ex16.cpp

#include <iostream>
#include <print>
#include <string>
#include <vector>

class Disciplina {
public:
    std::string nome;
    Disciplina(const std::string& nome) : nome(nome) {}
};

class Professor {
public:
    std::string nome;
    std::vector<Disciplina*> disciplinas; // Associação simples por meio de ponteiros

    Professor(const std::string& nome) : nome(nome) {}

    void adicionarDisciplina(Disciplina* d) {
        disciplinas.push_back(d);
    }

    void listarDisciplinas(void) {
        std::println("Professor {}, ensina:", nome);
        for (Disciplina* d : disciplinas) {
            std::println("- {}", d->nome);
        }
    }
};

int main(void) {
    Professor prof("Dr. Joao");
    Disciplina d1("Matematica");
    Disciplina d2("Fisica");

    prof.adicionarDisciplina(&d1);
    prof.adicionarDisciplina(&d2);

    prof.listarDisciplinas();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
