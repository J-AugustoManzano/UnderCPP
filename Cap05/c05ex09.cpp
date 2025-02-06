// c05ex09.cpp

#include <iostream>
#include <print>
#include <stdexcept>  // Para o uso de out_of_range

// Classe gen�rica Lista usando templates
template <typename T>
class Lista {
private:
    T* elementos;
    size_t tamanho;
    int16_t capacidade;

    // M�todo privado para redimensionar a lista se necess�rio
    void redimensionar(void) {
        capacidade *= 2;
        T* novosElementos = new T[capacidade];
        for (size_t i = 0; i < tamanho; ++i) {
            novosElementos[i] = elementos[i];
        }
        delete[] elementos;
        elementos = novosElementos;
    }

public:
    // Construtor
    Lista(size_t capacidadeInicial = 5)
        : tamanho(0), capacidade(capacidadeInicial) {
        elementos = new T[capacidade];
    }

    // Destrutor
    ~Lista() {
        delete[] elementos;
    }

    // Adiciona um elemento ao final da lista
    void adicionar(const T& item) {
        if (tamanho == capacidade) {
            redimensionar();
        }
        elementos[tamanho++] = item;
    }

    // Remove o �ltimo elemento da lista
    void remover(void) {
        if (tamanho > 0) {
            --tamanho;
        }
    }

    // Retorna o elemento no �ndice especificado
    T obter(uint16_t indice) const {
        if (indice >= 0 and indice < tamanho) {
            return elementos[indice];
        }
        throw std::out_of_range("Indice fora do intervalo!");
    }

    // Imprime todos os elementos da lista
    void imprimir(void) const {
        for (size_t i = 0; i < tamanho; ++i) {
            std::println("{}", elementos[i]);
        }
        std::print("");
    }

    // Retorna o tamanho atual da lista
    int obterTamanho(void) const {
        return tamanho;
    }
};

// Fun��o principal para testar a classe Lista
int main(void) {
    // Usando a classe gen�rica Lista com inteiros
    Lista<int> listaInteiros;
    listaInteiros.adicionar(10);
    listaInteiros.adicionar(20);
    listaInteiros.adicionar(30);
    listaInteiros.imprimir(); // Sa�da: 10 20 30

    listaInteiros.remover();
    listaInteiros.imprimir(); // Sa�da: 10 20

    // Usando a classe gen�rica Lista com strings
    Lista<std::string> listaStrings;
    listaStrings.adicionar("C++");
    listaStrings.adicionar("e");
    listaStrings.adicionar("poderoso");
    listaStrings.imprimir(); // Sa�da: C++ e poderoso

    listaStrings.remover();
    listaStrings.imprimir(); // Sa�da: C++ �

    // Testando acesso aos elementos
    std::println("Elemento no indice 1: {}", listaStrings.obter(1)); // Sa�da: �

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
