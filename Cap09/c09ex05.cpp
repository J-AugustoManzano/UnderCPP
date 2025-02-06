// c09ex05.cpp

#include <iostream>
#include <print>
#include <fstream>

int main(void) {
    std::fstream arqbin;

    // Cria o arquivo binário deixando-o pronto para escrita
    arqbin.open("arqbin1.dat", std::ios::out | std::ios::binary);
    std::println("Arquivo \"arqbin1.dat\" criado com sucesso.");

    // Fecha o arquivo após sua criação
    arqbin.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
