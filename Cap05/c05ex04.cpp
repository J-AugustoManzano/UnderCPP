// c05ex04.cpp

#include <iostream>
#include <print>
#include <limits>
#include <string>

using str = std::string;

// Classe base para todos os tipos de clientes
class Cliente {
protected:
    str nome;
    str endereco;

public:
    Cliente(const str& n, const str& e)
        : nome(n), endereco(e) {}

    void exibirInformacoes(void) const {
        std::println("");
        std::println("Nome .........: {}", nome);
        std::println("Endereco .....: {}", endereco);

    }
};

// Cliente F�sico herda de Cliente
class ClienteFisico : public Cliente {
private:
    str cpf;

public:
    ClienteFisico(const str& n, const str& e, const str& d)
        : Cliente(n, e), cpf(d) {}

    void exibirInformacoes(void) const {
        Cliente::exibirInformacoes();
        std::println("CPF ..........: {}", cpf);
        std::println("");
    }
};

// Cliente Jur�dico herda de Cliente
class ClienteJuridico : public Cliente {
private:
    str cnpj;
    str razaoSocial;

public:
    ClienteJuridico(const str& n, const str& e, const str& d, const str& rs)
        : Cliente(n, e), cnpj(d), razaoSocial(rs) {}

    void exibirInformacoes(void) const {
        Cliente::exibirInformacoes();
        std::println("CNPJ .........: {}", cnpj);
        std::println("Razao Social .: {}", razaoSocial);
        std::println("");
    }
};

// Fun��o para exibir o menu
void exibirMenu(void) {
    std::println("CADASTRO E APRESENTACAO DE CLIENTE");
    std::println("==================================");
    std::println("");
    std::println("Menu");
    std::println("");
    std::println("[1] - Pessoa Fisica");
    std::println("[2] - Pessoa Juridica");
    std::println("[3] - Sair");
    std::println("");
    std::print("Escolha uma oppco: ");
}

// Fun��o para cadastrar cliente f�sico
void cadastrarClienteFisico(void) {
    str nome, endereco, cpf;

    std::print("Entre o nome ..........: ");
    std::getline(std::cin >> std::ws, nome);
    std::print("Entre o endereco ......: ");
    std::getline(std::cin >> std::ws, endereco);
    std::print("Entre o CPF ...........: ");
    std::getline(std::cin >> std::ws, cpf);

    ClienteFisico cliente(nome, endereco, cpf);

    std::println("");
    std::println("Cliente pessoa fisica cadastrado!");
    cliente.exibirInformacoes();
}

// Fun��o para cadastrar cliente jur�dico
void cadastrarClienteJuridico(void) {
    str nome, endereco, cnpj, razaoSocial;

    std::print("Entre o nome ..........: ");
    std::getline(std::cin >> std::ws, nome);
    std::print("Entre o endereco ......: ");
    std::getline(std::cin >> std::ws, endereco);
    std::print("Entre o CNPJ ..........: ");
    std::getline(std::cin >> std::ws, cnpj);
    std::print("Entre a razao social ..: ");
    std::getline(std::cin >> std::ws, razaoSocial);

    ClienteJuridico cliente(nome, endereco, cnpj, razaoSocial);

    std::println("");
    std::println("Cliente pessoa juridica cadastrado!");
    cliente.exibirInformacoes();
}

int main(void) {
    int opcao;

    do {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        switch (opcao) {
        case 1:
            cadastrarClienteFisico();
            break;
        case 2:
            cadastrarClienteJuridico();
            break;
        case 3:
            std::println("Saindo do programa...");
            std::println("");
            break;
        default:
            std::println("Opcao invalida! Tente novamente.");
            std::println("");
        }

    } while (opcao != 3);

    return 0;
}
