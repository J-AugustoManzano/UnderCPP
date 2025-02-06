// c09ex01.cpp

#include <iostream>
#include <print>
#include <fstream>

int main(void) {
    std::fstream arqtxt;

    // Cria arquivo texto deixando-o pronto para escrita
    arqtxt.open("arqtxt.tex", std::ios::out);
    std::println("Arquivo \"arqtxt.tex\" criado com sucesso.");

    // Fecha o arquivo após sua criação
    arqtxt.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
