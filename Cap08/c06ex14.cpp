// c08ex14.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

struct Cliente {
    std::string nome;
    double investimento;
    std::string moeda;
};

struct ClienteBRL {
    std::string nome;
    double investimento_brl;
};

int main() {
    // Dados de entrada
    std::vector<Cliente> clientes = {
        {"Ana", 1000, "USD"},
        {"Carlos", 850, "EUR"},
        {"Joana", 4000, "BRL"}
    };

    // Taxas de câmbio
    std::map<std::string, double> taxas_cambio = {
        {"USD", 5.0},
        {"EUR", 6.0},
        {"BRL", 1.0}
    };

    // Vetor para armazenar os resultados
    std::vector<ClienteBRL> investimentos_brl(clientes.size());

    // Função de transformação
    std::transform(clientes.begin(), clientes.end(), investimentos_brl.begin(),
        [&taxas_cambio](const Cliente& cliente) {
            return ClienteBRL{
                cliente.nome,
                cliente.investimento * taxas_cambio[cliente.moeda]
            };
        });

    // Exibir resultados
    for (const auto& cliente : investimentos_brl) {
        std::println("Nome: {:<10}| Investimento em BRL: {:>5}",
            cliente.nome, cliente.investimento_brl);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
