// c09ex18.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <vector>

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

int main(void) {
    uint64_t tamanho;
    char* numeroCaracteres = reinterpret_cast<char*>(&tamanho);
    std::fstream arqbin("arqbin6.dat", std::ios::binary | std::ios::in);

    if (not arqbin) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        pausa();
        return 1;
    }

    std::println("Conteudo do arquivo:\n");

    while (arqbin.read(numeroCaracteres, sizeof(tamanho))) {
        std::vector<char> mensagem(tamanho);
        if (arqbin.read(mensagem.data(), tamanho)) {
            // Garante que a mensagem seja uma string válida
            mensagem.push_back('\0');  // Adiciona o terminador nulo
            std::println("{}", mensagem.data());
        } else {
            std::cerr << "Erro de leitura. Arquivo pode estar corrompido." << std::endl;
            break;
        }
    }

    arqbin.close();
    pausa();
    return 0;
}
