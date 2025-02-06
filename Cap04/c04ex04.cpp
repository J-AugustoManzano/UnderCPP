// c04ex04.cpp

#include <iostream>
#include <print>
#include <string>

int main(void) {
    std::string frase = "Estudo de programacao com C++23!";

    // Frase original
    std::println("Frase original ........................: {}", frase);

    // Obtendo o comprimento da string
    std::println("Tamanho em caracteres (size) ..........: {}", frase.size());
    std::println("Tamanho em caracteres (length) ........: {}", frase.length());

    // Extraindo uma substring
    std::string palavra = frase.substr(10, 11);
    std::println("Sub cadeia extraida ...................: {}", palavra);

    // Procurando uma palavra na string
    size_t pos = frase.find("programacao");
    if (pos != std::string::npos) {
        std::println("Palavra '{}' esta na posicao .: {}", palavra, pos);
    }

    // Substituindo parte da string
    frase.replace(22, 3, "sem");
    std::println("Frase modificada ......................: {}", frase);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
