// c09ex14.cpp

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
    char* conteudo = reinterpret_cast<char*>(&valor);
    constexpr size_t tamanho = sizeof(valor);
    char resp;
    std::fstream arqbin;

    arqbin.open("arqbin5.dat", std::ios::app | std::ios::binary);
    if (not arqbin) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        pausa();
        return 1;
    }

    std::println("CADASTRO SEQUENCIAL DE VALORES");
    std::println("------------------------------");

    do {
        std::println("");
        std::print("Entre um valor: ");
        std::cin >> valor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        arqbin.write(conteudo, tamanho);
        std::println("");
        std::println("Deseja continuar?");
        std::print("[S] Sim \n[qualquer letra] Nao\n\n--> ");
        std::cin.get(resp);
        std::cin.ignore();
    } while (toupper(resp) == 'S');

    arqbin.close();
    std::println("\nCadastro finalizado.");
    pausa();

    return 0;
}
