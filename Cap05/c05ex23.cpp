// c05ex23.cpp

#include <iostream>
#include <print>
#include <string>

class GerenteBanco; // Declaração antecipada para uso na classe Conta

class Conta {
private:
    double saldo;

public:
    // Construtor para inicializar o saldo
    explicit Conta(double saldoInicial) : saldo(saldoInicial) {}

    // Função para depositar dinheiro
    void depositar(double valor) {
        saldo += valor;
    }

    // Função para sacar dinheiro
    void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
        } else {
            std::println("Saldo insuficiente para saque!");
        }
    }

    // Método para exibir o saldo (normalmente privado)
    void exibirSaldo() const {
        std::println("R$ {}", saldo);
    }

    // Declarar a classe GerenteBanco como amiga
    friend class GerenteBanco;
};

class GerenteBanco {
private:
    std::string nome;

public:
    // Construtor para inicializar o nome do gerente
    explicit GerenteBanco(const std::string& nome) : nome(nome) {}

    // Função amiga para acessar o saldo privado da Conta
    void verificarSaldo(const Conta& conta) const {
        std::println("O gerente {} verificou o saldo .....: R$ {}", nome,  conta.saldo);
    }

    // Função amiga para ajustar o saldo (usado apenas em casos excepcionais)
    void ajustarSaldo(Conta& conta, double novoSaldo) const {
        conta.saldo = novoSaldo;
        std::println("O gerente {} ajustou o saldo para ..: R$ {}", nome, novoSaldo);
    }
};

int main(void) {
    // Criar uma conta com saldo inicial de R$ 1000
    Conta minhaConta(1000.0);

    // Criar um gerente de banco
    GerenteBanco gerente("Carlos");

    // Exibir o saldo antes do ajuste
    std::print("Saldo antes do ajuste -> ");
    minhaConta.exibirSaldo();
    std::println("");

    // O gerente pode acessar o saldo diretamente
    gerente.verificarSaldo(minhaConta);

    // Realizar alguns ajustes (permitido apenas ao gerente)
    gerente.ajustarSaldo(minhaConta, 2000.0);
    std::println("");

    // Exibir o saldo após o ajuste
    std::print("Saldo apos o ajuste -> ");
    minhaConta.exibirSaldo();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
