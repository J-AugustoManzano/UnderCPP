// c05ex03.cpp

#include <iostream>
#include <print>
#include <limits>

class Carro {
private:
    std::string modelo;
    int16_t ano;

    // Getters para acessar os atributos privados
    std::string pegaModelo(void) const {
        return modelo;
    }

    int16_t pegaAno(void) const {
        return ano;
    }

public:
    // Construtor com lista de inicialização
    Carro(const std::string& m, int16_t a) : modelo(m), ano(a) {
        // Exibe detalhes diretamente no construtor
        std::print("Construtor chamado para o ");
        std::println("Modelo: {}, Ano: {}", pegaModelo(), pegaAno());
    }

    // Destrutor
    ~Carro() {
        std::println("Destrutor chamado para o Modelo: {}", pegaModelo());
    }
};

int main(void) {
    // Criação do objeto 'Carro'
    Carro meuCarro("Toyota Corolla", 2024);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
