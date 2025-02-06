// c09ex12.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <filesystem>

int main(void) {
    // Tenta abrir o arquivo diretamente
    std::fstream arquivo("arqbin4.dat", std::ios::binary | std::ios::in);

    if (arquivo.fail()) {
        std::println("Falha ao abrir o arquivo.");

        // Verificação adicional: arquivo não existe ou não é regular
        if (not std::filesystem::exists("arqbin4.dat")) {
            std::println("O arquivo nao existe.");
        } else if (not std::filesystem::is_regular_file("arqbin4.dat")) {
            std::println("O arquivo nao e um arquivo regular.");
        }
    } else {
        std::println("Arquivo aberto com sucesso.");
        arquivo.close();
    }

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
