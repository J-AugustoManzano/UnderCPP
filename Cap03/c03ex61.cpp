// c03ex61.cpp

#include <iostream>
#include <print>
#include <cstdlib>

int16_t* criarArranjo(int16_t tamanho) {
    int16_t* arranjo = new int16_t[tamanho];
    if (arranjo == nullptr) {
        std::println("Erro de alocacao de memoria");
        exit(1);
    }
    return arranjo;
}

int main(void) {
    int16_t tamanho = 5;
    int16_t* meuArranjo = criarArranjo(tamanho);

    for (size_t i = 0; i < tamanho; ++i) {
        meuArranjo[i] = i * 2;
        std::println("{}", meuArranjo[i]);
    }

    delete[] meuArranjo;

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
