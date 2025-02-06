// c03ex12.cpp

#include <iostream>
#include <print>
#include <map>
#include <string>
#include <limits>

using IteratorFruta = std::map<std::string, size_t>::const_iterator;

std::string entraFruta(void) {
    std::string nome;
    std::print("Entre o nome da fruta ..: ");
    std::getline(std::cin, nome);
    return nome;
}

size_t entraQuantidade(void) {
    size_t quantidade;
    std::print("Entre a quantidade .....: ");
    std::cin >> quantidade;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return quantidade;
}

void exibirMenu(void) {
    std::println("INVENTARIO ESTOQUE DE FRUTAS");
    std::println("");
    std::println("[1] Adicionar fruta");
    std::println("[2] Remover fruta");
    std::println("[3] Buscar fruta");
    std::println("[4] Exibir inventario");
    std::println("[5] Sair");
    std::println("");
    std::print("Escolha uma opcao: ");
}

void adicionarFruta(std::map<std::string, size_t> &frutas) {
    std::string nome = entraFruta();
    size_t quantidade = entraQuantidade();

    // Aumenta a quantidade do estoque de frutas
    frutas[nome] += quantidade;
    std::println("{} adicionada com sucesso! Estoque tem {} unidades.", nome, frutas[nome]);
    std::println("");
}

void removerFruta(std::map<std::string, size_t> &frutas) {
    std::string nome = entraFruta();
    std::map<std::string, size_t>::iterator it = frutas.find(nome);

    if (it != frutas.end()) {
        size_t quantidadeARemover = entraQuantidade();

        // Verifica se a quantidade a ser removida não é maior que o estoque atual
        if (quantidadeARemover >= (*it).second) {
            frutas.erase(it);
            std::println("{} removida com sucesso. Quantidade atual: 0)", nome);
        } else {
            (*it).second -= quantidadeARemover;
            std::println("Quantidade de {} reduzida para {}.", nome, (*it).second);
        }
        std::println("");
    } else {
        std::println("Fruta nao encontrada.");
        std::println("");
    }
}

void buscarFruta(const std::map<std::string, size_t> &frutas) {
    std::string nome = entraFruta();

    IteratorFruta it = frutas.find(nome); // Usando o alias
    if (it != frutas.end()) {
        std::println("{} encontrada. Quantidade: {}.", nome, (*it).second);
        std::println("");
    } else {
        std::println("Fruta nao encontrada.");
        std::println("");
    }
}

void exibirInventario(const std::map<std::string, size_t> &frutas) {
    std::println("LISTA DE FRUTAS");
    std::println("");

    if (frutas.empty()) {
        std::println("Lista vazia.");
        std::println("");
    } else {
        for (IteratorFruta it = frutas.begin(); it != frutas.end(); ++it) {
            std::string nomeFruta = (*it).first;
            size_t quantidadeFruta = (*it).second;
            std::println("{:<10} : {:>6}", nomeFruta, quantidadeFruta);
        }
        std::println("");
    }
}

int main(void) {
    std::map<std::string, size_t> frutas;
    int16_t opcao = 0;

    while (opcao != 5) {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        switch (opcao) {
            case 1:
                adicionarFruta(frutas);
                break;
            case 2:
                removerFruta(frutas);
                break;
            case 3:
                buscarFruta(frutas);
                break;
            case 4:
                exibirInventario(frutas);
                break;
            case 5:
                std::println("Encerrando programa...");
                break;
            default:
                std::println("Opcao invalida. Tente novamente.");
        }
    }

    return 0;
}
