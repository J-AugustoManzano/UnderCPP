// c09ex06.cpp

#include <iostream>
#include <print>
#include <limits>
#include <fstream>

int main(void) {
    std::fstream arqbin;
    double valor;

    // Abre o arquivo binário em modo de escrita com acréscimos
    arqbin.open("arqbin1.dat", std::ios::out | std::ios::binary | std::ios::app);

    std::print("Entre um valor numerico: ");
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Escreve o valor no arquivo binário
    arqbin.write(reinterpret_cast<const char*>(&valor), sizeof(valor));

    // Descarrega o buffer de saída para o arquivo
    arqbin.flush();

    // Fecha o arquivo após escrita
    arqbin.close();

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
