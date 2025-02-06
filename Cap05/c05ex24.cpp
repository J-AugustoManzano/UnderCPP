// c05ex24.cpp

#include <iostream>
#include <print>
#include <string>

class ContaBancaria {
private:
    std::string titular;
    double saldo;

    // Atributo est�tico para contar o n�mero total de contas criadas
    static size_t totalContas;

public:
    // Construtor que inicializa a conta e incrementa o contador est�tico
    ContaBancaria(const std::string& nomeTitular, double saldoInicial)
        : titular(nomeTitular), saldo(saldoInicial) {
        totalContas++; // Incrementa o total de contas criadas
    }

    // Destrutor para decrementar o total de contas quando um objeto � destru�do
    ~ContaBancaria() {
        totalContas--; // Decrementa o total de contas ao destruir uma inst�ncia
    }

    // M�todo para depositar dinheiro na conta
    void depositar(double valor) {
        saldo += valor;
        std::println("Deposito de R$ {} para a conta de {}",valor, titular);
    }

    // M�todo para sacar dinheiro da conta
    void sacar(double valor) {
        if (valor > 0 and valor <= saldo) {
            saldo -= valor;
            std::println("Saque de R$ {} realizado na conta de {}", valor, titular);
        } else {
            std::println("Saque de R$ {} nao realizado na conta de {}",valor, titular);
        }
    }

    // M�todo para exibir informa��es da conta
    void exibirSaldo(void) const {
        std::println("Titular: {}, Saldo: R$ {}", titular, saldo);
    }

    // M�todo est�tico para obter o n�mero total de contas
    static size_t pegaTotalContas(void) {
        return totalContas;
    }
};

// Inicializando o atributo est�tico fora da classe
size_t ContaBancaria::totalContas = 0;

int main(void) {
    // Criando algumas contas
    ContaBancaria conta1("Joao", 1500.0);
    ContaBancaria conta2("Maria", 2000.0);
    ContaBancaria conta3("Carlos", 500.0);

    // Exibindo o saldo inicial das contas
    std::println("--- Saldos Iniciais ---");
    std::println("");
    conta1.exibirSaldo();
    conta2.exibirSaldo();
    conta3.exibirSaldo();
    std::println("");

    // Realizando algumas opera��es de dep�sito e saque
    std::println("--- Operacoes ---");
    std::println("");
    conta1.depositar(500.0);      // Jo�o deposita R$ 500
    conta2.sacar(300.0);          // Maria saca R$ 300
    conta3.sacar(1000.0);         // Carlos tenta sacar mais do que possui
    std::println("");

    // Exibindo os saldos ap�s as opera��es
    std::println("--- Saldos Apos operacoes ---");
    std::println("");
    conta1.exibirSaldo();
    conta2.exibirSaldo();
    conta3.exibirSaldo();
    std::println("");

    // Exibindo o n�mero total de contas usando o m�todo est�tico
    std::println("Total de contas criadas: {}", ContaBancaria::pegaTotalContas());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
