// c03ex11.cpp

#include <iostream>
#include <print>
#include <set>
#include <string>
#include <limits>

std::string entraFruta(void) {
    std::string nome;
    std::print("Entre o nome da fruta: ");
    std::getline(std::cin, nome);
    return nome;
}

void exibirMenu(void) {
    std::println("LISTA DE FRUTAS");
    std::println("");
    std::println("[1] Adicionar fruta");
    std::println("[2] Remover fruta");
    std::println("[3] Buscar fruta");
    std::println("[4] Exibir inventario");
    std::println("[5] Sair");
    std::println("");
    std::print("Escolha uma oppco: ");
}

void adicionarFruta(std::set<std::string> &frutas) {
    std::string nome;

    std::println("CADASTRO DE FRUTAS");
    std::println("");
    nome = entraFruta();

    if (frutas.find(nome) != frutas.end()) {
        std::println("Fruta existente na lista.");
        std::println("");
    } else {
        frutas.insert(nome);
        std::println("{} adicionada com sucesso!", nome);
        std::println("");
    }
}

void removerFruta(std::set<std::string> &frutas) {
    std::string nome;

    std::println("REMOCAO DE FRUTAS");
    std::println("");
    nome = entraFruta();

    std::set<std::string>::iterator it = frutas.find(nome);
    if (it != frutas.end()) {
        frutas.erase(it);
        std::println("{} removida com sucesso.", nome);
        std::println("");
    } else {
        std::println("Fruta nao encontrada.");
        std::println("");
    }
}

void buscarFruta(const std::set<std::string> &frutas) {
    std::string nome;

    std::println("BUSCA DE FRUTAS");
    std::println("");
    nome = entraFruta();

    if (frutas.find(nome) != frutas.end()) {
        std::println("{} encontrada.", nome);
        std::println("");
    } else {
        std::println("Fruta nao encontrada.");
        std::println("");
    }
}

void exibirInventario(const std::set<std::string> &frutas) {
    std::println("LISTA DE FRUTAS");
    std::println("");

    if (frutas.empty()) {
        std::println("Lista vazia.");
        std::println("");
    } else {
        std::set<std::string>::const_iterator it;
        for (it = frutas.begin(); it != frutas.end(); ++it) {
            std::println("{}", *it);
        }
        std::println("");
    }
}

int main(void) {
    std::set<std::string> frutas;
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
                std::println("Oppco invalida. Tente novamente.");
        }
    }

    return 0;
}
