// c0Xex07.cpp

#include <iostream>
#include <print>
#include <vector>

std::vector<uint8_t> compress(const std::string& conteudo) {
    std::vector<uint8_t> comprimido;
    char caractereAtual = conteudo[0];
    uint8_t contar = 0;

    for (char c : conteudo) {
        if (c == caractereAtual && contar < 255) {
            contar++;
        } else {
            comprimido.push_back(caractereAtual); // Armazena o caractere
            comprimido.push_back(contar);  // Armazena a contagem
            caractereAtual = c;
            contar = 1;
        }
    }
    comprimido.push_back(caractereAtual);
    comprimido.push_back(contar);

    return comprimido;
}

std::string decompress(const std::vector<uint8_t>& comprimido) {
    std::string decomprimido;

    for (size_t i = 0; i < comprimido.size(); i += 2) {
        char caractere = comprimido[i];
        uint8_t contar = comprimido[i + 1];
        decomprimido.append(contar, caractere);
    }

    return decomprimido;
}

int main(void) {
    std::string dados = "aaabbbbccddddee";
    auto dadoComprimido = compress(dados);

    std::println("Dados originais: {}", dados);
    std::println("");

    std::cout << "Dados comprimidos: ";
    for (auto byte : dadoComprimido) {
        //std::cout << std::bitset<8>(byte) << " ";
        std::print("{:08b} ", byte);
    }
    std::println("\n");

    auto dedadoComprimido = decompress(dadoComprimido);
    std::println("Dados descomprimidos: {}", dedadoComprimido);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
