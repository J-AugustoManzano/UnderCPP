// c09ex02.cpp

#include <iostream>
#include <print>
#include <string>
#include <fstream>

int main(void) {
    std::fstream arqtxt;
    std::string texto;

    // Abre o arquivo em modo de escrita com acr�scimos
    arqtxt.open("arqtxt.tex", std::ios::app);

    std::print("Entre uma palavra ou frase: ");
    std::getline(std::cin, texto);

    // Escreve o texto no arquivo com salto de linha
    arqtxt << texto << std::endl;

    // Descarrega o buffer de sa�da, garante que todo cone�do seja gravado
    arqtxt.flush();

    // Fecha o arquivo ap�s escrita
    arqtxt.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
