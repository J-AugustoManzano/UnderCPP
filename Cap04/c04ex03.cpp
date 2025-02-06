// c04ex03.cpp

#include <iostream>
#include <print>
#include <string>

int main(void) {
    std::string palavra = "Programacao";
    char letra;

    std::println("Palavra original ..: {}", palavra);

    // Acessando e alterando um caractere
    palavra[0] = 'p';
    std::println("Palavra alterada ..: {}", palavra);

    // Exibindo cada caractere da string
    std::print("Palavra separada ..: ");
    for (size_t i = 0; i < palavra.size(); ++i) {
        letra = palavra[i];
        std::print("{} ", letra);
    }
    std::println("");

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
