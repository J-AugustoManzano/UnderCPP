// c05ex18.cpp

#include <iostream>
#include <print>
#include <string>
#include <vector>

class Funcionario {
public:
    std::string nome;
    double salario;

    Funcionario(const std::string& nome, double salario)
        : nome(nome), salario(salario) {}

    void exibirInformacoes() const {
        std::println("Nome: {}, Salario R$ {}", nome, salario);
    }
};

class Departamento {
public:
    std::string nome;
    std::vector<Funcionario> funcionarios;

    Departamento(const std::string& nome) : nome(nome) {}

    void adicionarFuncionario(const Funcionario& funcionario) {
        funcionarios.push_back(funcionario);
    }

    void exibirDepartamentos() const {
        std::println("Departamento: {}", nome);
        std::println("");
        for (const Funcionario& funcionario : funcionarios) {
            funcionario.exibirInformacoes();
        }
    }
};

int main(void) {
    Funcionario func1("Marisa", 3500.0);
    Funcionario func2("Carlos", 4500.0);

    Departamento dep("Recursos Humanos");
    dep.adicionarFuncionario(func1);
    dep.adicionarFuncionario(func2);

    dep.exibirDepartamentos();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
