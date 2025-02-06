// c05ex24.cpp

#include <iostream>
#include <print>
#include <string>

class ContaBancaria {
private:
    std::string titular;
    double saldo;

    // Atributo estático para contar o número total de contas criadas
    static size_t totalContas;

public:
    // Construtor que inicializa a conta e incrementa o contador estático
    ContaBancaria(const std::string& nomeTitular, double saldoInicial)
        : titular(nomeTitular), saldo(saldoInicial) {
        totalContas++; // Incrementa o total de contas criadas
    }

    // Destrutor para decrementar o total de contas quando um objeto é destruído
    ~ContaBancaria() {
        totalContas--; // Decrementa o total de contas ao destruir uma instância
    }

    // Método para depositar dinheiro na conta
    void depositar(double valor) {
        saldo += valor;
        std::println("Deposito de R$ {} para a conta de {}",valor, titular);
    }

    // Método para sacar dinheiro da conta
    void sacar(double valor) {
        if (valor > 0 and valor <= saldo) {
            saldo -= valor;
            std::println("Saque de R$ {} realizado na conta de {}", valor, titular);
        } else {
            std::println("Saque de R$ {} nao realizado na conta de {}",valor, titular);
        }
    }

    // Método para exibir informações da conta
    void exibirSaldo(void) const {
        std::println("Titular: {}, Saldo: R$ {}", titular, saldo);
    }

    // Método estático para obter o número total de contas
    static size_t pegaTotalContas(void) {
        return totalContas;
    }
};

// Inicializando o atributo estático fora da classe
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

    // Realizando algumas operações de depósito e saque
    std::println("--- Operacoes ---");
    std::println("");
    conta1.depositar(500.0);      // João deposita R$ 500
    conta2.sacar(300.0);          // Maria saca R$ 300
    conta3.sacar(1000.0);         // Carlos tenta sacar mais do que possui
    std::println("");

    // Exibindo os saldos após as operações
    std::println("--- Saldos Apos operacoes ---");
    std::println("");
    conta1.exibirSaldo();
    conta2.exibirSaldo();
    conta3.exibirSaldo();
    std::println("");

    // Exibindo o número total de contas usando o método estático
    std::println("Total de contas criadas: {}", ContaBancaria::pegaTotalContas());

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
