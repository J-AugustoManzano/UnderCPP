// c09ex04cpp

#include <iostream>
#include <print>
#include <fstream>
#include <string>
#include <filesystem>

void menu(void) {
    std::println("Editor de texto simples - v. 1.0");
    std::println("");
    std::println("Menu Principal:");
    std::println("");
    std::println("1 - Criar arquivo");
    std::println("2 - Abrir arquivo");
    std::println("3 - Escrever arquivo");
    std::println("4 - Ler arquivo");
    std::println("5 - Sair do programa");
    std::println("");
    std::print("Escolha uma opcao: ");
}

bool arquivo_existe(const std::string& nome_arquivo) {
    return std::filesystem::exists(nome_arquivo);
}

void exibir_conteudo_arquivo(const std::string& nome_arquivo) {
    std::fstream arquivo(nome_arquivo, std::ios::in);
    if (arquivo) {
        std::println("Conteudo atual do arquivo \"{}\":\n", nome_arquivo);
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::println("{}", linha);
        }
        arquivo.close();
    } else {
        std::println("Erro ao abrir o arquivo para leitura.");
    }
}

int main(void) {
    std::fstream arquivo;
    std::string nome_arquivo;
    int opcao = 0;
    bool arquivo_selecionado = false;

    while (opcao != 5) {
        menu();
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer do teclado
        std::println("");

        switch (opcao) {
        case 1: { // Criar arquivo
            std::print("Informe o nome do arquivo: ");
            std::getline(std::cin, nome_arquivo);

            if (arquivo_existe(nome_arquivo)) {
                std::println("O arquivo \"{}\" ja existe, nao pode ser recriado.", nome_arquivo);
            } else {
                arquivo.open(nome_arquivo, std::ios::out);
                if (not arquivo) {
                    std::println("Erro ao criar o arquivo.");
                } else {
                    std::println("Arquivo \"{}\" criado com sucesso.", nome_arquivo);
                    arquivo_selecionado = true;
                    arquivo.close();
                }
            }
            std::println("");
            break;
        }

        case 2: { // Abrir arquivo existente
            std::print("Informe o nome do arquivo a ser aberto: ");
            std::getline(std::cin, nome_arquivo);

            if (not arquivo_existe(nome_arquivo)) {
                std::print("O arquivo \"{}\" nao existe. ", nome_arquivo);
                std::println("Use a opcao 1 para cria-lo.");
            } else {
                std::println("Arquivo \"{}\" aberto para operacoes.", nome_arquivo);
                arquivo_selecionado = true;
            }
            std::println("");
            break;
        }

        case 3: { // Gravar no arquivo
            if (not arquivo_selecionado) {
                std::println("Nenhum arquivo foi selecionado. Use as opcoes 1 ou 2 primeiro.");
            } else {
                if (arquivo_existe(nome_arquivo)) {
                    exibir_conteudo_arquivo(nome_arquivo);
                }
                arquivo.open(nome_arquivo, std::ios::app);
                if (not arquivo) {
                    std::println("Erro ao abrir o arquivo para gravacao.");
                } else {
                    std::println("\nEscreva o texto.");
                    std::println("Pressione Ctrl+X (e Enter) para encerrar a escrita:\n");
                    std::string linha;
                    while (true) {
                        std::getline(std::cin, linha);
                        if (linha == "\x18") // Ctrl+X em ASCII
                            break;
                        arquivo << linha << std::endl;
                    }
                    std::println("Texto gravado com sucesso.");
                    arquivo.close();
                }
            }
            std::println("");
            break;
        }

        case 4: { // Ler arquivo
            if (not arquivo_selecionado) {
                std::println("Nenhum arquivo foi selecionado. Use as opcoes 1 ou 2 primeiro.");
            } else if (not arquivo_existe(nome_arquivo)) {
                std::print("O arquivo \"{}\"", nome_arquivo);
                std::println("nao existe. Use a opcao 1 para cria-lo.");
            } else {
                exibir_conteudo_arquivo(nome_arquivo);
            }
            std::println("");
            break;
        }

        case 5:
            std::println("Encerrando o programa...");
            std::println("");
            break;

        default:
            std::println("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
