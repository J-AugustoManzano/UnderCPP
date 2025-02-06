// c08ex08.cpp

#include <iostream>
#include <print>
#include <iomanip>
#include <list>

const int16_t LIMITE {10};

std::list<int16_t> fila;

bool vazia(void) {
    return fila.empty();
}

bool cheia(void) {
    return fila.size() == LIMITE;
}

bool adicionar(int16_t elemento) {
    if (cheia()) {
        return false;
    } else {
        fila.push_back(elemento);
        return true;
    }
}

bool retirar(int16_t &elemento) {
    if (vazia()) {
        return false;
    } else {
        elemento = fila.front();
        fila.pop_front();
        return true;
    }
}

void entrada(void) {
    int16_t elemento;
    std::print("Entre com um elemento numerico: ");
    std::cin >> elemento;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::println("");

    if (adicionar(elemento)) {
        std::println("Elemento {} inserido na fila.", elemento);
    } else {
        std::println("Impossivel adicionar {} - fila cheia.", elemento);
    }
    std::println("");
}

void saida(void) {
    int16_t elemento;
    if (retirar(elemento)) {
        std::println("Elemento {} retirado do inicio da fila.", elemento);
    } else {
        std::println("Impossivel retirar elemento - fila vazia.");
    }
    std::println("");
}

void atual(void) {
    if (not vazia()) {
        std::println("Primeiro elemento da fila: {}", fila.front());
    } else {
        std::println("Impossivel apresentar - fila vazia.");
    }
    std::println("");
}

void mostrar(void) {
    if (not vazia()) {
        size_t i {1};
        std::list<int16_t> filaTemp = fila;

        while (not filaTemp.empty()) {
            std::println("Posicao: {:>2} = {}", i, filaTemp.front());
            filaTemp.pop_front();
            ++i;
        }
    } else {
        std::println("Impossivel apresentar - fila vazia.");
    }
    std::println("");
}

void criar(void) {
    fila.clear();
}

int main(void) {
    criar();
    int opcao = 0;

    while (opcao != 6) {
        std::println("PROGRAMA: FILA\n");
        std::println("[1] - Entrada");
        std::println("[2] - Saida");
        std::println("[3] - Apresentar 1o. da fila");
        std::println("[4] - Apresentar a fila");
        std::println("[5] - Nova fila");
        std::println("[6] - Sair\n");
        std::print("Escolha uma opcao: ");
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        if (opcao != 6) {
            switch (opcao) {
                case 1: entrada(); break;
                case 2: saida();   break;
                case 3: atual();   break;
                case 4: mostrar(); break;
                case 5: criar();   break;
                default:
                    std::println("Opcao invalida. Tente novamente.\n");
            }
        }
    }

    return 0;
}
