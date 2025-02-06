// c09ex10.cpp

#include <iostream>
#include <print>
#include <fstream>

int main(void) {
    // Definir um arranjo de 10 inteiros para armazenar os valores lidos
    int16_t valores[10];

    // Abrir o arquivo binário para leitura
    std::fstream arquivo("arqbin2.dat", std::ios::in | std::ios::binary);

    // Ler os dados do arquivo binário
    arquivo.read(reinterpret_cast<char*>(valores), sizeof(valores));

    // Exibir os valores lidos
    std::println("Valores lidos do arquivo binario:/n");
    for (size_t i = 0; i <= 9; ++i) {
        std::println("Valor {:>2}: {}", (i + 1), valores[i]);
    }

    // Fechar o arquivo
    arquivo.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
