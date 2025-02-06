// c09ex07.cpp

#include <iostream>
#include <print>
#include <fstream>

int main(void) {
    std::fstream arqbin;
    double valor;

    // Abre o arquivo binário em modo de leitura
    arqbin.open("arqbin1.dat", std::ios::in | std::ios::binary);

    std::println("Conteudo do arquivo \"arqbin1.dat\":\n");

    // Lê os valores armazenados no arquivo e exibe na tela
    while (arqbin.read(reinterpret_cast<char*>(&valor), sizeof(double))) {
        std::println("{}", valor);
    }

    // Fecha o arquivo após a leitura
    arqbin.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
