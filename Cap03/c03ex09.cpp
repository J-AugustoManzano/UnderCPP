// c03ex09.cpp

#include <iostream>
#include <print>
#include <iomanip>
#include <deque>

const int16_t LIMITE {10};

std::deque<int16_t> dequeDados;

bool vazio(void) {
    return dequeDados.empty();
}

bool cheio(void) {
    return dequeDados.size() == LIMITE;
}

bool adicionarInicio(int16_t elemento) {
    if (cheio()) {
        return false;
    } else {
        dequeDados.push_front(elemento);
        return true;
    }
}

bool adicionarFim(int16_t elemento) {
    if (cheio()) {
        return false;
    } else {
        dequeDados.push_back(elemento);
        return true;
    }
}

bool retirarInicio(int16_t &elemento) {
    if (vazio()) {
        return false;
    } else {
        elemento = dequeDados.front();
        dequeDados.pop_front();
        return true;
    }
}

bool retirarFim(int16_t &elemento) {
    if (vazio()) {
        return false;
    } else {
        elemento = dequeDados.back();
        dequeDados.pop_back();
        return true;
    }
}

void inserirInicio(void) {
    int16_t elemento;
    std::print("Entre com um elemento numerico para inserir no inicio: ");
    std::cin >> elemento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    if (adicionarInicio(elemento)) {
        std::println("Elemento {} inserido no inicio do deque.", elemento);
    } else {
        std::println("Impossivel adicionar {} - deque cheio.", elemento);
    }
    std::println("");
}

void inserirFim(void) {
    int16_t elemento;
    std::print("Entre com um elemento numerico para inserir no fim: ");
    std::cin >> elemento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    if (adicionarFim(elemento)) {
        std::println("Elemento {} inserido no fim do deque.", elemento);
    } else {
        std::println("Impossivel adicionar {} - deque cheio.", elemento);
    }
    std::println("");
}

void removerInicio(void) {
    int16_t elemento;
    if (retirarInicio(elemento)) {
        std::println("Elemento {} removido do inicio do deque.", elemento);
    } else {
        std::println("Impossivel remover - deque vazio.");
    }
    std::println("");
}

void removerFim(void) {
    int16_t elemento;
    if (retirarFim(elemento)) {
        std::println("Elemento {} removido do fim do deque.", elemento);
    } else {
        std::println("Impossivel remover - deque vazio.");
    }
    std::println("");
}

void mostrar(void) {
    if (not vazio()) {
        size_t i {1};
        std::deque<int16_t> dequeTemp = dequeDados;

        while (not dequeTemp.empty()) {
            std::println("Posicao: {:>2} = {}", i, dequeTemp.front());
            dequeTemp.pop_front();
            ++i;
        }
    } else {
        std::println("Impossivel apresentar - deque vazio.");
    }
    std::println("");
}

void criar(void) {
    dequeDados.clear();
}

int main(void) {
    criar();
    int opcao = 0;

    while (opcao != 7) {
        std::println("PROGRAMA: DEQUE\n");
        std::println("[1] - Inserir no inicio");
        std::println("[2] - Inserir no fim");
        std::println("[3] - Remover do inicio");
        std::println("[4] - Remover do fim");
        std::println("[5] - Mostrar deque");
        std::println("[6] - Criar novo deque");
        std::println("[7] - Sair\n");
        std::print("Escolha uma opcao: ");
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        if (opcao != 7) {
            switch (opcao) {
                case 1: inserirInicio(); break;
                case 2: inserirFim(); break;
                case 3: removerInicio(); break;
                case 4: removerFim(); break;
                case 5: mostrar(); break;
                case 6: criar(); break;
                default:
                    std::println("Opcao invalida. Tente novamente.\n");
            }
        }
    }

    return 0;
}
