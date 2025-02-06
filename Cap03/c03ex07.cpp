/// c08ex07.cpp

#include <iostream>
#include <print>
#include <iomanip>
#include <list>

const int16_t LIMITE {10};

std::list<int16_t> pilha;

bool vazia(void) {
    return pilha.empty();
}

bool cheia(void) {
    return pilha.size() == LIMITE;
}

bool adicionar(int16_t elemento) {
    if (cheia()) {
        return false;
    } else {
        pilha.push_back(elemento);
        return true;
    }
}

bool retirar(int16_t &elemento) {
    if (vazia()) {
        return false;
    } else {
        elemento = pilha.back();
        pilha.pop_back();
        return true;
    }
}

void empilhar(void) {
    int16_t elemento;
    std::print("Entre com um elemento numerico: ");
    std::cin >> elemento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    if (adicionar(elemento)) {
        std::println("Elemento {} inserido na pilha.", elemento);
    } else {
        std::println("Impossivel adicionar {} - pilha cheia.", elemento);
    }
    std::println("");
}

void desempilhar(void) {
    int16_t elemento;
    if (retirar(elemento)) {
        std::println("Elemento {} retirado do topo da pilha.", elemento);
    } else {
        std::println("Impossivel retirar elemento - pilha vazia.");
    }
    std::println("");
}

void mostrar(void) {
    if (not vazia()) {
        size_t i {1};
        std::list<int16_t> lstTemp = pilha;

        while (not lstTemp.empty()) {
            std::println("Posicao: {:>2} = {}", i, lstTemp.back());
            lstTemp.pop_back();
            ++i;
        }
    } else {
        std::println("Impossivel apresentar - pilha vazia.");
    }
    std::println("");
}

void criar(void) {
    pilha.clear();
}

int main(void) {
    criar();
    int opcao = 0;

    while (opcao != 5) {
        std::println("PROGRAMA: PILHA\n");
        std::println("[1] - Empilhar");
        std::println("[2] - Desempilhar");
        std::println("[3] - Mostrar");
        std::println("[4] - Criar pilha");
        std::println("[5] - Sair\n");
        std::print("Escolha uma opcao: ");
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        if (opcao != 5) {
            switch (opcao) {
                case 1: empilhar(); break;
                case 2: desempilhar(); break;
                case 3: mostrar(); break;
                case 4: criar(); break;
                default:
                    std::println("Opcao invalida. Tente novamente.\n");
            }
        }
    }

    return 0;
}
