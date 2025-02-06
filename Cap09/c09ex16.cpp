// c09ex16.cpp

#include <iostream>
#include <print>
#include <limits>
#include <cctype>
#include <fstream>

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

int main(void) {
    int32_t valor;
    uint64_t pos;
    char* conteudo = reinterpret_cast<char*>(&valor);
    size_t tamanho = sizeof(valor);
    uint64_t tamanhoArquivo, tamanhoRegistro, nrRegs;
    char resp;
    std::fstream arqbin;

    arqbin.open("arqbin5.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (not arqbin) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        pausa();
        return 1;
    }

    arqbin.seekg(0, std::ios::end);
    tamanhoArquivo = arqbin.tellg();
    tamanhoRegistro = sizeof(valor);
    nrRegs = tamanhoArquivo / tamanhoRegistro;

    std::println("PESQUISA E ALTERACAO DIRETA DE VALORES");
    std::println("--------------------------------------");
    std::println("");

    if (nrRegs == 0) {
        std::println("O arquivo esta vazio.");
        pausa();
        return 1;
    } else {
        std::print("O arquivo possui {} registro{}.", nrRegs, (nrRegs == 1) ? "" : "s");
        std::println("");
    }

    do {
        std::println("");
        std::print("Entre a posicao a ser pesquisada: ");
        std::cin >> pos;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("");

        if (pos >= 1 and pos <= nrRegs) {
            arqbin.seekg((pos - 1) * tamanho, std::ios::beg);
            arqbin.read(conteudo, tamanho);
            std::print("Valor {} na posicao {}", valor, pos);
            std::println("");

            std::println("");
            std::print("Entre o novo valor: ");
            std::cin >> valor;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::println("");

            arqbin.seekp((pos - 1) * tamanho, std::ios::beg);
            arqbin.write(conteudo, tamanho);
            std::print("Novo valor {} gravado na posicao {}", valor, pos);
            std::println("");
        } else {
            std::cerr << "Posicao informada - invalida." << std::endl;
        }

        std::println("");
        std::println("Deseja continuar?");
        std::print("[S] Sim \n[qualquer letra] Nao\n\n--> ");
        std::cin.get(resp);
        std::cin.ignore();
    } while (toupper(resp) == 'S');

    arqbin.close();

    pausa();
    return 0;
}
