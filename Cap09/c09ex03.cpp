// c09ex03.cpp

#include <iostream>
#include <print>
#include <string>
#include <fstream>

int main(void) {
    std::fstream arqtxt;
    std::string linha;

    // Abre o arquivo em modo de leitura
    arqtxt.open("arqtxt.tex", std::ios::in);

    std::println("Conteudo do arquivo \"arqtxt.tex\":\n");

    // Lê cada linha do arquivo e exibe na tela
    while (std::getline(arqtxt, linha)) {
        std::println("{}", linha);
    }

    // Fecha o arquivo após a leitura
    arqtxt.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
