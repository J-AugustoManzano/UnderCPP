// c08ex16.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

// Estrutura para representar um cliente
struct Cliente {
    std::string nome;
    double totalCompras;
};

int main(void) {
    // Lista de clientes
    std::vector<Cliente> clientes = {
        {"Ana", 1500.00},
        {"Carlos", 700.00},
        {"Beatriz", 1200.00},
        {"Joao", 500.00}
    };

    // Lista para armazenar clientes filtrados
    std::vector<Cliente> clientesVip;

    // Filtro para clientes com total de compras acima de 1000
    std::copy_if(clientes.begin(), clientes.end(), std::back_inserter(clientesVip),
        [](const Cliente& cliente) { return cliente.totalCompras > 1000.0; });

    // Exibir os clientes VIPs
    std::println("Clientes VIP:");
    std::println("");
    for (const auto& cliente : clientesVip) {
        std::println("{:<8} - Compras: R$ {:>7.2f}", cliente.nome, cliente.totalCompras);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
