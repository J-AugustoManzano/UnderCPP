// c09ex09.cpp

#include <iostream>
#include <limits>
#include <print>
#include <fstream>

int main(void) {
    // Definir um arranjo de 10 inteiros
    int16_t valores[10];

    // Solicitar ao usuário que insira os 10 valores inteiros
    std::println("Entre 10 valores inteiros:\n");
    for (size_t i = 0; i <= 9; ++i) {
        std::print("Valor {:>2}: ", (i + 1));
        std::cin >> valores[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Abrir um arquivo binário para escrita
    std::fstream arquivo("arqbin2.dat", std::ios::out | std::ios::binary);

    // Gravar os dados no arquivo binário
    arquivo.write(reinterpret_cast<char*>(valores), sizeof(valores));

    // Fechar o arquivo
    arquivo.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
