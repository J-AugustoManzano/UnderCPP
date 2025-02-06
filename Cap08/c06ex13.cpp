// c08ex13.cpp

#include <iostream>
#include <print>
#include <algorithm>
#include <string>
#include <vector>

struct Produto {
    std::string nome;
    double preco_base;
    double preco_final;
};

struct ProdutoDetalhado {
    std::string nome;
    double preco_base;
    double valor_imposto;
    double taxa_imposto; // Em percentual (20% = 0.2)
};

int main(void) {
    // Lista de produtos com preço base e preço final de venda
    std::vector<Produto> produtos = {
        {"Notebook", 2500.0, 3000.0},
        {"Smartphone", 1300.0, 1500.0},
        {"Tablet", 1080.0, 1200.0},
        {"Monitor", 675.0, 800.0}
    };

    // Vetor para armazenar os resultados detalhados
    std::vector<ProdutoDetalhado> produtos_detalhados(produtos.size());

    // Função de transformação
    std::transform(produtos.begin(), produtos.end(), produtos_detalhados.begin(),
        [](const Produto& produto) {
            double valor_imposto = produto.preco_final - produto.preco_base;
            double taxa_imposto = valor_imposto / produto.preco_base;
            return ProdutoDetalhado{
                produto.nome,
                produto.preco_base,
                valor_imposto,
                taxa_imposto
            };
        });

    // Exibir resultados
    for (const auto& produto : produtos_detalhados) {
        std::println("Produto ..............: {}", produto.nome);
        std::println("   Preco base ........: R$ {:>8.2f}", produto.preco_base);
        std::println("   Valor do imposto ..: R$ {:>8.2f}", produto.valor_imposto);
        std::println("   Taxa de imposto ...: {:>.2f}%", produto.taxa_imposto * 100);
        std::println("   Preco final .......: R$ {:>8.2f}",
            produto.preco_base + produto.valor_imposto);
        std::println("");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
