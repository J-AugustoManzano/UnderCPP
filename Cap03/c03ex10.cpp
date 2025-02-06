// c03ex10.cpp

#include <iostream>
#include <string>
#include <print>
#include <limits>
#include <queue>

// Estrutura para gerenciar a fila com prioridade
using ItemFila = std::pair<std::pair<int16_t, int16_t>, std::string>;
using FilaPrioridade =
    std::priority_queue<ItemFila, std::vector<ItemFila>, std::greater<ItemFila>>;

FilaPrioridade fila;

uint16_t senhaAtualP = 0;  // Contador para senhas prioritárias
uint16_t senhaAtualC = 0;  // Contador para senhas comuns
uint16_t ordemChegada = 0; // Contador para ordem de chegada

std::string formatarSenha(int16_t tipoCliente, int16_t numero) {
    std::string prefixo = (tipoCliente == 1) ? "CP" : "CC";
    std::string numeroFormatado = std::to_string(numero);
    return prefixo + std::string(3 - numeroFormatado.length(), '0') + numeroFormatado;
}

void adicionar(int16_t tipoCliente) {
    std::string novaSenha;
    uint16_t prioridade;

    prioridade = (tipoCliente == 1) ? 1 : 2;

    if (tipoCliente == 1) {
        ++senhaAtualP;
    }
    if (tipoCliente == 2) {
        ++senhaAtualC;
    }

    novaSenha = formatarSenha(tipoCliente, (tipoCliente == 1) ? senhaAtualP : senhaAtualC);

    fila.push({{prioridade, ++ordemChegada}, novaSenha});
    std::print("Senha de atendimento {} ", novaSenha);
    if (tipoCliente == 1) {
        std::println("prioritaria");
    } else {
        std::println("normal");
    }
    std::println("");
}

void atender(void) {
    if (fila.empty()) {
        std::println("Fila vazia.\n");
    } else {
        std::string senhaAtendida = fila.top().second;
        fila.pop();
        std::println("Senha {} atendida.\n", senhaAtendida);
    }
}

void mostrar(void) {
    std::print("Fila de atendimento: ");

    if (fila.empty()) {
        std::println("(vazia).");
    } else {
        FilaPrioridade copiaFila = fila;

        std::println("\n");
        uint16_t pos = 1;
        while (not copiaFila.empty()) {
            std::println("{} - {}", ++pos, copiaFila.top().second);
            copiaFila.pop();
        }
    }
    std::println("");
}

int main(void) {
    int16_t opcao = 0;

    while (opcao != 4) {
        std::println("PROGRAMA: FILA BANCARIA\n");
        std::println("[1] - Chegada a fila");
        std::println("[2] - Atender cliente");
        std::println("[3] - Mostrar fila");
        std::println("[4] - Sair\n");
        std::print("Escolha uma opcao: ");
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        switch (opcao) {
            case 1: {
                int16_t tipoAtendimento;
                std::println("Tipo de atendimento:\n");
                std::println("[1] - Prioritario");
                std::println("[2] - Normal (comum)\n");
                std::print("Escolha uma opcao: ");
                std::cin >> tipoAtendimento;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;

                if (tipoAtendimento == 1 or tipoAtendimento == 2) {
                    adicionar(tipoAtendimento);
                } else {
                    std::println("Opcao invalida.\n");
                }
                break;
            }
            case 2:
                atender();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                std::println("Encerrando programa...");
                break;
            default:
                std::println("Opcao invalida. Tente novamente.");
        }
    }

    return 0;
}
