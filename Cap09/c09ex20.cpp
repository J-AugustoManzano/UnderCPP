// c09ex20.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <vector>

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

struct Pessoa {
  std::string nome;
  uint16_t idade;

  bool lerArq(std::fstream &arqbin) {
    uint64_t tamanho;
    char* conteudo = reinterpret_cast<char*>(&tamanho);
    arqbin.read(conteudo, sizeof(tamanho));
    if (arqbin.peek() == EOF) {
        return false;
    }

    std::vector<char> nome(tamanho + 1);
    arqbin.read(nome.data(), tamanho);
    nome[tamanho] = '\0';
    this->nome = std::string(nome.data());

    char* dados = reinterpret_cast<char*>(&idade);
    arqbin.read(dados, sizeof(idade));

    return true;
  }
};

int main(void) {
    Pessoa pessoa;
    std::fstream arqbin("arqbin7.dat", std::ios::in | std::ios::binary);
    if (not arqbin) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        pausa();
        return 1;
    }

    std::println("RELATORIO DE REGISTROS DE DADOS PESSOAIS");
    std::println("----------------------------------------");
    std::println("");
    std::println("{:<41}{:>9}", "Nome", "Idade");
    std::println("");

    while (pessoa.lerArq(arqbin)) {
        std::println("{:<41}{:>9}", pessoa.nome, pessoa.idade);
    }

    arqbin.close();

    pausa();
    return 0;
}
