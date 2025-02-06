// c09ex08.cpp

#include <iostream>
#include <print>
#include <fstream>
#include <string>
#include <filesystem>

void menu(void) {
    std::println("Cadastro com arquivo binario - v. 1.0");
    std::println("");
    std::println("Menu Principal:");
    std::println("");
    std::println("1 - Criar arquivo");
    std::println("2 - Abrir arquivo");
    std::println("3 - Escrevar arquivo");
    std::println("4 - Ler arquivo");
    std::println("5 - Sair do programa");
    std::println("");
    std::print("Escolha uma opcao: ");
}

bool arquivo_existe(const std::string& nome_arquivo) {
    return std::filesystem::exists(nome_arquivo);
}

void exibir_conteudo_arquivo(const std::string& nome_arquivo) {
    std::fstream arquivo(nome_arquivo, std::ios::in | std::ios::binary);
    if (arquivo) {
        std::println("Conteudo atual do arquivo binario \"{}\":\n", nome_arquivo);
        double valor;
        arquivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
        while (arquivo) {
            std::println("Valor: {}", valor);
            arquivo.read(reinterpret_cast<char*>(&valor), sizeof(valor));
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
                arquivo.open(nome_arquivo, std::ios::out | std::ios::binary);
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
                std::println("O arquivo \"{}\" nao existe. ", nome_arquivo);
                std::println("Use a opcao 1 para cria-lo.");
            } else {
                std::println("Arquivo \"{}\" aberto para operacoes.", nome_arquivo);
                arquivo_selecionado = true;
            }
            std::println("");
            break;
        }

        case 3: { // Adicionar valor numerico
            if (not arquivo_selecionado) {
                std::println("Nenhum arquivo foi selecionado. Use as opcoes 1 ou 2 primeiro.");
            } else {
                // Exibe o conteúdo atual do arquivo antes de adicionar novos valores
                if (arquivo_existe(nome_arquivo)) {
                    exibir_conteudo_arquivo(nome_arquivo);
                }

                arquivo.open(nome_arquivo, std::ios::app | std::ios::binary);
                if (not arquivo) {
                    std::println("Erro ao abrir o arquivo para gravacao.");
                } else {
                    std::println("");
                    std::print("Entre um valor numerico: ");
                    double valor;
                    std::cin >> valor;
                    arquivo.write(reinterpret_cast<const char*>(&valor), sizeof(valor));
                    std::println("Valor gravado com sucesso.");
                    arquivo.close();
                }
            }
            std::println("");
            break;
        }

        case 4: { // Ler arquivo binario
            if (not arquivo_selecionado) {
                std::println("Nenhum arquivo foi selecionado. Use as opcoes 1 ou 2 primeiro.");
            } else if (not arquivo_existe(nome_arquivo)) {
                std::print("O arquivo \"{}\" nao existe. ", nome_arquivo);
                std::println("Use a opcao 1 para cria-lo.");
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
