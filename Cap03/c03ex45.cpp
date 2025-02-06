// c03ex45.cpp

#include <iostream>
#include <print>
#include <memory>
#include <limits>

int main(void) {
    int16_t tamanho;

    // Pedir ao usuário para definir o tamanho do arranjo
    std::print("Entre o tamanho do arranjo: ");
    std::cin >> tamanho;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Cria um shared_ptr para um arranjo de inteiros
    std::shared_ptr<int16_t[]> ptrArranjo = std::make_shared<int16_t[]>(tamanho);

    // Cria um weak_ptr que observa o shared_ptr
    std::weak_ptr<int16_t[]> prtArranjoFraco = ptrArranjo;

    // Preencher o arranjo com valores inseridos pelo usuário
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::print("Entre o valor para o elemento com indice [{:>3}]: ", i);
        std::cin >> ptrArranjo[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Exibir os valores armazenados no arranjo
    std::println("");
    std::println("Valores no arranjo acessados pelo ponteiro original:");
    std::println("");
    for (size_t i = 0; i < tamanho; ++i) {
        std::println("Elemento [{:>3}]: {:>5}", i, ptrArranjo[i]);
    }

    // Exemplo de um segundo ponteiro compartilhado com o mesmo arranjo
    std::shared_ptr<int16_t[]> outroPtrArranjo = ptrArranjo;

    // Verificar se o weak_ptr ainda é válido antes de usar
    std::shared_ptr<int16_t[]> compartilhadoParaFraco = prtArranjoFraco.lock();
    if (compartilhadoParaFraco) {
        std::println("");
        std::println("Valores no arranjo acessados pelo weak_ptr:");
        std::println("");
        for (size_t i = 0; i < tamanho; ++i) {
            std::println("Elemento [{:>3}]: {:>5}", i, compartilhadoParaFraco[i]);
        }
    } else {
        std::println("O ponteiro fraco nao e mais valido.");
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
