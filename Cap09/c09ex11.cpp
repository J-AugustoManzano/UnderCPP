// c09ex11.cpp

#include <iostream>
#include <print>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <filesystem>
#include <cctype>

void pausa(void) {
    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();
}

int main(void) {
    uint8_t num;
    char resp{'S'};

    try {
        // Verificação com std::filesystem
        if (std::filesystem::exists("arqbin3.dat") and
            not std::filesystem::is_regular_file("arqbin3.dat")) {
            throw std::runtime_error("\"arqbin3.dat\" nao e um arquivo \"regular\".");
        }

        std::fstream arqbin("arqbin3.dat", std::ios::binary
            | std::ios::in
            | std::ios::out
            | std::ios::app);
        if (not arqbin.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo.");
        }

        std::println("Entrada de valores\n");

        do {
            std::print("Entre um numero inteiro (0 a 255): ");
            uint16_t temp; // Variável temporária para verificar o intervalo

            std::cin >> temp;
            if (std::cin.fail() or temp < 0 or temp > 255) {
                std::cerr << "Entrada invalida. Informe um numero inteiro entre 0 e 255.";
                std::println("");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            num = static_cast<uint8_t>(temp); // Garantir conversão para uint8_t

            arqbin.write(reinterpret_cast<char*>(&num), sizeof(num));
            if (not arqbin) {
                throw std::runtime_error("Erro ao gravar no arquivo.");
            }

            arqbin.flush(); // Garante gravação imediata

            std::println("Deseja continuar?");
            std::print("Tecle [S] p/ SIM | outra letra p/ NAO: ");
            std::cin >> resp;
            std::cin.ignore();
            std::println("");
        } while (toupper(resp) == 'S');

        arqbin.clear();
        arqbin.seekg(0, std::ios::beg); // Coloca ponteiro no início do arquivo

        std::println("Valores no arquivo:\n");
        while (true) {
            arqbin.read(reinterpret_cast<char*>(&num), sizeof(num));
            if (arqbin.gcount() == 0) break;
            // Converte para int16_t para poder exibir o valor
            std::print("{:>4}", static_cast<int16_t>(num));
        }
        std::println("");

        arqbin.close();

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    pausa();
    return 0;
}
