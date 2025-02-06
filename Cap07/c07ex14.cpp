// c07ex14.cpp

#include <iostream>
#include <print>
#include <thread>
#include <vector>
#include <atomic>
#include <memory>

template <typename T>
class PilhaSemBloqueio {
private:
    struct Noh {
        T dado;
        Noh* proximo;
        Noh(T valor) : dado(valor), proximo(nullptr) {}
    };
    std::atomic<Noh*> cabeca;

public:
    PilhaSemBloqueio(void) : cabeca(nullptr) {}

    void empilhar(T valor) {
        Noh* novoNoh = new Noh(valor);
        Noh* cabecaAntiga;
        do {
            cabecaAntiga = cabeca.load();
            novoNoh->proximo = cabecaAntiga;
        } while (not cabeca.compare_exchange_weak(cabecaAntiga, novoNoh)); // CAS
    }

    bool desempilhar(T& resultado) {
        Noh* cabecaAntiga;
        do {
            cabecaAntiga = cabeca.load();
            if (not cabecaAntiga) return false; // Pilha vazia
        } while (not cabeca.compare_exchange_weak(cabecaAntiga, cabecaAntiga->proximo)); // CAS
        resultado = cabecaAntiga->dado;
        delete cabecaAntiga;
        return true;
    }
};

void testarPilhaSemBloqueio(PilhaSemBloqueio<int16_t>& pilha, int16_t id) {
    bool falhaSimulada = false;

    for (size_t i = 0; i <= 7; ++i) {
        pilha.empilhar(id * 8 + i);
        if (id == 1 and i == 5) {
            std::println("Thread {} simulando falha.", i);
            falhaSimulada = true;
            break;  // Encerra o laço
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    if (not falhaSimulada) {
        int16_t valor;
        for (size_t i = 0; i <= 7; ++i) {
            if (pilha.desempilhar(valor)) {
                std::println("Thread {} desempilhou: {:>2}", id, valor);
            }
        }
    }
}

int main(void) {
    PilhaSemBloqueio<int16_t> pilha;

    const int16_t numeroDeThreads = 4;
    std::vector<std::thread> fluxos;

    for (size_t i = 0; i < numeroDeThreads; ++i) {
        fluxos.push_back(std::thread(testarPilhaSemBloqueio, std::ref(pilha), i));
    }

    for (std::thread& fluxo : fluxos) {
        fluxo.join();
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}

