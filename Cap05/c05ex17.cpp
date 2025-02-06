// c05ex17.cpp

#include <iostream>
#include <print>
#include <string>

class Conta {
public:
    std::string titular;
    double saldo;

    Conta(const std::string& titular, double saldo) : titular(titular), saldo(saldo) {}

    void exibirSaldo(void) const {
        std::println("Saldo R$ ...: {:8.2f}", saldo);
    }

    void debitar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
        } else {
            std::println("Saldo insuficiente!");
        }
    }
};

class Transacao {
public:
    void realizarDebito(Conta& conta, double valor) {
        std::println("Debito R$ ..: {:8.2f} ", valor);
        conta.debitar(valor);
        conta.exibirSaldo();
    }
};

int main(void) {
    Conta contaCorrente("Maria", 1500.0);
    Transacao operacao;

    std::println("Cliente ....: {}", contaCorrente.titular);
    contaCorrente.exibirSaldo(); // Exibindo saldo inicial

    operacao.realizarDebito(contaCorrente, 253.89); // Realizando débito

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
