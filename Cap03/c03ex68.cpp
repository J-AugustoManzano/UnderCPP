// c03ex68.cpp

#include <print>
#include <iostream>
#include <limits>

struct PessoaFisica {
    char cpf[15];  // CPF para formatação xxx.xxx.xxx-xx (14+1)
};

struct PessoaJuridica {
    char cnpj[20];  // CNPJ para formatação xx.xxx.xxx/xxxx-xx (19+1)
};

// Definição da union para armazenar CPF ou CNPJ
union Pessoa {
    PessoaFisica fisica;
    PessoaJuridica juridica;
};

struct Cliente {
    std::string nome;
    char tipo;
    Pessoa pessoa;
};

int main(void) {
    Cliente cliente;

    // Entrada de dados
    std::print("Informe o nome ........: ");
    std::getline(std::cin, cliente.nome);
    do {
      std::print("Informe o tipo (F/J) ..: ");
      std::cin >> cliente.tipo;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (cliente.tipo != 'F' and cliente.tipo != 'J') {
          std::println("Tipo invalido! Informe 'F' ou 'J'.");
      }
    } while (cliente.tipo != 'F' and cliente.tipo != 'J');

    if (cliente.tipo == 'F') {
        std::print("Informe o CPF .........: ");
        std::cin >> cliente.pessoa.fisica.cpf;
    } else if (cliente.tipo == 'J') {
        std::print("Informe o CNPJ ........: ");
        std::cin >> cliente.pessoa.juridica.cnpj;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Exibição dos dados coletados
    std::println("\nDados do cliente\n");
    std::println("Nome ..................: {}", cliente.nome);
    if (cliente.tipo == 'F') {
        std::string cpf(cliente.pessoa.fisica.cpf);
        std::println("CPF ...................: {}", cpf);
    } else if (cliente.tipo == 'J') {
        std::string cnpj(cliente.pessoa.juridica.cnpj);
        std::println("CNPJ ..................: {}", cnpj);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
