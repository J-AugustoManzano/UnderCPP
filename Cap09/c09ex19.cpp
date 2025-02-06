// c09ex19.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <limits>

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

struct Pessoa {
  std::string nome;
  uint16_t idade;

  void escreverArq(std::fstream& arqbin) {
    uint64_t tamanho = nome.size();
    char* nomeCad = reinterpret_cast<char*>(&tamanho);
    char* idadeCad = reinterpret_cast<char*>(&idade);
    arqbin.write(nomeCad, sizeof(tamanho));
    arqbin.write(nome.c_str(), tamanho);
    arqbin.write(idadeCad, sizeof(uint16_t));
  }
};

int main(void)
{
  char resp;
  std::fstream arqbin("arqbin7.dat", std::ios::app | std::ios::binary);
  if (not arqbin) {
    std::cerr << "Erro ao abrir o arquivo." << std::endl;
    pausa();
    return 1;
  }

  std::println("CADASTRO DE REGISTRO DE DADOS PESSOAIS");
  std::println("--------------------------------------");

  do {
    std::println("");
    std::print("Entre nome ...: ");
    std::string nome;
    getline(std::cin, nome);
    std::print("Entre idade ..: ");
    uint16_t idade;
    std::cin >> idade;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Pessoa pessoa;
    pessoa.nome = nome;
    pessoa.idade = idade;

    pessoa.escreverArq(arqbin);

    std::println("");
    std::print("Deseja continuar? [S] Sim ");
    std::print("[qualquer letra] Nao --> ");
    std::cin.get(resp);
    std::cin.ignore();
  } while (toupper(resp) == 'S');

  arqbin.close();

  pausa();
  return 0;
}
