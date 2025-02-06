// c08ex17.cpp

#include <iostream>
#include <print>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

// Estrutura para representar uma transação
struct Transacao {
    int id;
    double valor;
    std::string descricao;
};

int main(void) {
    // Lista de transações
    std::vector<Transacao> transacoes = {
        {1, 5000.00, "Transferencia bancaria"},
        {2, 150.00, "Pagamento de conta"},
        {3, 7500.00, "Compra de equipamento"},
        {4, 200.00, "Pagamento de servico"}
    };

    // Lista para armazenar transações acima de R$ 1000
    std::vector<Transacao> transacoesSuspeitas;

    // Filtro para transações com valor maior que 1000
    std::copy_if(transacoes.begin(), transacoes.end(), std::back_inserter(transacoesSuspeitas),
        [](const Transacao& transacao) { return transacao.valor > 1000.0; });

    // Exibir as transações suspeitas
    std::println("Transacoes suspeitas:");
    std::println("");
    for (const auto& transacao : transacoesSuspeitas) {
        std::println("ID: {} - Valor: R$ {} - Descricao {}",
            transacao.id, transacao.valor, transacao.descricao);
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
