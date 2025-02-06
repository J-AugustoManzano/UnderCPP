// c05ex24.cpp

#include <iostream>
#include <print>
#include <string>

class Pessoa {
private:
    std::string nome;

public:
    // Construtor que usa o ponteiro this para diferenciar o atributo do par�metro
    Pessoa(const std::string& nome) {
        this->nome = nome; // 'this->nome' refere-se ao atributo, enquanto 'nome' � o par�metro
    }

    // M�todo para exibir o nome
    void pegaNome(void) const {
        std::println("Nome: {}", this->nome);
    }
};

int main(void) {
    Pessoa pessoa("Marta");
    pessoa.pegaNome();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
