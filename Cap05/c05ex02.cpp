// c05ex02.cpp

#include <iostream>
#include <print>
#include <limits>

class Carro {
private:
    std::string modelo;
    int16_t ano;

    // M�todos getters para acessar os atributos de forma interna
    // Sub-rotina membro do tipo fun��o
    std::string pegaModelo(void) const {
        return modelo;
    }

    int16_t pegaAno(void) const {
        return ano;
    }

public:
    // M�todos setters para modificar os atributos
    // Sub-rotina membro do tipo procedimento
    void poeModelo(const std::string& m) {
        modelo = m;
    }

    void poeAno(int16_t a) {
        ano = a;
    }

    // M�todo para exibir os detalhes do carro
    void exibeDetalhes(void) const {
        std::println("");
        std::println("Modelo: {}, Ano: {}", pegaModelo(), pegaAno());
    }
};

int main(void) {
    Carro meuCarro;

    // Vari�veis para solicitar ao usu�rio o modelo e o ano do carro
    std::string modelo;
    int16_t ano;

    std::print("Entre o modelo do carro ..: ");
    std::getline(std::cin, modelo);  // Captura o modelo com espa�os

    std::print("Entre o ano do carro .....: ");
    std::cin >> ano;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Usar os setters para atribuir valores aos atributos privados
    meuCarro.poeModelo(modelo);
    meuCarro.poeAno(ano);

    // Exibir os detalhes do carro obtidos a partir dos getters
    meuCarro.exibeDetalhes();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

