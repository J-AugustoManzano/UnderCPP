// c05ex06.cpp

#include <iostream>
#include <print>
#include <string>

// Classe base Carro
class Carro {
private:
    std::string modelo;
    int16_t ano;

public:
    // Construtor para inicializar atributos
    Carro(const std::string& mod, int16_t ano) : modelo(mod), ano(ano) {}

    // Getters para acessar os atributos privados
    std::string pegaModelo(void) const { return modelo; }
    int16_t pegaAno() const { return ano; }

    // M�todo para exibir informa��es do carro
    void exibirCarro(void) const {
        std::println("Modelo: {}, Ano: {}", modelo, ano);
    }
};

// Classe base Motor
class Motor {
private:
    int16_t potencia;

public:
    // Construtor para inicializar atributos
    Motor(int16_t pot) : potencia(pot) {}

    // Getter para acessar a pot�ncia do motor
    int16_t pegaPotencia(void) const { return potencia; }

    // M�todo para exibir informa��es do motor
    void exibirMotor(void) const {
        std::println("Potencia: {} HP", potencia);
    }
};

// Classe derivada que herda de Carro e Motor
class VeiculoEsportivo : public Carro, public Motor {
private:
    double velocidadeMaxima;

public:
    // Construtor para inicializar todos os atributos
    VeiculoEsportivo(const std::string& mod, int16_t ano, int pot, double velMax)
        : Carro(mod, ano), Motor(pot), velocidadeMaxima(velMax) {}

    // M�todo para exibir todas as informa��es do ve�culo esportivo
    void exibirInformacoes(void) const {
        exibirCarro();
        exibirMotor();
        std::println("Velocidade Maxima: {} km/h", velocidadeMaxima);
    }
};

// Fun��o principal
int main(void) {
    // Criando um ve�culo esportivo com heran�a m�ltipla
    VeiculoEsportivo ferrari("Ferrari F8", 2023, 720, 340.0);

    // Exibindo as informa��es do ve�culo
    ferrari.exibirInformacoes();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
