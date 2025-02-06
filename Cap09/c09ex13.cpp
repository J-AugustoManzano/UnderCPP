// c09ex13.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <filesystem>

int main(void) {
    std::filesystem::path caminho_arquivo = "arqbin4.dat";

    // Verifica se o arquivo existe
    if (not std::filesystem::exists(caminho_arquivo)) {
        std::cerr << "Aviso: O arquivo " << caminho_arquivo << " nao existe.\n";
        std::cerr << "Criando o arquivo...\n";

        // Cria o arquivo vazio
        std::fstream arquivo(caminho_arquivo, std::ios::binary | std::ios::out);
        if (not arquivo) {
            std::cerr << "Erro: Nao foi possivel criar o arquivo \""
                << caminho_arquivo << "\".\n";
            return 1;
        }

        std::println("Arquivo \"{}\" criado com sucesso.", caminho_arquivo.string());
        arquivo.close();
    }

    // Verifica se é um arquivo regular
    if (not std::filesystem::is_regular_file(caminho_arquivo)) {
        std::cerr << "Erro: \"" << caminho_arquivo << "\" nao e um arquivo regular.\n";
        return 1;
    }

    // Abre o arquivo para leitura e escrita em modo binário
    std::fstream arquivo(caminho_arquivo, std::ios::binary | std::ios::in
                                                           | std::ios::out);
    if (not arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo \""
            << caminho_arquivo << "\".\n";
        return 1;
    }

    // Processa os dados do arquivo
    int64_t valor;
    while (arquivo.read(reinterpret_cast<char*>(&valor), sizeof(valor))) {
        std::println("Valor lido: {}", valor);
    }

    // Verifica o estado do fluxo após a leitura
    if (arquivo.eof()) {
        std::println("Fim do arquivo alcancado.");
    } else if (arquivo.bad()) {
        std::cerr << "Erro: Falha grave ao acessar o arquivo \""
            << caminho_arquivo << "\".\n";
    } else if (arquivo.fail()) {
        std::cerr << "Erro: Falha na leitura dos dados do arquivo.\n";
    }

    // Fecha o arquivo
    arquivo.close();

    // Finaliza o programa
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
