// c02ex64.cpp

#include <iostream>
#include <print>
#include <cctype>

int main(void) {
    int16_t i;
    std::string entrada;
    bool ehAlfanumerico;

    do {
        std::print("Entre com um texto (com numeros): ");
        std::getline(std::cin, entrada);

        ehAlfanumerico = true;

        // Verifica se a entrada contém apenas letras
        i = 0;
        while (i < entrada.length()) {
            if (not std::isalnum(entrada[i]) and not std::isspace(entrada[i])) {
                ehAlfanumerico = false;
                break;
            }
            ++i;
        }

        if (not ehAlfanumerico) {
            std::println("Entrada invalida. Por favor, entre apenas texto (sem numeros).");
            std::println("");
        }

    } while (not ehAlfanumerico);

    std::println("");
    std::println("Texto informado = {}", entrada);

    std::println("");
    std::print("Tecle <Enter> para encerrar... ");
    std::cin.get();

    return 0;
}
